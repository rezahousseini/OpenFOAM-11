/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2014-2023 OpenFOAM Foundation
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

#include "makePhaseCompressibleMomentumTransportModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "RAS/LaheyKEpsilon/LaheyKEpsilon.H"
makeRASModel(LaheyKEpsilon);

#include "RAS/kOmegaSSTSato/kOmegaSSTSato.H"
makeRASModel(kOmegaSSTSato);

#include "RAS/continuousGasKEpsilon/continuousGasKEpsilon.H"
makeRASModel(continuousGasKEpsilon);

#include "RAS/mixtureKEpsilon/mixtureKEpsilon.H"
makeRASModel(mixtureKEpsilon);

#include "LES/SmagorinskyZhang/SmagorinskyZhang.H"
makeLESModel(SmagorinskyZhang);

#include "LES/Niceno/NicenoKEqn.H"
makeLESModel(NicenoKEqn);

#include "LES/continuousGasKEqn/continuousGasKEqn.H"
makeLESModel(continuousGasKEqn);

#include "kineticTheoryModels/kineticTheoryModel/kineticTheoryModel.H"
makeMomentumTransportModel
(
    phaseCompressibleMomentumTransportModel,
    RAS,
    kineticTheoryModel
);

#include "phasePressureModel/phasePressureModel.H"
makeMomentumTransportModel
(
    phaseCompressibleMomentumTransportModel,
    RAS,
    phasePressureModel
);


// ************************************************************************* //
