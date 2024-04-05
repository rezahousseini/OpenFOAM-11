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

\*---------------------------------------------------------------------------*/

#include "motionSolvers/displacement/solidBody/solidBodyMotionFunctions/sixDoFMotion/sixDoFMotion.H"
#include "global/constants/mathematical/mathematicalConstants.H"
#include "db/runTimeSelection/construction/addToRunTimeSelectionTable.H"

using namespace Foam::constant::mathematical;

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace solidBodyMotionFunctions
{
    defineTypeNameAndDebug(sixDoFMotion, 0);
    addToRunTimeSelectionTable
    (
        solidBodyMotionFunction,
        sixDoFMotion,
        dictionary
    );
}
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "primitives/functions/Function1/None/None.H"
#include "primitives/functions/Function1/Constant/Constant.H"
#include "primitives/functions/Function1/Uniform/Uniform.H"
#include "primitives/functions/Function1/Zero/ZeroConstant.H"
#include "primitives/functions/Function1/One/OneConstant.H"
#include "primitives/functions/Function1/Polynomial1/Polynomial1.H"
#include "primitives/functions/Function1/Sine/Sine.H"
#include "primitives/functions/Function1/Square/Square.H"
#include "primitives/functions/Function1/Table/Table.H"
#include "primitives/functions/Function1/UniformTable1/UniformTable1.H"
#include "primitives/functions/Function1/NonUniformTable1/NonUniformTable1.H"
#include "primitives/functions/Function1/Table/TableReader/Embedded/EmbeddedTableReader.H"
#include "primitives/functions/Function1/Table/TableReader/Foam/FoamTableReader.H"
#include "primitives/functions/Function1/Scale/Scale.H"
#include "primitives/functions/Function1/Coded/CodedFunction1.H"

typedef Foam::solidBodyMotionFunctions::sixDoFMotion::translationRotationVectors
trvType;

template<>
const char* const trvType::vsType::typeName = "vector2Vector";

template<>
const char* const trvType::vsType::componentNames[] = {"x", "y"};

template<>
const trvType trvType::vsType::vsType::zero
(
    trvType::uniform(vector::uniform(0))
);

template<>
const trvType trvType::vsType::one(trvType::uniform(vector::uniform(1)));

template<>
const trvType trvType::vsType::max(trvType::uniform(vector::uniform(vGreat)));

template<>
const trvType trvType::vsType::min(trvType::uniform(vector::uniform(-vGreat)));

template<>
const trvType trvType::vsType::rootMax
(
    trvType::uniform(vector::uniform(rootVGreat))
);

template<>
const trvType trvType::vsType::rootMin
(
    trvType::uniform(vector::uniform(-rootVGreat))
);

namespace Foam
{
    makeFunction1s(trvType, nullArg);

    defineTableReader(trvType);
    namespace TableReaders
    {
        makeTableReader(Embedded, trvType);
        makeTableReader(Foam, trvType);
    }
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::solidBodyMotionFunctions::sixDoFMotion::sixDoFMotion
(
    const dictionary& SBMFCoeffs,
    const Time& runTime
)
:
    solidBodyMotionFunction(SBMFCoeffs, runTime)
{
    read(SBMFCoeffs);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::solidBodyMotionFunctions::sixDoFMotion::~sixDoFMotion()
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

Foam::septernion
Foam::solidBodyMotionFunctions::sixDoFMotion::transformation() const
{
    const scalar t = time_.value();

    translationRotationVectors TRV = translationRotation_->value(t);

    // Convert the rotational motion from deg to rad
    TRV[1] *= pi/180.0;

    quaternion R(quaternion::XYZ, TRV[1]);
    septernion TR(septernion(-CofG_ + -TRV[0])*R*septernion(CofG_));

    DebugInFunction << "Time = " << t << " transformation: " << TR << endl;

    return TR;
}


bool Foam::solidBodyMotionFunctions::sixDoFMotion::read
(
    const dictionary& SBMFCoeffs
)
{
    solidBodyMotionFunction::read(SBMFCoeffs);

    translationRotation_ = Function1<translationRotationVectors>::New
    (
        "translationRotation",
        SBMFCoeffs_
    );

    SBMFCoeffs_.lookup("CofG") >> CofG_;

    return true;
}


// ************************************************************************* //
