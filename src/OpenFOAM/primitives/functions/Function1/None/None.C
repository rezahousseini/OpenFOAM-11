/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2020 OpenFOAM Foundation
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

#include "primitives/functions/Function1/None/None.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Type>
Foam::Function1s::None<Type>::None
(
    const word& name,
    const dictionary& dict
)
:
    FieldFunction1<Type, None<Type>>(name),
    dictName_(dict.name())
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

template<class Type>
Foam::Function1s::None<Type>::~None()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Type>
Type Foam::Function1s::None<Type>::value(const scalar) const
{
    FatalErrorInFunction
        << "Required function " << this->name() << " in " << nl
        << "    " << dictName_ << nl
        << "    is not defined."
        << exit(FatalError);

    return pTraits<Type>::zero;
}


template<class Type>
Type Foam::Function1s::None<Type>::integral(const scalar, const scalar) const
{
    FatalErrorInFunction
        << "Required function " << this->name() << " in " << nl
        << "    " << dictName_ << nl
        << "    is not defined."
        << exit(FatalError);

    return pTraits<Type>::zero;
}


template<class Type>
void Foam::Function1s::None<Type>::write(Ostream& os) const
{}


// ************************************************************************* //
