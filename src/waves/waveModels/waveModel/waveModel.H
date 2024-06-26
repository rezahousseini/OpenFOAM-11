/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2017-2021 OpenFOAM Foundation
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
    Foam::waveModel

Description
    Generic base class for waves. Derived classes must implement field
    functions which return the elevation above the wave surface and the
    velocity field, both as a function of position.

SourceFiles
    waveModel.C
    waveModelNew.C

\*---------------------------------------------------------------------------*/

#ifndef waveModel_H
#define waveModel_H

#include "db/dictionary/dictionary.H"
#include "primitives/functions/Function1/Function1/Function1.H"
#include "db/runTimeSelection/construction/runTimeSelectionTables.H"
#include "fields/Fields/vectorField/vectorField.H"
#include "fields/Fields/vector2DField/vector2DField.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                          Class waveModel Declaration
\*---------------------------------------------------------------------------*/

class waveModel
{
    // Private Data

        //- Gravitational acceleration [m/s^2]
        const scalar g_;


public:

    //- Runtime type information
    TypeName("waveModel");


    // Declare runtime construction
    declareRunTimeSelectionTable
    (
        autoPtr,
        waveModel,
        dictionary,
        (const dictionary& dict, const scalar g),
        (dict, g)
    );


    // Constructors

        //- Construct a copy
        waveModel(const waveModel& wave);

        //- Construct from a dictionary and gravity
        waveModel(const dictionary& dict, const scalar g);

        //- Construct a clone
        virtual autoPtr<waveModel> clone() const = 0;


    // Selectors

        //- Select
        static autoPtr<waveModel> New
        (
            const dictionary& dict,
            const scalar g
        );

        //- Select
        static autoPtr<waveModel> New
        (
            const word& type,
            const dictionary& dict,
            const scalar g
        );


    //- Destructor
    virtual ~waveModel();


    // Member Functions

        // Access

            //- Get the value of gravity
            scalar g() const
            {
                return g_;
            }

        //- Get the wave elevation at a given time and local coordinates. Local
        //  x is aligned with the direction of propagation.
        virtual tmp<scalarField> elevation
        (
            const scalar t,
            const scalarField& x
        ) const = 0;

        //- Get the wave velocity at a given time and local coordinates. Local
        //  x is aligned with the direction of propagation, and z with negative
        //  gravity.
        virtual tmp<vector2DField> velocity
        (
            const scalar t,
            const vector2DField& xz
        ) const = 0;

        //- Write
        virtual void write(Ostream& os) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
