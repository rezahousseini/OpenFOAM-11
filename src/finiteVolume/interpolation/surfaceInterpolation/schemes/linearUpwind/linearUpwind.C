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

#include "interpolation/surfaceInterpolation/schemes/linearUpwind/linearUpwind.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

template<>
Foam::tmp<Foam::surfaceVectorField>
Foam::linearUpwind<Foam::vector>::correction
(
    const volVectorField& vf
) const
{
    const fvMesh& mesh = this->mesh();

    tmp<surfaceVectorField> tsfCorr
    (
        surfaceVectorField::New
        (
            "linearUpwind::correction(" + vf.name() + ')',
            mesh,
            dimensioned<vector>(vf.name(), vf.dimensions(), Zero)
        )
    );

    surfaceVectorField& sfCorr = tsfCorr.ref();

    const surfaceScalarField& faceFlux = this->faceFlux_;

    const labelList& owner = mesh.owner();
    const labelList& neighbour = mesh.neighbour();

    const volVectorField& C = mesh.C();
    const surfaceVectorField& Cf = mesh.Cf();

    tmp<fv::gradScheme<vector>> gradScheme_
    (
        fv::gradScheme<vector>::New
        (
            mesh,
            mesh.schemes().grad(gradSchemeName_)
        )
    );

    tmp<volTensorField> tgradVf = gradScheme_().grad(vf, gradSchemeName_);
    const volTensorField& gradVf = tgradVf();

    forAll(faceFlux, facei)
    {
        const label celli =
            (faceFlux[facei] > 0) ? owner[facei] : neighbour[facei];
        sfCorr[facei] = (Cf[facei] - C[celli]) & gradVf[celli];
    }


    typename surfaceVectorField::Boundary& bSfCorr = sfCorr.boundaryFieldRef();

    forAll(bSfCorr, patchi)
    {
        fvsPatchVectorField& pSfCorr = bSfCorr[patchi];

        if (pSfCorr.coupled())
        {
            const labelUList& pOwner = mesh.boundary()[patchi].faceCells();
            const vectorField& pCf = Cf.boundaryField()[patchi];
            const scalarField& pFaceFlux = faceFlux.boundaryField()[patchi];

            const tensorField pGradVfNei
            (
                gradVf.boundaryField()[patchi].patchNeighbourField()
            );

            // Build the d-vectors
            vectorField pd(Cf.boundaryField()[patchi].patch().delta());

            forAll(pOwner, facei)
            {
                label own = pOwner[facei];

                if (pFaceFlux[facei] > 0)
                {
                    pSfCorr[facei] = (pCf[facei] - C[own]) & gradVf[own];
                }
                else
                {
                    pSfCorr[facei] =
                        (pCf[facei] - pd[facei] - C[own]) & pGradVfNei[facei];
                }
            }
        }
    }

    return tsfCorr;
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    makelimitedSurfaceInterpolationScheme(linearUpwind)
}

// ************************************************************************* //
