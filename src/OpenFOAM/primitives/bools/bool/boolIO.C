/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2023 OpenFOAM Foundation
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
    Reads an bool from an input stream, for a given version number and file
    format. If an ASCII file is being read, then the line numbers are counted
    and an erroneous read is reported.

\*---------------------------------------------------------------------------*/

#include "db/error/error.H"

#include "primitives/bools/bool/bool.H"
#include "primitives/bools/Switch/Switch.H"
#include "db/IOstreams/IOstreams.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

Foam::word Foam::name(const bool b)
{
    return b ? "true" : "false";
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

Foam::Istream& Foam::operator>>(Istream& is, bool& b)
{
    if (is.good())
    {
        b = Switch(is);
    }

    return is;
}


Foam::Ostream& Foam::operator<<(Ostream& os, const bool b)
{
    os.write(name(b));
    os.check("Ostream& operator<<(Ostream&, const bool)");
    return os;
}


bool Foam::readBool(Istream& is)
{
    bool b;
    is  >> b;

    return b;
}


// ************************************************************************* //
