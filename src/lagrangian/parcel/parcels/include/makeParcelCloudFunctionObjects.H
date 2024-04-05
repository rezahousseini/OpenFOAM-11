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

#ifndef makeParcelCloudFunctionObjects_H
#define makeParcelCloudFunctionObjects_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "submodels/CloudFunctionObjects/FacePostProcessing/FacePostProcessing.H"
#include "submodels/CloudFunctionObjects/Flux/Flux.H"
#include "submodels/CloudFunctionObjects/ParticleCollector/ParticleCollector.H"
#include "submodels/CloudFunctionObjects/ParticleErosion/ParticleErosion.H"
#include "submodels/CloudFunctionObjects/ParticleTracks/ParticleTracks.H"
#include "submodels/CloudFunctionObjects/ParticleTrap/ParticleTrap.H"
#include "submodels/CloudFunctionObjects/PatchCollisionDensity/PatchCollisionDensity.H"
#include "submodels/CloudFunctionObjects/PatchPostProcessing/PatchPostProcessing.H"
#include "submodels/CloudFunctionObjects/RelativeVelocity/RelativeVelocity.H"
#include "submodels/CloudFunctionObjects/SizeDistribution/SizeDistribution.H"
#include "submodels/CloudFunctionObjects/VoidFraction/VoidFraction.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define makeParcelCloudFunctionObjects(CloudType)                              \
                                                                               \
    makeCloudFunctionObject(CloudType);                                        \
                                                                               \
    makeCloudFunctionObjectType(FacePostProcessing, CloudType);                \
    makeCloudFunctionObjectType(MassFlux, CloudType);                          \
    makeCloudFunctionObjectType(NumberFlux, CloudType);                        \
    makeCloudFunctionObjectType(ParticleCollector, CloudType);                 \
    makeCloudFunctionObjectType(ParticleErosion, CloudType);                   \
    makeCloudFunctionObjectType(ParticleTracks, CloudType);                    \
    makeCloudFunctionObjectType(ParticleTrap, CloudType);                      \
    makeCloudFunctionObjectType(PatchCollisionDensity, CloudType);             \
    makeCloudFunctionObjectType(PatchPostProcessing, CloudType);               \
    makeCloudFunctionObjectType(RelativeVelocity, CloudType);                  \
    makeCloudFunctionObjectType(VoidFraction, CloudType);                      \
    makeCloudFunctionObjectType(SizeDistribution, CloudType);                  \
    makeCloudFunctionObjectType(VolumeFlux, CloudType);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
