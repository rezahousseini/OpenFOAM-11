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
    pdfPlot

Description
    Generates a graph of a probability distribution function.

\*---------------------------------------------------------------------------*/

#include "global/argList/argList.H"
#include "db/Time/Time.H"
#include "distributions/distribution/distribution.H"
#include "sampledSet/writers/setWriter.H"
#include "db/functionObjects/writeFile/writeFile.H"
#include "db/IOstreams/Fstreams/OFstream.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "include/setRootCase.H"
    #include "include/createTime.H"
    #include "createFields.H"

    label iCheck = 100;
    for (label i=1; i<=nSamples; i++)
    {
        scalar ps = p->sample();
        label n = label((ps - xMin)*nIntervals/(xMax - xMin));
        samples[n]++;

        if (writeData)
        {
            filePtr() << ps << nl;
        }

        if (i % iCheck == 0)
        {
            Info<< "    processed " << i << " samples" << endl;

            if (i == 10*iCheck)
            {
                iCheck *= 10;
            }
        }
    }

    scalarField x(nIntervals);
    forAll(x, i)
    {
        x[i] = xMin + i*(xMax - xMin)/(nIntervals - 1);
    }

    setWriter::New(runTime.controlDict().lookup("graphFormat"))->write
    (
        pdfPath,
        args.executable(),
        coordSet(true, "x", x),
        p->type(),
        samples
    );

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
