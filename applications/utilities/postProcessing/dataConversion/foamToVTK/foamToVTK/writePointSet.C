/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2020 OpenFOAM Foundation
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

#include "writePointSet.H"
#include "db/IOstreams/Fstreams/OFstream.H"
#include "vtkWriteFieldOps.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

void writePointSet
(
    const bool binary,
    const vtkMesh& vMesh,
    const pointSet& set,
    const fileName& fileName
)
{
    std::ofstream ostr(fileName.c_str());

    vtkWriteOps::writeHeader
    (
        ostr,
        binary,
        set.name()
    );

    ostr<< "DATASET POLYDATA" << std::endl;

    //------------------------------------------------------------------
    //
    // Write topology
    //
    //------------------------------------------------------------------


    // Write points

    ostr<< "POINTS " << set.size() << " float" << std::endl;

    DynamicList<floatScalar> ptField(3*set.size());

    vtkWriteOps::insert
    (
        UIndirectList<point>(vMesh.mesh().points(), set.toc())(),
        ptField
    );

    vtkWriteOps::write(ostr, binary, ptField);


    //-----------------------------------------------------------------
    //
    // Write data
    //
    //-----------------------------------------------------------------

    // Write faceID

    ostr
        << "POINT_DATA " << set.size() << std::endl
        << "FIELD attributes 1" << std::endl;

    // Cell ids first
    ostr<< "pointID 1 " << set.size() << " int" << std::endl;

    labelList pointIDs(set.toc());

    vtkWriteOps::write(ostr, binary, pointIDs);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
