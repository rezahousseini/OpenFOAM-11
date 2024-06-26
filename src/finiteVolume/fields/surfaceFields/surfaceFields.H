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

InClass
    Foam::surfaceFields

Description
    Foam::surfaceFields

SourceFiles
    surfaceFields.C

\*---------------------------------------------------------------------------*/

#ifndef surfaceFields_H
#define surfaceFields_H

#include "fields/GeometricFields/GeometricField/GeometricFields.H"
#include "surfaceMesh/surfaceMesh.H"
#include "fvMesh/fvMesh.H"
#include "fields/fvsPatchFields/fvsPatchField/fvsPatchFields.H"
#include "fields/surfaceFields/surfaceFieldsFwd.H"
#include "fields/fvsPatchFields/basic/calculated/calculatedFvsPatchFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

//- Check if surfaceField is a flux
//  i.e. an extensive field oriented with the face requiring
//  flipping after mapping.
//  Currently it is assumed that only surfaceScalarFields can be fluxes
template<class Type>
inline bool isFlux(const DimensionedField<Type, surfaceMesh>& df)
{
    return false;
}

//- Check if surfaceScalarField is a flux
//  i.e. an extensive field oriented with the face requiring
//  flipping after mapping.
//  Currently it is assumed that fluxes are either volumetric or mass
template<>
inline bool isFlux<scalar>(const DimensionedField<scalar, surfaceMesh>& df)
{
    return
        df.dimensions() == dimFlux
     || df.dimensions() == dimMassFlux;
}

//- Check if surfaceField is a face velocity or momentum
template<class Type>
inline bool isFaceVelocity(const DimensionedField<Type, surfaceMesh>& df)
{
    return false;
}

//- Check if surfaceVectorField is a face velocity or momentum
template<>
inline bool isFaceVelocity<vector>
(
    const DimensionedField<vector, surfaceMesh>& df
)
{
    return
        df.dimensions() == dimVelocity
     || df.dimensions() == dimDensity*dimVelocity;
}

}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
