/*--------------------------------*- C++ -*----------------------------------*\
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

Class
    Foam::patchToPoly2DMesh

Description
    Convert a primitivePatch into a 2D polyMesh.

SourceFiles
    patchToPoly2DMesh.C

\*---------------------------------------------------------------------------*/

#ifndef patchToPoly2DMesh_H
#define patchToPoly2DMesh_H

#include "meshes/meshShapes/edge/EdgeMap.H"
#include "MeshedSurface/MeshedSurface.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                      Class patchToPoly2DMesh Declaration
\*---------------------------------------------------------------------------*/

class patchToPoly2DMesh
{
    // Private Data

        // Reference to the meshed surface
        const MeshedSurface<face>& patch_;

        const wordList& patchNames_;

        const labelList& patchSizes_;

        labelList patchStarts_;

        const EdgeMap<label>& mapEdgesRegion_;

        pointField points_;

        faceList faces_;

        labelList owner_;

        labelList neighbour_;


    // Private Member Functions

        void flipFaceOrder();

        void createNeighbours();

        labelList internalFaceOrder();

        void addPatchFacesToFaces();

        void addPatchFacesToOwner();

        void createPolyMeshComponents();


public:

    // Constructors

        //- Construct from a primitivePatch
        patchToPoly2DMesh
        (
            const MeshedSurface<face>& patch,
            const wordList& patchNames,
            const labelList& patchSizes,
            const EdgeMap<label>& mapEdgesRegion
        );

        //- Disallow default bitwise copy construction
        patchToPoly2DMesh(const patchToPoly2DMesh&) = delete;


    //- Destructor
    ~patchToPoly2DMesh();


    // Member Functions

        // Access

            pointField& points()
            {
                return points_;
            }

            faceList& faces()
            {
                return faces_;
            }

            labelList& owner()
            {
                return owner_;
            }

            labelList& neighbour()
            {
                return neighbour_;
            }

            const wordList& patchNames() const
            {
                return patchNames_;
            }

            const labelList& patchSizes() const
            {
                return patchSizes_;
            }

            const labelList& patchStarts() const
            {
                return patchStarts_;
            }


        // Edit

            //- Create the mesh
            void createMesh();


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const patchToPoly2DMesh&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
