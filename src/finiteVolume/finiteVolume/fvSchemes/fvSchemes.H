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
    Foam::fvSchemes

Description
    Selector class for finite volume differencing schemes.
    fvMesh is derived from fvSchemes so that all fields have access to the
    fvSchemes from the mesh reference they hold.

SourceFiles
    fvSchemes.C

\*---------------------------------------------------------------------------*/

#ifndef fvSchemes_H
#define fvSchemes_H

#include "db/IOobjects/IOdictionary/IOdictionary.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                          Class fvSchemes Declaration
\*---------------------------------------------------------------------------*/

class fvSchemes
:
    public IOdictionary
{
    // Private Data

        dictionary ddtSchemes_;
        ITstream defaultDdtScheme_;

        dictionary d2dt2Schemes_;
        ITstream defaultD2dt2Scheme_;

        dictionary interpolationSchemes_;
        ITstream defaultInterpolationScheme_;

        dictionary divSchemes_;
        ITstream defaultDivScheme_;

        dictionary gradSchemes_;
        ITstream defaultGradScheme_;

        dictionary snGradSchemes_;
        ITstream defaultSnGradScheme_;

        dictionary laplacianSchemes_;
        ITstream defaultLaplacianScheme_;

        mutable dictionary fluxRequired_;
        bool defaultFluxRequired_;

        //- Steady-state run indicator
        //  Set true if the default ddtScheme is steadyState
        bool steady_;


    // Private Member Functions

        //- Clear the dictionaries and streams before reading
        void clear();

        //- Read settings from the dictionary
        void read(const dictionary&);

        //- Filter group extensions
        word filterGroup(const word& name) const;

        //- Lookup and return scheme for name from the schemes dictionary
        //  or return defaultScheme if defined.
        //  Wildcard lookup and group extension are enabled
        ITstream& lookupScheme
        (
            const word& name,
            const dictionary& schemes,
            const ITstream& defaultScheme
        ) const;


public:

    //- Type information
    ClassName("fvSchemes");


    // Constructors

        //- Construct for objectRegistry
        fvSchemes(const objectRegistry& obr);

        //- Disallow default bitwise copy construction
        fvSchemes(const fvSchemes&) = delete;


    // Member Functions

        // Access

            const dictionary& dict() const;

            ITstream& ddt(const word& name) const;

            ITstream& d2dt2(const word& name) const;

            ITstream& interpolation(const word& name) const;

            ITstream& div(const word& name) const;

            ITstream& grad(const word& name) const;

            ITstream& snGrad(const word& name) const;

            ITstream& laplacian(const word& name) const;

            void setFluxRequired(const word& name) const;

            bool fluxRequired(const word& name) const;

            //- Return true if the default ddtScheme is steadyState
            bool steady() const
            {
                return steady_;
            }

            //- Return true if the default ddtScheme is not steadyState
            bool transient() const
            {
                return !steady_;
            }


        // Read

            //- Read the fvSchemes
            bool read();


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const fvSchemes&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
