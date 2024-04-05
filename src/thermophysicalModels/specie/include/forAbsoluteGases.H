/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2020-2021 OpenFOAM Foundation
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

#ifndef forAbsoluteGases_H
#define forAbsoluteGases_H

#include "specie/specie.H"

#include "equationOfState/perfectGas/perfectGas.H"

#include "thermo/eConst/eConstThermo.H"
#include "thermo/hConst/hConstThermo.H"
#include "thermo/janaf/janafThermo.H"

#include "thermo/absoluteEnthalpy/absoluteEnthalpy.H"

#include "transport/const/constTransport.H"
#include "transport/sutherland/sutherlandTransport.H"

#include "thermo/thermo/thermo.H"

#include "include/forThermo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define forAbsoluteGasEqns(Mu, He, Cp, Macro, Args...)                         \
    forThermo(Mu, He, Cp, perfectGas, specie, Macro, Args)

#define forAbsoluteGasEnergiesAndThermos(Mu, Macro, Args...)                   \
    forAbsoluteGasEqns(Mu, absoluteEnthalpy, hConstThermo, Macro, Args);       \
    forAbsoluteGasEqns(Mu, absoluteEnthalpy, janafThermo, Macro, Args);

#define forAbsoluteGasTransports(Macro, Args...)                               \
    forAbsoluteGasEnergiesAndThermos(constTransport, Macro, Args);             \
    forAbsoluteGasEnergiesAndThermos(sutherlandTransport, Macro, Args)

#define forAbsoluteGases(Macro, Args...)                                       \
    forAbsoluteGasTransports(Macro, Args)

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
