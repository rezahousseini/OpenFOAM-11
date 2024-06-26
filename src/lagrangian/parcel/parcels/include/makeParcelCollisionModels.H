/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2020 OpenFOAM Foundation
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

#ifndef makeParcelCollisionModels_H
#define makeParcelCollisionModels_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "submodels/Momentum/CollisionModel/NoCollision/NoCollision.H"
#include "submodels/Momentum/CollisionModel/PairCollision/PairCollision.H"

#include "submodels/Momentum/CollisionModel/PairCollision/PairModel/PairSpringSliderDashpot/PairSpringSliderDashpot.H"

#include "submodels/Momentum/CollisionModel/PairCollision/WallModel/WallSpringSliderDashpot/WallSpringSliderDashpot.H"
#include "submodels/Momentum/CollisionModel/PairCollision/WallModel/WallLocalSpringSliderDashpot/WallLocalSpringSliderDashpot.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define makeParcelCollisionModels(CloudType)                                   \
                                                                               \
    makeCollisionModel(CloudType);                                             \
    makeCollisionModelType(NoCollision, CloudType);                            \
    makeCollisionModelType(PairCollision, CloudType);                          \
                                                                               \
    makePairModel(CloudType);                                                  \
    makePairModelType(PairSpringSliderDashpot, CloudType);                     \
                                                                               \
    makeWallModel(CloudType);                                                  \
    makeWallModelType(WallSpringSliderDashpot, CloudType);                     \
    makeWallModelType(WallLocalSpringSliderDashpot, CloudType);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
