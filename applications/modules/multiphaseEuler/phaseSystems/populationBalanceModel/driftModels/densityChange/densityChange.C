/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2017-2023 OpenFOAM Foundation
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

#include "populationBalanceModel/driftModels/densityChange/densityChange.H"
#include "db/runTimeSelection/construction/addToRunTimeSelectionTable.H"
#include "finiteVolume/fvc/fvcDdt.H"
#include "finiteVolume/fvc/fvcDiv.H"
#include "finiteVolume/fvc/fvcSup.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace diameterModels
{
namespace driftModels
{
    defineTypeNameAndDebug(densityChangeDrift, 0);
    addToRunTimeSelectionTable(driftModel, densityChangeDrift, dictionary);
}
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::diameterModels::driftModels::densityChangeDrift::densityChangeDrift
(
    const populationBalanceModel& popBal,
    const dictionary& dict
)
:
    driftModel(popBal, dict)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::diameterModels::driftModels::densityChangeDrift::addToDriftRate
(
    volScalarField& driftRate,
    const label i
)
{
    const sizeGroup& fi = popBal_.sizeGroups()[i];
    const phaseModel& phase = fi.phase();
    const volScalarField& alpha = phase;
    const volScalarField& rho = phase.rho();

    driftRate -=
        fi.x()
       *(
            fvc::ddt(alpha, rho) + fvc::div(phase.alphaRhoPhi())
          - fvc::Sp(fvc::ddt(alpha) + fvc::div(phase.alphaPhi()), rho)
        )/rho;
}


// ************************************************************************* //
