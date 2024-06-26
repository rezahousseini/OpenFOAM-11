/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2022 OpenFOAM Foundation
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

#include "cutPoly/cutPolyIsoSurface.H"
#include "cutPoly/cutPolyValue.H"

// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

template<class Type>
Foam::tmp<Foam::Field<Type>> Foam::cutPolyIsoSurface::sample
(
    const Field<Type> cPsis
) const
{
    return tmp<Field<Type>>(new Field<Type>(cPsis, faceCells_));
}


template<class Type>
Foam::tmp<Foam::Field<Type>> Foam::cutPolyIsoSurface::interpolate
(
    const Field<Type>& pPsis
) const
{
    tmp<Field<Type>> tValues(new Field<Type>(points_.size()));
    Field<Type>& values = tValues.ref();

    forAll(points_, pointi)
    {
        values[pointi] =
            cutPoly::edgeCutValue
            (
                pointEdges_[pointi],
                pointEdgeLambdas_[pointi],
                pPsis
            );
    }

    return tValues;
}


// ************************************************************************* //
