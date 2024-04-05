/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2022 OpenFOAM Foundation
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

#ifndef makeParcelForces_H
#define makeParcelForces_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "submodels/Momentum/ParticleForces/Drag/SphereDrag/SphereDragForce.H"
#include "submodels/Momentum/ParticleForces/Drag/NonSphereDrag/NonSphereDragForce.H"
#include "submodels/Momentum/ParticleForces/Drag/SchillerNaumannDrag/SchillerNaumannDragForce.H"
#include "submodels/Momentum/ParticleForces/Drag/WenYuDrag/WenYuDragForce.H"
#include "submodels/Momentum/ParticleForces/Drag/ErgunWenYuDrag/ErgunWenYuDragForce.H"
#include "submodels/Momentum/ParticleForces/Drag/PlessisMasliyahDrag/PlessisMasliyahDragForce.H"

#include "submodels/Momentum/ParticleForces/Lift/SaffmanMeiLift/SaffmanMeiLiftForce.H"
#include "submodels/Momentum/ParticleForces/Lift/TomiyamaLift/TomiyamaLiftForce.H"

#include "submodels/Momentum/ParticleForces/Gravity/GravityForce.H"
#include "submodels/Momentum/ParticleForces/NonInertialFrame/NonInertialFrameForce.H"
#include "submodels/Momentum/ParticleForces/Paramagnetic/ParamagneticForce.H"
#include "submodels/Momentum/ParticleForces/PressureGradient/PressureGradientForce.H"
#include "submodels/Momentum/ParticleForces/VirtualMass/VirtualMassForce.H"

#include "submodels/Momentum/ParticleForces/Scaled/ScaledForce.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define makeParcelForces(CloudType)                                            \
                                                                               \
    makeParticleForceModel(CloudType);                                         \
    makeParticleForceModelType(SphereDragForce, CloudType);                    \
    makeParticleForceModelType(NonSphereDragForce, CloudType);                 \
    makeParticleForceModelType(SchillerNaumannDragForce, CloudType);           \
    makeParticleForceModelType(WenYuDragForce, CloudType);                     \
    makeParticleForceModelType(ErgunWenYuDragForce, CloudType);                \
    makeParticleForceModelType(PlessisMasliyahDragForce, CloudType);           \
    makeParticleForceModelType(SaffmanMeiLiftForce, CloudType);                \
    makeParticleForceModelType(TomiyamaLiftForce, CloudType);                  \
    makeParticleForceModelType(GravityForce, CloudType);                       \
    makeParticleForceModelType(NonInertialFrameForce, CloudType);              \
    makeParticleForceModelType(ParamagneticForce, CloudType);                  \
    makeParticleForceModelType(PressureGradientForce, CloudType);              \
    makeParticleForceModelType(VirtualMassForce, CloudType);                   \
    makeParticleForceModelType(ScaledForce, CloudType);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
