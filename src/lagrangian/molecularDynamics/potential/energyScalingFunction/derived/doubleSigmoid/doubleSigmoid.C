/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2019 OpenFOAM Foundation
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

#include "energyScalingFunction/derived/doubleSigmoid/doubleSigmoid.H"
#include "db/runTimeSelection/construction/addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace energyScalingFunctions
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(doubleSigmoid, 0);

addToRunTimeSelectionTable
(
    energyScalingFunction,
    doubleSigmoid,
    dictionary
);

// * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * * //

scalar doubleSigmoid::sigmoidScale
    (
        const scalar r,
        const scalar shift,
        const scalar scale
    ) const
{
    return 1.0 / (1.0 + exp( scale * (r - shift)));
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

doubleSigmoid::doubleSigmoid
(
    const word& name,
    const dictionary& energyScalingFunctionProperties,
    const pairPotential& pairPot
)
:
    energyScalingFunction(name, energyScalingFunctionProperties, pairPot),
    doubleSigmoidCoeffs_
    (
        energyScalingFunctionProperties.subDict(typeName + "Coeffs")
    ),
    shift1_(doubleSigmoidCoeffs_.template lookup<scalar>("shift1")),
    scale1_(doubleSigmoidCoeffs_.template lookup<scalar>("scale1")),
    shift2_(doubleSigmoidCoeffs_.template lookup<scalar>("shift2")),
    scale2_(doubleSigmoidCoeffs_.template lookup<scalar>("scale2"))
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

void doubleSigmoid::scaleEnergy(scalar& e, const scalar r) const
{
    e *= sigmoidScale(r, shift1_, scale1_) * sigmoidScale(r, shift2_, scale2_);
}


bool doubleSigmoid::read(const dictionary& energyScalingFunctionProperties)
{
    energyScalingFunction::read(energyScalingFunctionProperties);

    doubleSigmoidCoeffs_ =
        energyScalingFunctionProperties.subDict(typeName + "Coeffs");

    doubleSigmoidCoeffs_.lookup("shift1") >> shift1_;
    doubleSigmoidCoeffs_.lookup("scale1") >> scale1_;
    doubleSigmoidCoeffs_.lookup("shift2") >> shift2_;
    doubleSigmoidCoeffs_.lookup("scale2") >> scale2_;

    return true;
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace energyScalingFunctions
} // End namespace Foam

// ************************************************************************* //
