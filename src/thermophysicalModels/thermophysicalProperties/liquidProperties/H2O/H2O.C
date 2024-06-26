/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2021 OpenFOAM Foundation
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

#include "liquidProperties/H2O/H2O.H"
#include "db/runTimeSelection/construction/addToRunTimeSelectionTable.H"

#include "global/constants/thermodynamic/thermodynamicConstants.H"
using namespace Foam::constant::thermodynamic;

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(H2O, 0);
    addToRunTimeSelectionTable(liquidProperties, H2O,);
    addToRunTimeSelectionTable(liquidProperties, H2O, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::H2O::H2O()
:
    liquidProperties
    (
        typeName,
        18.015,
        647.13,
        2.2055e+7,
        0.05595,
        0.229,
        273.16,
        6.113e+2,
        373.15,
        6.1709e-30,
        0.3449,
        4.7813e+4
    ),
    rho_("rho", 98.343885, 0.30542, 647.13, 0.081),
    pv_("pv", 73.649, -7258.2, -7.3037, 4.1653e-06, 2),
    hl_("hl", 647.13, 2889425.47876769, 0.3199, -0.212, 0.25795, 0),
    Cp_
    (
        "Cp",
        15341.1046350264,
       -116.019983347211,
        0.451013044684985,
       -0.000783569247849015,
        5.20127671384957e-07,
        0
    ),
    h_
    (
        "h",
       -17957283.7993676,
        15341.1046350264,
       -58.0099916736053,
        0.150337681561662,
       -0.000195892311962254,
        1.04025534276991e-07
    ),
    Cpg_
    (
        "Cpg",
        1851.73466555648,
        1487.53816264224,
        2609.3,
        493.366638912018,
        1167.6
    ),
    B_
    (
        "B",
       -0.0012789342214821,
        1.4909797391063,
       -1563696.91923397,
        1.85445462114904e+19,
       -7.68082153760755e+21
    ),
    mu_("mu", -51.964, 3670.6, 5.7331, -5.3495e-29, 10),
    mug_("mug", 2.6986e-06, 0.498, 1257.7, -19570),
    kappa_("kappa", -0.4267, 0.0056903, -8.0065e-06, 1.815e-09, 0, 0),
    kappag_("kappag", 6.977e-05, 1.1243, 844.9, -148850),
    sigma_("sigma", 647.13, 0.18548, 2.717, -3.554, 2.047, 0),
    D_("D", 15.0, 15.0, 18.015, 28),
    Hf_(h_.value(Tstd))
{}


Foam::H2O::H2O
(
    const liquidProperties& l,
    const Function1s::NSRDS5& density,
    const Function1s::NSRDS1& vapourPressure,
    const Function1s::NSRDS6& heatOfVapourisation,
    const Function1s::NSRDS0& heatCapacity,
    const Function1s::NSRDS0& enthalpy,
    const Function1s::NSRDS7& idealGasHeatCapacity,
    const Function1s::NSRDS4& secondVirialCoeff,
    const Function1s::NSRDS1& dynamicViscosity,
    const Function1s::NSRDS2& vapourDynamicViscosity,
    const Function1s::NSRDS0& thermalConductivity,
    const Function1s::NSRDS2& vapourThermalConductivity,
    const Function1s::NSRDS6& surfaceTension,
    const Function2s::APIdiffCoef& vapourDiffusivity
)
:
    liquidProperties(l),
    rho_(density),
    pv_(vapourPressure),
    hl_(heatOfVapourisation),
    Cp_(heatCapacity),
    h_(enthalpy),
    Cpg_(idealGasHeatCapacity),
    B_(secondVirialCoeff),
    mu_(dynamicViscosity),
    mug_(vapourDynamicViscosity),
    kappa_(thermalConductivity),
    kappag_(vapourThermalConductivity),
    sigma_(surfaceTension),
    D_(vapourDiffusivity),
    Hf_(h_.value(Tstd))
{}


Foam::H2O::H2O(const dictionary& dict)
:
    H2O()
{
    readIfPresent(*this, dict);
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::H2O::write(Ostream& os) const
{
    liquidProperties::write(*this, os);
}


// ************************************************************************* //
