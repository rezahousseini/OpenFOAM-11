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
    Foam::motionDirectionalDiffusivity

Description
    MotionDirectional finite volume mesh motion diffusivity.

SourceFiles
    motionDirectionalDiffusivity.C

\*---------------------------------------------------------------------------*/

#ifndef motionDirectionalDiffusivity_H
#define motionDirectionalDiffusivity_H

#include "motionDiffusivity/motionDiffusivity/motionDiffusivity.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                Class motionDirectionalDiffusivity Declaration
\*---------------------------------------------------------------------------*/

class motionDirectionalDiffusivity
:
    public motionDiffusivity
{
    // Private Data

        vector diffusivityVector_;


public:

    //- Runtime type information
    TypeName("motionDirectional");


    // Constructors

        //- Construct for the given fvMesh and data Istream
        motionDirectionalDiffusivity(const fvMesh& mesh, Istream& mdData);

        //- Disallow default bitwise copy construction
        motionDirectionalDiffusivity
        (
            const motionDirectionalDiffusivity&
        ) = delete;


    //- Destructor
    virtual ~motionDirectionalDiffusivity();


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const motionDirectionalDiffusivity&) = delete;

        //- Return diffusivity field
        virtual tmp<surfaceScalarField> operator()() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
