/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2012-2022 OpenFOAM Foundation
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

#include "mixtures/coefficientMulticomponentMixture/coefficientMulticomponentMixture.H"
#include "mixtures/coefficientWilkeMulticomponentMixture/coefficientWilkeMulticomponentMixture.H"
#include "mixtures/valueMulticomponentMixture/valueMulticomponentMixture.H"
#include "mixtures/singleComponentMixture/singleComponentMixture.H"

#include "rhoThermo/rhoThermo.H"
#include "rhoMulticomponentThermo/rhoMulticomponentThermo.H"
#include "rhoThermo/heRhoThermo.H"

#include "include/forGases.H"
#include "include/forLiquids.H"
#include "include/forTabulated.H"
#include "makeMulticomponentThermo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define makeRhoMulticomponentThermos(Mixture, ThermoPhysics)                   \
    makeMulticomponentThermos                                                  \
    (                                                                          \
        rhoThermo,                                                             \
        rhoMulticomponentThermo,                                               \
        heRhoThermo,                                                           \
        Mixture,                                                               \
        ThermoPhysics                                                          \
    )

#define makeRhoMulticomponentThermo(Mixture, ThermoPhysics)                    \
    makeMulticomponentThermo                                                   \
    (                                                                          \
        rhoMulticomponentThermo,                                               \
        heRhoThermo,                                                           \
        Mixture,                                                               \
        ThermoPhysics                                                          \
    )

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    forCoeffGases
    (
        makeRhoMulticomponentThermos,
        coefficientMulticomponentMixture
    );

    forCoeffGases
    (
        makeRhoMulticomponentThermos,
        coefficientWilkeMulticomponentMixture
    );

    forGases(makeRhoMulticomponentThermo, singleComponentMixture);

    forCoeffLiquids
    (
        makeRhoMulticomponentThermos,
        coefficientMulticomponentMixture
    );
    forLiquids(makeRhoMulticomponentThermos, valueMulticomponentMixture);
    forLiquids(makeRhoMulticomponentThermo, singleComponentMixture);

    forTabulated(makeRhoMulticomponentThermos, valueMulticomponentMixture);
    forTabulated(makeRhoMulticomponentThermo, singleComponentMixture);
}

// ************************************************************************* //
