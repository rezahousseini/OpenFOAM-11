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

#include "clouds/derived/reactingMultiphaseCloud/reactingMultiphaseCloud.H"

#include "parcels/include/makeParcelCloudFunctionObjects.H"

// Momentum
#include "parcels/include/makeThermoParcelForces.H"
#include "parcels/include/makeParcelDispersionModels.H"
#include "parcels/include/makeReactingMultiphaseParcelInjectionModels.H"
#include "parcels/include/makeParcelPatchInteractionModels.H"
#include "parcels/include/makeReactingMultiphaseParcelStochasticCollisionModels.H"
#include "parcels/include/makeParcelSurfaceFilmModels.H"

// Thermodynamic
#include "parcels/include/makeParcelHeatTransferModels.H"

// Reacting
#include "parcels/include/makeReactingMultiphaseParcelCompositionModels.H"
#include "parcels/include/makeReactingParcelPhaseChangeModels.H"

// Reacting multiphase
#include "parcels/include/makeReactingMultiphaseParcelDevolatilisationModels.H"
#include "parcels/include/makeReactingMultiphaseParcelSurfaceReactionModels.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makeParcelCloudFunctionObjects(reactingMultiphaseCloud);

// Momentum sub-models
makeThermoParcelForces(reactingMultiphaseCloud);
makeParcelDispersionModels(reactingMultiphaseCloud);
makeReactingMultiphaseParcelInjectionModels(reactingMultiphaseCloud);
makeParcelPatchInteractionModels(reactingMultiphaseCloud);
makeReactingMultiphaseParcelStochasticCollisionModels
(
    reactingMultiphaseCloud
);
makeParcelSurfaceFilmModels(reactingMultiphaseCloud);

// Thermo sub-models
makeParcelHeatTransferModels(reactingMultiphaseCloud);

// Reacting sub-models
makeReactingMultiphaseParcelCompositionModels
(
    reactingMultiphaseCloud
);
makeReactingParcelPhaseChangeModels(reactingMultiphaseCloud);

// Reacting multiphase sub-models
makeReactingMultiphaseParcelDevolatilisationModels
(
    reactingMultiphaseCloud
);
makeReactingMultiphaseParcelSurfaceReactionModels
(
    reactingMultiphaseCloud
);


// ************************************************************************* //
