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

\*---------------------------------------------------------------------------*/

#include "meshes/pointMesh/pointPatches/constraint/cyclic/cyclicPointPatch.H"
#include "meshes/pointMesh/pointBoundaryMesh/pointBoundaryMesh.H"
#include "db/runTimeSelection/construction/addToRunTimeSelectionTable.H"
#include "meshes/pointMesh/pointMesh.H"
#include "meshes/meshShapes/edge/edgeList.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(cyclicPointPatch, 0);
    addToRunTimeSelectionTable
    (
        facePointPatch,
        cyclicPointPatch,
        polyPatch
    );
}

// * * * * * * * * * * * * * Protected Member Functions  * * * * * * * * * * //

void Foam::cyclicPointPatch::initCalcGeometry(PstreamBuffers&)
{}


void Foam::cyclicPointPatch::calcGeometry(PstreamBuffers&)
{}


void Foam::cyclicPointPatch::initMovePoints(PstreamBuffers&, const pointField&)
{}


void Foam::cyclicPointPatch::movePoints(PstreamBuffers&, const pointField&)
{}


void Foam::cyclicPointPatch::initTopoChange(PstreamBuffers& pBufs)
{
    facePointPatch::initTopoChange(pBufs);
    cyclicPointPatch::initCalcGeometry(pBufs);
}


void Foam::cyclicPointPatch::topoChange(PstreamBuffers& pBufs)
{
    facePointPatch::topoChange(pBufs);
    cyclicPointPatch::calcGeometry(pBufs);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::cyclicPointPatch::cyclicPointPatch
(
    const polyPatch& patch,
    const pointBoundaryMesh& bm
)
:
    coupledFacePointPatch(patch, bm),
    cyclicPolyPatch_(refCast<const cyclicPolyPatch>(patch))
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::cyclicPointPatch::~cyclicPointPatch()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

const Foam::edgeList& Foam::cyclicPointPatch::transformPairs() const
{
    return cyclicPolyPatch_.coupledPoints();
}


// ************************************************************************* //
