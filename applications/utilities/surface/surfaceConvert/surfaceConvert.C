/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2022 OpenFOAM Foundation
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
    surfaceConvert

Description
    Converts from one surface mesh format to another.

Usage
    \b surfaceConvert inputFile outputFile [OPTION]

    Options:
      - \par -clean
        Perform some surface checking/cleanup on the input surface

      - \par -scale \<scale\>
        Specify a scaling factor for writing the files

      - \par -group
        Orders faces by region

    Note
        The filename extensions are used to determine the file format type.

\*---------------------------------------------------------------------------*/

#include "global/argList/argList.H"
#include "primitives/strings/fileName/fileName.H"
#include "triSurface/triSurface.H"
#include "db/IOstreams/Fstreams/OFstream.H"
#include "include/OSspecific.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "include/removeCaseOptions.H"

    argList::addNote
    (
        "convert between surface formats"
    );

    argList::validArgs.append("surface file");
    argList::validArgs.append("output surface file");

    argList::addBoolOption
    (
        "clean",
        "perform some surface checking/cleanup on the input surface"
    );
    argList::addBoolOption
    (
        "group",
        "reorder faces into groups; one per region"
    );
    argList::addOption
    (
        "scale",
        "factor",
        "geometry scaling factor - default is 1"
    );
    argList::addOption
    (
        "writePrecision",
        "label",
        "write to output with the specified precision"
    );

    argList args(argc, argv);

    if (args.optionFound("writePrecision"))
    {
        label writePrecision = args.optionRead<label>("writePrecision");

        IOstream::defaultPrecision(writePrecision);
        Sout.precision(writePrecision);

        Info<< "Output write precision set to " << writePrecision << endl;
    }

    const fileName importName = args[1];
    const fileName exportName = args[2];

    if (importName == exportName)
    {
        FatalErrorInFunction
            << "Output file " << exportName << " would overwrite input file."
            << exit(FatalError);
    }

    Info<< "Reading : " << importName << endl;
    triSurface surf(importName);

    Info<< "Read surface:" << endl;
    surf.writeStats(Info);
    Info<< endl;

    if (args.optionFound("clean"))
    {
        Info<< "Cleaning up surface" << endl;
        surf.cleanup(true);

        Info<< "After cleaning up surface:" << endl;
        surf.writeStats(Info);
        Info<< endl;
    }

    const bool sortByRegion = args.optionFound("group");
    if (sortByRegion)
    {
        Info<< "Reordering faces into groups; one per region." << endl;
    }
    else
    {
        Info<< "Maintaining face ordering" << endl;
    }

    Info<< "writing " << exportName;

    scalar scaleFactor = 0;
    if (args.optionReadIfPresent("scale", scaleFactor) && scaleFactor > 0)
    {
        Info<< " with scaling " << scaleFactor;
        surf.scalePoints(scaleFactor);
    }
    Info<< endl;

    surf.write(exportName, sortByRegion);

    Info<< "\nEnd\n" << endl;

    return 0;
}

// ************************************************************************* //
