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

#include "snappyHexMeshDriver/snappyLayerDriver.H"
#include "meshes/polyMesh/syncTools/syncTools.H"

// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

template<class Type>
void Foam::snappyLayerDriver::averageNeighbours
(
    const polyMesh& mesh,
    const PackedBoolList& isMasterEdge,
    const labelList& meshEdges,
    const labelList& meshPoints,
    const edgeList& edges,
    const scalarField& invSumWeight,
    const Field<Type>& data,
    Field<Type>& average
)
{
    const pointField& pts = mesh.points();

    average = Zero;

    forAll(edges, edgei)
    {
        if (isMasterEdge.get(meshEdges[edgei]) == 1)
        {
            const edge& e = edges[edgei];
            // scalar eWeight = edgeWeights[edgei];
            // scalar eWeight =  1.0;
            scalar eMag = max
            (
                vSmall,
                mag
                (
                    pts[meshPoints[e[1]]]
                  - pts[meshPoints[e[0]]]
                )
            );
            scalar eWeight = 1.0/eMag;

            label v0 = e[0];
            label v1 = e[1];

            average[v0] += eWeight*data[v1];
            average[v1] += eWeight*data[v0];
        }
    }

    syncTools::syncPointList
    (
        mesh,
        meshPoints,
        average,
        plusEqOp<Type>(),
        Zero     // null value
    );

    average *= invSumWeight;
}


// ************************************************************************* //
