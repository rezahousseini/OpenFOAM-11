/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2019 OpenFOAM Foundation
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
    Foam::energyScalingFunctions::sigmoid

Description


SourceFiles
    sigmoid.C

\*---------------------------------------------------------------------------*/

#ifndef sigmoid_H
#define sigmoid_H

#include "energyScalingFunction/basic/energyScalingFunction.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace energyScalingFunctions
{

/*---------------------------------------------------------------------------*\
                           Class sigmoid Declaration
\*---------------------------------------------------------------------------*/

class sigmoid
:
    public energyScalingFunction
{
    // Private Data

        dictionary sigmoidCoeffs_;

        scalar shift_;
        scalar scale_;


    // Private Member Functions

        scalar sigmoidScale
        (
            const scalar r,
            const scalar shift,
            const scalar scale
        ) const;


public:

    //- Runtime type information
    TypeName("sigmoid");


    // Constructors

        //- Construct from components
        sigmoid
        (
            const word& name,
            const dictionary& energyScalingFunctionProperties,
            const pairPotential& pairPot
        );


    //- Destructor
    ~sigmoid()
    {}


    // Member Functions

        void scaleEnergy(scalar& e, const scalar r) const;

        //- Read dictionary
        bool read(const dictionary& energyScalingFunctionProperties);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace energyScalingFunctions
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
