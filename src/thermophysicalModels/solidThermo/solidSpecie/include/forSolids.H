/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2019-2022 OpenFOAM Foundation
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

#ifndef forSolids_H
#define forSolids_H

#include "specie/specie.H"

#include "equationOfState/rhoConst/rhoConst.H"

#include "thermo/eConst/eConstThermo.H"
#include "thermo/ePolynomial/ePolynomialThermo.H"
#include "thermo/ePower/ePowerThermo.H"
#include "thermo/eIcoTabulated/eIcoTabulatedThermo.H"

#include "thermo/sensibleInternalEnergy/sensibleInternalEnergy.H"

#include "solidSpecie/transport/constIso/constIsoSolidTransport.H"
#include "solidSpecie/transport/constAniso/constAnisoSolidTransport.H"
#include "solidSpecie/transport/exponential/exponentialSolidTransport.H"
#include "solidSpecie/transport/polynomial/polynomialSolidTransport.H"
#include "solidSpecie/transport/tabulated/tabulatedSolidTransport.H"

#include "thermo/thermo/thermo.H"

#include "include/forThermo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define forSolidEquations(Mu, He, Cp, Macro, Args...)                          \
    forThermo(Mu, He, Cp, rhoConst, specie, Macro, Args)

#define forSolidEnergiesAndThermos(Mu, Macro, Args...)                         \
    forSolidEquations(Mu, sensibleInternalEnergy, eConstThermo, Macro, Args);  \
    forSolidEquations                                                          \
        (Mu, sensibleInternalEnergy, ePolynomialThermo, Macro, Args);          \
    forSolidEquations(Mu, sensibleInternalEnergy, ePowerThermo, Macro, Args)   \
    forSolidEquations                                                          \
        (Mu, sensibleInternalEnergy, eIcoTabulatedThermo, Macro, Args)

#define forSolidTransports(Macro, Args...)                                     \
    forSolidEnergiesAndThermos(constIsoSolidTransport, Macro, Args);           \
    forSolidEnergiesAndThermos(constAnisoSolidTransport, Macro, Args);         \
    forSolidEnergiesAndThermos(exponentialSolidTransport, Macro, Args);        \
    forSolidEnergiesAndThermos(polynomialSolidTransport, Macro, Args)          \
    forSolidEnergiesAndThermos(tabulatedSolidTransport, Macro, Args)

#define forSolids(Macro, Args...)                                              \
    forSolidTransports(Macro, Args)

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
