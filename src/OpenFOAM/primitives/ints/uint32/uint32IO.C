/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2014-2018 OpenFOAM Foundation
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

#include "primitives/ints/uint32/uint32.H"
#include "db/IOstreams/IOstreams.H"

#include <sstream>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

Foam::word Foam::name(const uint32_t val)
{
    std::ostringstream buf;
    buf << val;
    return buf.str();
}


// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //

Foam::Istream& Foam::operator>>(Istream& is, uint32_t& i)
{
    token t(is);

    if (!t.good())
    {
        is.setBad();
        return is;
    }

    if (t.isLabel())
    {
        i = uint32_t(t.labelToken());
    }
    else
    {
        is.setBad();
        FatalIOErrorInFunction(is)
            << "wrong token type - expected uint32_t, found " << t.info()
            << exit(FatalIOError);

        return is;
    }

    // Check state of Istream
    is.check("Istream& operator>>(Istream&, uint32_t&)");

    return is;
}


uint32_t Foam::readUint32(Istream& is)
{
    uint32_t val;
    is >> val;

    return val;
}


bool Foam::read(const char* buf, uint32_t& s)
{
    char *endptr = nullptr;
    long l = strtol(buf, &endptr, 10);
    s = uint32_t(l);
    return (*endptr == 0);
}


Foam::Ostream& Foam::operator<<(Ostream& os, const uint32_t i)
{
    os.write(label(i));
    os.check("Ostream& operator<<(Ostream&, const uint32_t)");
    return os;
}


// ************************************************************************* //
