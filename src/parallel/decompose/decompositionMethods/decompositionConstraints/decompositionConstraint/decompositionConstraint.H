/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2015-2020 OpenFOAM Foundation
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
    Foam::decompositionConstraint

Description

SourceFiles
    decompositionConstraint.C

\*---------------------------------------------------------------------------*/

#ifndef decompositionConstraint_H
#define decompositionConstraint_H

#include "db/dictionary/dictionary.H"
#include "db/runTimeSelection/construction/runTimeSelectionTables.H"
#include "primitives/bools/lists/boolList.H"
#include "primitives/ints/lists/labelList.H"
#include "primitives/Pair/labelPair.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of classes
class polyMesh;

/*---------------------------------------------------------------------------*\
                   Class decompositionConstraint Declaration
\*---------------------------------------------------------------------------*/

class decompositionConstraint
{
protected:

    // Protected data

        //- Model coefficients dictionary
        dictionary coeffDict_;


public:

    //- Runtime type information
    TypeName("decompositionConstraint");


    // Declare run-time constructor selection table

        declareRunTimeSelectionTable
        (
            autoPtr,
            decompositionConstraint,
            dictionary,
            (
                const dictionary& constraintsDict,
                const word& type
            ),
            (constraintsDict, type)
        );


    // Constructors

        //- Construct with generic dictionary with optional entry for type
        decompositionConstraint
        (
            const dictionary& constraintsDict,
            const word& type
        );

        //- Disallow default bitwise copy construction
        decompositionConstraint(const decompositionConstraint&) = delete;


    // Selectors

        //- Return a reference to the selected decompositionConstraint
        static autoPtr<decompositionConstraint> New
        (
            const dictionary& constraintsDict,
            const word& type
        );


    //- Destructor
    virtual ~decompositionConstraint();


    // Member Functions

        //- Add my constraints to list of constraints
        virtual void add
        (
            const polyMesh& mesh,
            boolList& blockedFace,
            PtrList<labelList>& specifiedProcessorFaces,
            labelList& specifiedProcessor,
            List<labelPair>& explicitConnections
        ) const = 0;

        //- Apply any additional post-decomposition constraints. Usually no
        //  need to do anything since decomposition method should have already
        //  obeyed the constraints
        virtual void apply
        (
            const polyMesh& mesh,
            const boolList& blockedFace,
            const PtrList<labelList>& specifiedProcessorFaces,
            const labelList& specifiedProcessor,
            const List<labelPair>& explicitConnections,
            labelList& decomposition
        ) const
        {}


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const decompositionConstraint&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
