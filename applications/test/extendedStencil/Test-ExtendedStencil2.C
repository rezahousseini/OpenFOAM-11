/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2012-2023 OpenFOAM Foundation
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
    testExtendedStencil2

Description
    Test app for determining extended cell-to-cell stencil.

\*---------------------------------------------------------------------------*/

#include "global/argList/argList.H"
#include "db/Time/timeSelector.H"
#include "fvMesh/fvMesh.H"
#include "fields/volFields/volFields.H"
#include "fields/surfaceFields/surfaceFields.H"
#include "db/Time/Time.H"
#include "db/IOstreams/Fstreams/OFstream.H"
#include "meshTools/meshTools.H"

#include "fvMesh/extendedStencil/cellToCell/globalIndexStencils/CFCCellToCellStencil.H"


using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

void writeStencilOBJ
(
    const fileName& fName,
    const point& fc,
    const List<point>& stencilCc
)
{
    OFstream str(fName);
    label vertI = 0;

    meshTools::writeOBJ(str, fc);
    vertI++;

    forAll(stencilCc, i)
    {
        meshTools::writeOBJ(str, stencilCc[i]);
        vertI++;
        str << "l 1 " << vertI << nl;
    }
}


// Stats
void writeStencilStats(const labelListList& stencil)
{
    label sumSize = 0;
    label nSum = 0;
    label minSize = labelMax;
    label maxSize = labelMin;

    forAll(stencil, i)
    {
        const labelList& sCells = stencil[i];

        if (sCells.size() > 0)
        {
            sumSize += sCells.size();
            nSum++;
            minSize = min(minSize, sCells.size());
            maxSize = max(maxSize, sCells.size());
        }
    }
    reduce(sumSize, sumOp<label>());
    reduce(nSum, sumOp<label>());
    sumSize /= nSum;

    reduce(minSize, minOp<label>());
    reduce(maxSize, maxOp<label>());

    Info<< "Stencil size :" << nl
        << "    average : " << sumSize << nl
        << "    min     : " << minSize << nl
        << "    max     : " << maxSize << nl
        << endl;
}


// Main program:

int main(int argc, char *argv[])
{
    timeSelector::addOptions();
    #include "include/setRootCase.H"
    #include "include/createTime.H"
    timeSelector::select0(runTime, args);
    #include "include/createMesh.H"


    //---- CELL CENTRED STENCIL -----

    // Centred, cell stencil
    // ~~~~~~~~~~~~~~~~~~~~~

    {
        // Full stencil. This is per local cell a set of global indices, either
        // into cells or also boundary faces.
        CFCCellToCellStencil stencil(mesh);

        // Construct exchange map and renumber stencil
        List<Map<label>> compactMap(Pstream::nProcs());
        distributionMap map
        (
            stencil.globalNumbering(),
            stencil,
            compactMap
        );


        // Print some stats
        Info<< "cellFaceCell:" << endl;
        writeStencilStats(stencil);


        // Collect the data in stencil form
        List<List<vector>> stencilPoints;
        {
            const volVectorField& fld = mesh.C();

            // 1. Construct cell data in compact addressing
            List<point> compactFld(map.constructSize(), Zero);

            // Insert my internal values
            forAll(fld, celli)
            {
                compactFld[celli] = fld[celli];
            }
            // Insert my boundary values
            label nCompact = fld.size();
            forAll(fld.boundaryField(), patchi)
            {
                const fvPatchField<vector>& pfld = fld.boundaryField()[patchi];

                forAll(pfld, i)
                {
                    compactFld[nCompact++] = pfld[i];
                }
            }

            // Do all swapping
            map.distribute(compactFld);

            // 2. Pull to stencil
            stencilPoints.setSize(stencil.size());

            forAll(stencil, celli)
            {
                const labelList& compactCells = stencil[celli];

                stencilPoints[celli].setSize(compactCells.size());

                forAll(compactCells, i)
                {
                    stencilPoints[celli][i] = compactFld[compactCells[i]];
                }
            }
        }


        forAll(stencilPoints, celli)
        {
            writeStencilOBJ
            (
                runTime.path()/"centredCell" + Foam::name(celli) + ".obj",
                mesh.cellCentres()[celli],
                stencilPoints[celli]
            );
        }
    }

    Pout<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
