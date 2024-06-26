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
    Foam::twoPhaseMixture

Description
    Class to represent a mixture of two phases

SourceFiles
    twoPhaseMixture.C

\*---------------------------------------------------------------------------*/

#ifndef twoPhaseMixture_H
#define twoPhaseMixture_H

#include "db/IOobjects/IOdictionary/IOdictionary.H"
#include "fields/volFields/volFields.H"
#include "twoPhases.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                       Class twoPhaseMixture Declaration
\*---------------------------------------------------------------------------*/

class twoPhaseMixture
:
    public IOdictionary,
    virtual public twoPhases
{
    // Private data

        word phase1Name_;

        word phase2Name_;

        volScalarField alpha1_;

        volScalarField alpha2_;


    // Private Member Functions

        static typeIOobject<IOdictionary> readPhasePropertiesDict
        (
            const objectRegistry& obr
        );


public:

    TypeName("twoPhaseMixture");


    // Constructors

        //- Construct from components
        twoPhaseMixture(const fvMesh& mesh);


    //- Destructor
    ~twoPhaseMixture()
    {}


    // Member Functions

        const word& phase1Name() const
        {
            return phase1Name_;
        }

        const word& phase2Name() const
        {
            return phase2Name_;
        }

        //- Return the phase-fraction of phase 1
        const volScalarField& alpha1() const
        {
            return alpha1_;
        }

        //- Return the phase-fraction of phase 1
        volScalarField& alpha1()
        {
            return alpha1_;
        }

        //- Return the phase-fraction of phase 2
        const volScalarField& alpha2() const
        {
            return alpha2_;
        }

        //- Return the phase-fraction of phase 2
        volScalarField& alpha2()
        {
            return alpha2_;
        }

        //- Return the mixture density
        virtual const volScalarField& rho() const = 0;

        //- Interface fraction in a cell
        tmp<volScalarField::Internal> interfaceFraction() const;

        //- Correct the mixture properties
        virtual void correct() = 0;

        //- Read base phaseProperties dictionary
        virtual bool read() = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
