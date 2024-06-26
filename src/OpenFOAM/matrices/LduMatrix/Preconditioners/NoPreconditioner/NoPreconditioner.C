/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2018 OpenFOAM Foundation
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

#include "matrices/LduMatrix/Preconditioners/NoPreconditioner/NoPreconditioner.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Type, class DType, class LUType>
Foam::NoPreconditioner<Type, DType, LUType>::NoPreconditioner
(
    const typename LduMatrix<Type, DType, LUType>::solver& sol,
    const dictionary&
)
:
    LduMatrix<Type, DType, LUType>::preconditioner(sol)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Type, class DType, class LUType>
void Foam::NoPreconditioner<Type, DType, LUType>::read(const dictionary&)
{}


template<class Type, class DType, class LUType>
void Foam::NoPreconditioner<Type, DType, LUType>::precondition
(
    Field<Type>& wA,
    const Field<Type>& rA
) const
{
    wA = rA;
}


// ************************************************************************* //
