/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2013-2021 OpenFOAM Foundation
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

#include "makeIncompressibleMomentumTransportModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makeBaseMomentumTransportModel
(
    geometricOneField,
    geometricOneField,
    incompressibleMomentumTransportModel
);


// -------------------------------------------------------------------------- //
// Laminar models
// -------------------------------------------------------------------------- //

#include "laminar/Stokes/Stokes.H"
makeLaminarModel(Stokes);

#include "laminar/generalisedNewtonian/generalisedNewtonian.H"
makeLaminarModel(generalisedNewtonian);

#include "laminar/lambdaThixotropic/lambdaThixotropic.H"
makeLaminarModel(lambdaThixotropic);

#include "laminar/Maxwell/Maxwell.H"
makeLaminarModel(Maxwell);

#include "laminar/Giesekus/Giesekus.H"
makeLaminarModel(Giesekus);

#include "laminar/PTT/PTT.H"
makeLaminarModel(PTT);


// -------------------------------------------------------------------------- //
// RAS models
// -------------------------------------------------------------------------- //

#include "RAS/SpalartAllmaras/SpalartAllmaras.H"
makeRASModel(SpalartAllmaras);

#include "RAS/kEpsilon/kEpsilon.H"
makeRASModel(kEpsilon);

#include "RAS/RNGkEpsilon/RNGkEpsilon.H"
makeRASModel(RNGkEpsilon);

#include "RAS/realizableKE/realizableKE.H"
makeRASModel(realizableKE);

#include "RAS/LaunderSharmaKE/LaunderSharmaKE.H"
makeRASModel(LaunderSharmaKE);

#include "RAS/kOmega/kOmega.H"
makeRASModel(kOmega);

#include "RAS/kOmega2006/kOmega2006.H"
makeRASModel(kOmega2006);

#include "RAS/kOmegaSST/kOmegaSST.H"
makeRASModel(kOmegaSST);

#include "RAS/kOmegaSSTSAS/kOmegaSSTSAS.H"
makeRASModel(kOmegaSSTSAS);

#include "RAS/kOmegaSSTLM/kOmegaSSTLM.H"
makeRASModel(kOmegaSSTLM);

#include "RAS/v2f/v2f.H"
makeRASModel(v2f);

#include "RAS/LRR/LRR.H"
makeRASModel(LRR);

#include "RAS/SSG/SSG.H"
makeRASModel(SSG);


// -------------------------------------------------------------------------- //
// LES models
// -------------------------------------------------------------------------- //

#include "LES/Smagorinsky/Smagorinsky.H"
makeLESModel(Smagorinsky);

#include "LES/WALE/WALE.H"
makeLESModel(WALE);

#include "LES/kEqn/kEqn.H"
makeLESModel(kEqn);

#include "LES/dynamicKEqn/dynamicKEqn.H"
makeLESModel(dynamicKEqn);

#include "LES/dynamicLagrangian/dynamicLagrangian.H"
makeLESModel(dynamicLagrangian);

#include "LES/kOmegaSSTDES/kOmegaSSTDES.H"
makeLESModel(kOmegaSSTDES);

#include "LES/SpalartAllmarasDES/SpalartAllmarasDES.H"
makeLESModel(SpalartAllmarasDES);

#include "LES/SpalartAllmarasDDES/SpalartAllmarasDDES.H"
makeLESModel(SpalartAllmarasDDES);

#include "LES/SpalartAllmarasIDDES/SpalartAllmarasIDDES.H"
makeLESModel(SpalartAllmarasIDDES);

#include "LES/DeardorffDiffStress/DeardorffDiffStress.H"
makeLESModel(DeardorffDiffStress);


// ************************************************************************* //
