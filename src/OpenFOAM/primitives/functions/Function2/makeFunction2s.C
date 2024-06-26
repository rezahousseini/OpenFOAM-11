/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2020-2023 OpenFOAM Foundation
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

#include "primitives/functions/Function2/None/None2.H"
#include "primitives/functions/Function2/Constant/Constant2.H"
#include "primitives/functions/Function2/Zero/ZeroConstant2.H"
#include "primitives/functions/Function2/One/OneConstant2.H"
#include "primitives/functions/Function2/Scale/Scale2.H"
#include "primitives/functions/Function2/UniformTable2/UniformTable2.H"
#include "primitives/functions/Function2/Coded/CodedFunction2.H"

#include "fields/Fields/fieldTypes.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define makeFunction2s(Type, nullArg)                                          \
                                                                               \
    makeFunction2(Type);                                                       \
                                                                               \
    namespace Function2s                                                       \
    {                                                                          \
        makeFunction2Type(None, Type);                                         \
        makeFunction2Type(Constant, Type);                                     \
        makeFunction2Type(ZeroConstant, Type);                                 \
        makeFunction2Type(OneConstant, Type);                                  \
        makeFunction2Type(Scale, Type);                                        \
        makeFunction2Type(UniformTable, Type);                                 \
        makeFunction2Type(Coded, Type);                                        \
    }

namespace Foam
{
    makeFunction2(label);

    namespace Function2s
    {
        makeFunction2Type(None, label);
        makeFunction2Type(Constant, label);
    }

    FOR_ALL_FIELD_TYPES(makeFunction2s);
}


// ************************************************************************* //
