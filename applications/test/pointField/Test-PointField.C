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
    testPointField

Description
    For each time calculate the magnitude of velocity.

\*---------------------------------------------------------------------------*/

#include "global/argList/argList.H"
#include "fvMesh/fvMesh.H"
#include "fields/GeometricFields/pointFields/pointFields.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "include/setRootCase.H"

    #include "include/createTime.H"
    #include "include/createMesh.H"

    const pointMesh& pMesh = pointMesh::New(mesh);

    pointVectorField U
    (
        IOobject
        (
            "U",
            runTime.name(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        pMesh,
        dimensionedVector(dimLength, Zero),
        pointPatchVectorField::calculatedType()
    );

    pointVectorField V(U + 2*U);

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
