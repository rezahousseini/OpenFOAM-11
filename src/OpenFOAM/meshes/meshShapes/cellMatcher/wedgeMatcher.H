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

Class
    Foam::wedgeMatcher

Description
    A cellMatcher for wedge cells

See also
    cellMatcher

SourceFiles
    wedgeMatcher.C

\*---------------------------------------------------------------------------*/

#ifndef wedgeMatcher_H
#define wedgeMatcher_H

#include "meshes/meshShapes/cellMatcher/cellMatcher.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                        Class wedgeMatcher Declaration
\*---------------------------------------------------------------------------*/

class wedgeMatcher
:
    public cellMatcher
{
    // Static Data Members

        //- Constants for this shape
        static const label vertPerCell;
        static const label facePerCell;
        static const label maxVertPerFace;


public:

    // Constructors

        //- Construct null
        wedgeMatcher();

        //- Disallow default bitwise copy construction
        wedgeMatcher(const wedgeMatcher&) = delete;


    //- Destructor
    ~wedgeMatcher();


    // Member Functions

        virtual label nVertPerCell() const
        {
            return vertPerCell;
        }

        virtual label nFacePerCell() const
        {
            return facePerCell;
        }

        virtual label nMaxVertPerFace() const
        {
            return maxVertPerFace;
        }

        virtual label faceHashValue() const;

        virtual bool faceSizeMatch(const faceList&, const labelList&) const;

        virtual bool matchShape
        (
            const bool checkOnly,
            const faceList& faces,
            const labelList& faceOwner,
            const label celli,
            const labelList& myFaces
        );

        virtual bool isA(const primitiveMesh& mesh, const label celli);

        virtual bool isA(const faceList&);

        virtual bool matches
        (
            const primitiveMesh& mesh,
            const label celli,
            cellShape& shape
        );


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const wedgeMatcher&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
