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
    attachMesh

Description
    Attach topologically detached mesh using prescribed mesh modifiers.

\*---------------------------------------------------------------------------*/

#include "global/argList/argList.H"
#include "meshes/polyMesh/polyMesh.H"
#include "db/Time/Time.H"
#include "polyTopoChange/attachPolyTopoChanger/attachPolyTopoChanger.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "include/addOverwriteOption.H"
    argList::noParallel();

    #include "include/setRootCase.H"
    #include "include/createTimeNoFunctionObjects.H"
    #include "include/createPolyMesh.H"
    const word oldInstance = mesh.pointsInstance();

    const bool overwrite = args.optionFound("overwrite");

    if (!overwrite)
    {
        runTime++;
    }

    Info<< "Time = " << runTime.userTimeName() << nl
        << "Attaching sliding interface" << endl;

    attachPolyTopoChanger(mesh).attach();

    if (overwrite)
    {
        mesh.setInstance(oldInstance);
    }
    mesh.write();

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
