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

InClass
    Foam::IOstream

Description
    Useful combination of include files which define Sin, Sout and Serr and
    the use of IO streams generally.

\*---------------------------------------------------------------------------*/

#ifndef IOstreams_H
#define IOstreams_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "db/IOstreams/Sstreams/ISstream.H"
#include "db/IOstreams/Sstreams/prefixOSstream.H"
#include "db/IOstreams/token/token.H"
#include "primitives/chars/char/char.H"
#include "primitives/ints/int/int.H"
#include "primitives/ints/uint/uint.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// Global predefined streams for standard input, output

namespace Foam
{
    extern ISstream Sin;
    extern prefixOSstream Sout;
    extern OSstream Serr;
    extern prefixOSstream Pout;
    extern prefixOSstream Perr;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
