/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2015-2023 OpenFOAM Foundation
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
    Foam::interfaceSurfaceTensionModel

Description
    Abstract base-class for interface surface-tension models which can be
    used when interface compression is applied between two phases.

SourceFiles
    interfaceSurfaceTensionModel.C
    interfaceSurfaceTensionModelNew.C

\*---------------------------------------------------------------------------*/

#ifndef interfaceSurfaceTensionModel_H
#define interfaceSurfaceTensionModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "fields/volFields/volFields.H"
#include "db/dictionary/dictionary.H"
#include "db/runTimeSelection/construction/runTimeSelectionTables.H"
#include "phaseInterface/phaseInterface/phaseInterface.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                     Class interfaceSurfaceTensionModel Declaration
\*---------------------------------------------------------------------------*/

class interfaceSurfaceTensionModel
{
protected:

    // Protected data

        //- Interface
        const phaseInterface interface_;


public:

    //- Runtime type information
    TypeName("surfaceTensionModel");


    // Declare runtime construction
    declareRunTimeSelectionTable
    (
        autoPtr,
        interfaceSurfaceTensionModel,
        dictionary,
        (
            const dictionary& dict,
            const phaseInterface& interface
        ),
        (dict, interface)
    );


    // Static Data Members

        //- Coefficient dimensions
        static const dimensionSet dimSigma;


    // Constructors

        //- Construct from a dictionary and an interface
        interfaceSurfaceTensionModel
        (
            const dictionary& dict,
            const phaseInterface& interface
        );


    //- Destructor
    virtual ~interfaceSurfaceTensionModel();


    // Selectors

        static autoPtr<interfaceSurfaceTensionModel> New
        (
            const dictionary& dict,
            const phaseInterface& interface,
            const bool outer=true
        );


    // Member Functions

        //- Surface tension
        virtual tmp<volScalarField> sigma() const = 0;

        //- Surface tension for a patch
        virtual tmp<scalarField> sigma(const label patchi) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
