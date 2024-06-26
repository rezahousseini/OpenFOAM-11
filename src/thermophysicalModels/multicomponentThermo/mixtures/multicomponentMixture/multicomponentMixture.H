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

Class
    Foam::multicomponentMixture

Description
    Foam::multicomponentMixture

SourceFiles
    multicomponentMixture.C

\*---------------------------------------------------------------------------*/

#ifndef multicomponentMixture_H
#define multicomponentMixture_H

#include "mixtures/basicSpecieMixture/basicSpecieMixture.H"
#include "containers/HashTables/HashPtrTable/HashPtrTable.H"
#include "specieElement/specieElement.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class multicomponentMixture Declaration
\*---------------------------------------------------------------------------*/

template<class ThermoType>
class multicomponentMixture
:
    public basicSpecieMixture
{

public:

    //- The type of thermodynamics this mixture is instantiated for
    typedef ThermoType thermoType;


private:

    // Private Data

        //- List of specie thermo
        PtrList<ThermoType> specieThermos_;

        //- Table of species composition
        List<List<specieElement>> specieCompositions_;


    // Private Member Functions

        //- Read the species data from the given dictionary and return
        PtrList<ThermoType> readSpeciesData(const dictionary& thermoDict) const;

        //- Read the species composition from the given dictionary and return
        List<List<specieElement>> readSpeciesComposition
        (
            const dictionary& thermoDict
        ) const;


public:

    // Constructors

        //- Construct from dictionary, mesh and phase name
        multicomponentMixture(const dictionary&, const fvMesh&, const word&);

        //- Disallow default bitwise copy construction
        multicomponentMixture
        (
            const multicomponentMixture<ThermoType>&
        ) = delete;


    //- Destructor
    virtual ~multicomponentMixture()
    {}


    // Member Functions

        //- Return the raw specie thermodynamic data
        inline const PtrList<ThermoType>& specieThermos() const
        {
            return specieThermos_;
        }

        //- Read dictionary
        void read(const dictionary&);

        //- Return thermo based on index
        inline const ThermoType& specieThermo(const label speciei) const
        {
            return specieThermos_[speciei];
        }

        //- Return composition based on index
        const List<specieElement>& specieComposition
        (
            const label speciei
        ) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
    #include "mixtures/multicomponentMixture/multicomponentMixture.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
