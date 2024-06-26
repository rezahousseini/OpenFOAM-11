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
    Foam::heSolidThermo

Description
    Energy for a solid mixture

SourceFiles
    heSolidThermo.C

\*---------------------------------------------------------------------------*/

#ifndef heSolidThermo_H
#define heSolidThermo_H

#include "heThermo/heThermo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                        Class heSolidThermo Declaration
\*---------------------------------------------------------------------------*/

template<class BasicSolidThermo, class MixtureType>
class heSolidThermo
:
    public heThermo<BasicSolidThermo, MixtureType>
{
protected:

    // Protected data

        //- Anisotropic thermal conductivity [W/m/K]
        volVectorField Kappa_;


    // Private Member Functions

        //- Calculate the thermo variables
        void calculate();


public:

    //- Runtime type information
    TypeName("heSolidThermo");


    // Constructors

        //- Construct from mesh and phase name
        heSolidThermo
        (
            const fvMesh&,
            const word& phaseName
        );

        //- Disallow default bitwise copy construction
        heSolidThermo
        (
            const heSolidThermo<BasicSolidThermo, MixtureType>&
        ) = delete;


    //- Destructor
    virtual ~heSolidThermo();


    // Member Functions

        //- Update properties
        virtual void correct();

        //- Return true if thermal conductivity is isotropic
        virtual bool isotropic() const
        {
            return MixtureType::thermoType::isotropic;
        }

        //- Anisotropic thermal conductivity [W/m/K]
        virtual const volVectorField& Kappa() const;


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=
        (
            const heSolidThermo<BasicSolidThermo, MixtureType>&
        ) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
    #include "solidThermo/heSolidThermo.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
