/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2022 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "fields/volFields/volFields.H"
#include "fields/surfaceFields/surfaceFields.H"
#include "finiteVolume/fvc/fvcGrad.H"
#include "fields/fvPatchFields/basic/coupled/coupledFvPatchFields.H"

// * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * * //

template<class Type, class Limiter, template<class> class LimitFunc>
void Foam::LimitedScheme<Type, Limiter, LimitFunc>::calcLimiter
(
    const VolField<Type>& phi,
    surfaceScalarField& limiterField
) const
{
    const fvMesh& mesh = this->mesh();

    tmp<VolField<typename Limiter::phiType>> tlPhi = LimitFunc<Type>()(phi);
    const VolField<typename Limiter::phiType>& lPhi = tlPhi();

    tmp<VolField<typename Limiter::gradPhiType>> tgradc(fvc::grad(lPhi));
    const VolField<typename Limiter::gradPhiType>& gradc = tgradc();

    const surfaceScalarField& CDweights = mesh.surfaceInterpolation::weights();

    const labelUList& owner = mesh.owner();
    const labelUList& neighbour = mesh.neighbour();

    const vectorField& C = mesh.C();

    scalarField& pLim = limiterField.primitiveFieldRef();

    forAll(pLim, face)
    {
        label own = owner[face];
        label nei = neighbour[face];

        pLim[face] = Limiter::limiter
        (
            CDweights[face],
            this->faceFlux_[face],
            lPhi[own],
            lPhi[nei],
            gradc[own],
            gradc[nei],
            C[nei] - C[own]
        );
    }

    const typename VolField<Type>::Boundary&
        bPhi = phi.boundaryField();

    surfaceScalarField::Boundary& bLim =
        limiterField.boundaryFieldRef();

    forAll(bLim, patchi)
    {
        scalarField& pLim = bLim[patchi];

        if (bPhi[patchi].coupled())
        {
            const scalarField& pCDweights = CDweights.boundaryField()[patchi];
            const scalarField& pFaceFlux =
                this->faceFlux_.boundaryField()[patchi];

            const Field<typename Limiter::phiType> plPhiP
            (
                lPhi.boundaryField()[patchi].patchInternalField()
            );
            const Field<typename Limiter::phiType> plPhiN
            (
                lPhi.boundaryField()[patchi].patchNeighbourField()
            );
            const Field<typename Limiter::gradPhiType> pGradcP
            (
                gradc.boundaryField()[patchi].patchInternalField()
            );
            const Field<typename Limiter::gradPhiType> pGradcN
            (
                gradc.boundaryField()[patchi].patchNeighbourField()
            );

            // Build the d-vectors
            vectorField pd(CDweights.boundaryField()[patchi].patch().delta());

            forAll(pLim, face)
            {
                pLim[face] = Limiter::limiter
                (
                    pCDweights[face],
                    pFaceFlux[face],
                    plPhiP[face],
                    plPhiN[face],
                    pGradcP[face],
                    pGradcN[face],
                    pd[face]
                );
            }
        }
        else
        {
            pLim = 1.0;
        }
    }
}


// * * * * * * * * * * * * Public Member Functions  * * * * * * * * * * * * //

template<class Type, class Limiter, template<class> class LimitFunc>
Foam::tmp<Foam::surfaceScalarField>
Foam::LimitedScheme<Type, Limiter, LimitFunc>::limiter
(
    const VolField<Type>& phi
) const
{
    const fvMesh& mesh = this->mesh();

    const word limiterFieldName(type() + "Limiter(" + phi.name() + ')');

    if (this->mesh().solution().cache("limiter"))
    {
        if (!mesh.foundObject<surfaceScalarField>(limiterFieldName))
        {
            surfaceScalarField* limiterField
            (
                new surfaceScalarField
                (
                    IOobject
                    (
                        limiterFieldName,
                        mesh.time().name(),
                        mesh,
                        IOobject::NO_READ,
                        IOobject::NO_WRITE
                    ),
                    mesh,
                    dimless
                )
            );

            mesh.objectRegistry::store(limiterField);
        }

        surfaceScalarField& limiterField =
            mesh.lookupObjectRef<surfaceScalarField>
            (
                limiterFieldName
            );

        calcLimiter(phi, limiterField);

        return limiterField;
    }
    else
    {
        tmp<surfaceScalarField> tlimiterField
        (
            surfaceScalarField::New
            (
                limiterFieldName,
                mesh,
                dimless
            )
        );

        calcLimiter(phi, tlimiterField.ref());

        return tlimiterField;
    }
}


// ************************************************************************* //
