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

#include "interpolation/surfaceInterpolation/multivariateSchemes/multivariateSelectionScheme/multivariateSelectionScheme.H"
#include "interpolation/surfaceInterpolation/limitedSchemes/limitedSurfaceInterpolationScheme/limitedSurfaceInterpolationScheme.H"
#include "fields/volFields/volFields.H"
#include "fields/surfaceFields/surfaceFields.H"
#include "interpolation/surfaceInterpolation/limitedSchemes/upwind/upwind.H"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

template<class Type>
Foam::multivariateSelectionScheme<Type>::multivariateSelectionScheme
(
    const fvMesh& mesh,
    const typename multivariateSurfaceInterpolationScheme<Type>::
        fieldTable& fields,
    const surfaceScalarField& faceFlux,
    Istream& schemeData
)
:
    multivariateSurfaceInterpolationScheme<Type>
    (
        mesh,
        fields,
        faceFlux,
        schemeData
    ),
    schemes_(schemeData),
    faceFlux_(faceFlux),
    weights_
    (
        IOobject
        (
            "multivariateWeights",
            mesh.time().name(),
            mesh
        ),
        mesh,
        dimless
    )
{
    typename multivariateSurfaceInterpolationScheme<Type>::
        fieldTable::const_iterator iter = this->fields().begin();

    surfaceScalarField limiter
    (
        limitedSurfaceInterpolationScheme<Type>::New
        (
            mesh,
            faceFlux_,
            schemes_.lookup(iter()->name())
        )().limiter(*iter())
    );

    for (++iter; iter != this->fields().end(); ++iter)
    {
        limiter = min
        (
            limiter,
            limitedSurfaceInterpolationScheme<Type>::New
            (
                mesh,
                faceFlux_,
                schemes_.lookup(iter()->name())
            )().limiter(*iter())
        );
    }

    weights_ =
        limiter*mesh.surfaceInterpolation::weights()
      + (scalar(1) - limiter)*upwind<Type>(mesh, faceFlux_).weights();
}


// ************************************************************************* //
