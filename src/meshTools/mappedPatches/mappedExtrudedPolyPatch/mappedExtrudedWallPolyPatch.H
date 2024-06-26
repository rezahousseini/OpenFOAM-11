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

Class
    Foam::mappedExtrudedWallPolyPatch

Description
    Wall patch which holds a mapping engine to map values from another patch

SourceFiles
    mappedExtrudedWallPolyPatch.C

\*---------------------------------------------------------------------------*/

#ifndef mappedExtrudedWallPolyPatch_H
#define mappedExtrudedWallPolyPatch_H

#include "meshes/polyMesh/polyPatches/derived/wall/wallPolyPatch.H"
#include "mappedPatches/mappedExtrudedPatchBase/mappedExtrudedPatchBase.H"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                     Class mappedExtrudedWallPolyPatch Declaration
\*---------------------------------------------------------------------------*/

class mappedExtrudedWallPolyPatch
:
    public wallPolyPatch,
    public mappedExtrudedPatchBase
{
protected:

    // Protected Member Functions

        //- Calculate the patch geometry
        virtual void calcGeometry(PstreamBuffers&);

        //- Correct patches after moving points
        virtual void movePoints(PstreamBuffers&, const pointField&);

        //- Update of the patch topology
        virtual void topoChange(PstreamBuffers&);


public:

    //- Runtime type information
    TypeName("mappedExtrudedWall");


    // Constructors

        //- Construct from components
        mappedExtrudedWallPolyPatch
        (
            const word& name,
            const label size,
            const label start,
            const label index,
            const polyBoundaryMesh& bm,
            const word& patchType
        );

        //- Construct from components
        mappedExtrudedWallPolyPatch
        (
            const word& name,
            const label size,
            const label start,
            const label index,
            const word& neighbourRegion,
            const word& neighbourPatch,
            const bool isExtrudedRegion,
            const polyBoundaryMesh& bm
        );

        //- Construct from dictionary
        mappedExtrudedWallPolyPatch
        (
            const word& name,
            const dictionary& dict,
            const label index,
            const polyBoundaryMesh& bm,
            const word& patchType
        );

        //- Construct as copy, resetting the boundary mesh
        mappedExtrudedWallPolyPatch
        (
            const mappedExtrudedWallPolyPatch&,
            const polyBoundaryMesh&
        );

        //- Construct given the original patch and resetting the
        //  face list and boundary mesh information
        mappedExtrudedWallPolyPatch
        (
            const mappedExtrudedWallPolyPatch& pp,
            const polyBoundaryMesh& bm,
            const label index,
            const label newSize,
            const label newStart
        );

        //- Construct and return a clone, resetting the boundary mesh
        virtual autoPtr<polyPatch> clone(const polyBoundaryMesh& bm) const
        {
            return autoPtr<polyPatch>
            (
                new mappedExtrudedWallPolyPatch(*this, bm)
            );
        }

        //- Construct and return a clone, resetting the face list
        //  and boundary mesh
        virtual autoPtr<polyPatch> clone
        (
            const polyBoundaryMesh& bm,
            const label index,
            const label newSize,
            const label newStart
        ) const
        {
            return autoPtr<polyPatch>
            (
                new mappedExtrudedWallPolyPatch
                (
                    *this,
                    bm,
                    index,
                    newSize,
                    newStart
                )
            );
        }


    //- Destructor
    virtual ~mappedExtrudedWallPolyPatch();


    // Member Functions

        //- Write the polyPatch data as a dictionary
        virtual void write(Ostream&) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
