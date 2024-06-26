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
    Foam::reactionRateFlameArea

Description
    Abstract class for reaction rate per flame area unit

SourceFiles
    reactionRateFlameArea.C
    reactionRateFlameAreaNew.C

\*---------------------------------------------------------------------------*/

#ifndef reactionRateFlameArea_H
#define reactionRateFlameArea_H

#include "db/runTimeSelection/construction/runTimeSelectionTables.H"
#include "db/dictionary/dictionary.H"
#include "memory/autoPtr/autoPtr.H"
#include "fields/volFields/volFields.H"
#include "combustionModel/combustionModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
class fvMesh;

/*---------------------------------------------------------------------------*\
                    Class reactionRateFlameArea Declaration
\*---------------------------------------------------------------------------*/

class reactionRateFlameArea
{

protected:

    // Protected data

        //- Dictionary
        dictionary coeffDict_;

        //- Mesh reference
        const fvMesh& mesh_;

        //- Combustion model owner
        const combustionModel& combModel_;

        //- Fuel name
        word fuel_;

        //- Fuel consumption rate per unit of flame area
        volScalarField omega_;


public:

    //- Runtime type information
    TypeName("reactionRateFlameArea");


    // Declare run-time constructor selection table

        declareRunTimeSelectionTable
        (
            autoPtr,
            reactionRateFlameArea,
            dictionary,
            (
                const word modelType,
                const dictionary& dict,
                const fvMesh& mesh,
                const combustionModel& combModel
            ),
            (modelType, dict, mesh, combModel)
        );


    // Constructors

        //- Construct from components
        reactionRateFlameArea
        (
            const word& modelType,
            const dictionary& dict,
            const fvMesh& mesh,
            const combustionModel& combModel
        );

        //- Disallow default bitwise copy construction
        reactionRateFlameArea(const reactionRateFlameArea&) = delete;


    // Selector

        static autoPtr<reactionRateFlameArea> New
        (
            const dictionary& dict,
            const fvMesh& mesh,
            const combustionModel& combModel
        );


    // Destructor

        virtual ~reactionRateFlameArea();


    // Member Functions

        //- Access functions

            //- Return omega
            const volScalarField& omega() const
            {
                return omega_;
            }


        //- Correct omega
        virtual void correct(const volScalarField& sigma) = 0;

        //- Update from dictionary
        virtual bool read(const dictionary& dictProperties);


    // Member Operators

         //- Disallow default bitwise assignment
        void operator=(const reactionRateFlameArea&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
