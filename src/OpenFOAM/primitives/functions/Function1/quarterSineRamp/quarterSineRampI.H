/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2017-2020 OpenFOAM Foundation
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

#include "primitives/functions/Function1/quarterSineRamp/quarterSineRamp.H"
#include "global/constants/mathematical/mathematicalConstants.H"

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

inline Foam::scalar Foam::Function1s::quarterSineRamp::value
(
    const scalar t
) const
{
    return sin(constant::mathematical::piByTwo*linearRamp(t));
}


inline Foam::scalar Foam::Function1s::quarterSineRamp::integral
(
    const scalar t1,
    const scalar t2
) const
{
    using namespace constant::mathematical;

    const scalar l1 = linearRamp(t1), l2 = linearRamp(t2);

    return
      - (cos(piByTwo*l2) - cos(piByTwo*l1))/piByTwo/dLinearRampDt()
      + (t2 - min(t2, end()));
}


// ************************************************************************* //
