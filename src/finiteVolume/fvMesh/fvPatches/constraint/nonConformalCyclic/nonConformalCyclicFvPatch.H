/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2021-2022 OpenFOAM Foundation
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
    Foam::nonConformalCyclicFvPatch

Description
    Non-conformal cyclic FV patch. As nonConformalCoupledFvPatch, but the
    neighbouring patch is local and known and is made available by this class.

See also
    Foam::nonConformalCyclicPolyPatch
    Foam::nonConformalCoupledFvPatch

SourceFiles
    nonConformalCyclicFvPatch.C

\*---------------------------------------------------------------------------*/

#ifndef nonConformalCyclicFvPatch_H
#define nonConformalCyclicFvPatch_H

#include "fvMesh/fvPatches/constraint/cyclic/cyclicFvPatch.H"
#include "nonConformal/polyPatches/nonConformalCyclic/nonConformalCyclicPolyPatch.H"
#include "fvMesh/fvPatches/constraint/nonConformalCoupled/nonConformalCoupledFvPatch.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class nonConformalErrorFvPatch;

/*---------------------------------------------------------------------------*\
                  Class nonConformalCyclicFvPatch Declaration
\*---------------------------------------------------------------------------*/

class nonConformalCyclicFvPatch
:
    public cyclicFvPatch,
    public nonConformalCoupledFvPatch
{
    // Private Data

        //- Reference to the polyPatch
        const nonConformalCyclicPolyPatch& nonConformalCyclicPolyPatch_;


protected:

    // Protected Member functions

        //- Make patch weighting factors
        void makeWeights(scalarField&) const;


public:

    //- Runtime type information
    TypeName(nonConformalCyclicPolyPatch::typeName_());


    // Constructors

        //- Construct from polyPatch and fvBoundaryMesh
        nonConformalCyclicFvPatch
        (
            const polyPatch& patch,
            const fvBoundaryMesh& bm
        );


    //- Destructor
    virtual ~nonConformalCyclicFvPatch();


    // Member Functions

        // Access

            //- Poly patch
            const nonConformalCyclicPolyPatch& nonConformalCyclicPatch() const;

            //- Neighbour patch
            const nonConformalCyclicFvPatch& nbrPatch() const;

            //- ...
            using cyclicFvPatch::owner;

            //- ...
            using cyclicFvPatch::neighbour;

            //- ...
            using cyclicFvPatch::transform;

            //- Is this patch coupled? Returns true. For NCC patches the poly
            //  mesh is considered non-coupled whilst the finite volume mesh is
            //  considered coupled.
            virtual bool coupled() const;

            //- Return the start label of this patch in the polyMesh face list.
            //  Raises an error unless the patch is empty.
            virtual label start() const;

            //- Return the size
            virtual label size() const;

            //- Return the face-cells
            virtual const labelUList& faceCells() const;


        //- Return delta (P to N) vectors across coupled patch
        virtual tmp<vectorField> delta() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
