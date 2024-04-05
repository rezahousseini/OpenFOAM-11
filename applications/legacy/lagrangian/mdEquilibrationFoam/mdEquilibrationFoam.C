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

Application
    mdEquilibrationFoam

Description
    Solver to equilibrate and/or precondition molecular dynamics systems.

\*---------------------------------------------------------------------------*/

#include "global/argList/argList.H"
#include "mdTools/md.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "include/setRootCase.H"
    #include "include/createTime.H"
    #include "include/createMesh.H"

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info<< "\nReading field U\n" << endl;
    volVectorField U
    (
        IOobject
        (
            "U",
            runTime.name(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    potential pot(mesh);

    moleculeCloud molecules(mesh, pot);

    #include "mdTools/temperatureAndPressureVariables.H"

    #include "readmdEquilibrationDict.H"

    label nAveragingSteps = 0;

    Info<< "\nStarting time loop\n" << endl;

    while (runTime.loop())
    {
        nAveragingSteps++;

        Info<< "Time = " << runTime.userTimeName() << endl;

        molecules.evolve();

        #include "mdTools/meanMomentumEnergyAndNMols.H"

        #include "mdTools/temperatureAndPressure.H"

        #include "mdTools/temperatureEquilibration.H"

        runTime.write();

        if (runTime.writeTime())
        {
            nAveragingSteps = 0;
        }

        Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
            << "  ClockTime = " << runTime.elapsedClockTime() << " s"
            << nl << endl;
    }

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
