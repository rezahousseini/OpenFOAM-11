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

#include "phaseFluidMulticomponentThermophysicalTransportModels.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makeThermophysicalTransportModelTables
(
    PhaseThermophysicalTransportModel,
    phaseCompressibleMomentumTransportModel,
    fluidMulticomponentThermo
);


// -------------------------------------------------------------------------- //
// Laminar models
// -------------------------------------------------------------------------- //

#include "laminar/Fourier/Fourier.H"
makeLaminarThermophysicalTransportModel(Fourier);

#include "laminar/unityLewisFourier/unityLewisFourier.H"
makeLaminarThermophysicalTransportModel(unityLewisFourier);

#include "laminar/FickianFourier/FickianFourier.H"
makeLaminarThermophysicalTransportModel(FickianFourier);

#include "laminar/MaxwellStefanFourier/MaxwellStefanFourier.H"
makeLaminarThermophysicalTransportModel(MaxwellStefanFourier);


// -------------------------------------------------------------------------- //
// RAS models
// -------------------------------------------------------------------------- //

#include "turbulence/eddyDiffusivity/eddyDiffusivity.H"
makeRASLESThermophysicalTransportModel(RAS, eddyDiffusivity);

#include "turbulence/unityLewisEddyDiffusivity/unityLewisEddyDiffusivity.H"
makeRASLESThermophysicalTransportModel(RAS, unityLewisEddyDiffusivity);

#include "turbulence/nonUnityLewisEddyDiffusivity/nonUnityLewisEddyDiffusivity.H"
makeRASLESThermophysicalTransportModel(RAS, nonUnityLewisEddyDiffusivity);

#include "turbulence/FickianEddyDiffusivity/FickianEddyDiffusivity.H"
makeRASLESThermophysicalTransportModel(RAS, FickianEddyDiffusivity);


// -------------------------------------------------------------------------- //
// LES models
// -------------------------------------------------------------------------- //

#include "turbulence/eddyDiffusivity/eddyDiffusivity.H"
makeRASLESThermophysicalTransportModel(LES, eddyDiffusivity);

#include "turbulence/unityLewisEddyDiffusivity/unityLewisEddyDiffusivity.H"
makeRASLESThermophysicalTransportModel(LES, unityLewisEddyDiffusivity);

#include "turbulence/nonUnityLewisEddyDiffusivity/nonUnityLewisEddyDiffusivity.H"
makeRASLESThermophysicalTransportModel(LES, nonUnityLewisEddyDiffusivity);


// ************************************************************************* //
