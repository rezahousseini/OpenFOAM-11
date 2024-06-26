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

Description
    Prints out a description of the StringStream

\*---------------------------------------------------------------------------*/

#include "db/IOstreams/StringStreams/IStringStream.H"
#include "db/IOstreams/StringStreams/OStringStream.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

void Foam::IStringStream::print(Ostream& os) const
{
    os  << "IStringStream " << name() << " : "
        << "buffer = \n" << str() << Foam::endl;

    ISstream::print(os);
}


void Foam::OStringStream::print(Ostream& os) const
{
    os  << "OStringStream " << name() << " : "
        << "buffer = \n" << str() << Foam::endl;

    OSstream::print(os);
}


// ************************************************************************* //
