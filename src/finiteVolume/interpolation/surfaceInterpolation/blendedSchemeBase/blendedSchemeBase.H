/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2013-2022 OpenFOAM Foundation
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
    Foam::blendedSchemeBase

Description
    Base class for blended schemes to provide access to the blending factor
    surface field

\*---------------------------------------------------------------------------*/

#ifndef blendedSchemeBase_H
#define blendedSchemeBase_H

#include "db/typeInfo/className.H"
#include "memory/tmp/tmp.H"
#include "fields/surfaceFields/surfaceFieldsFwd.H"
#include "fields/volFields/volFieldsFwd.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

TemplateName(blendedSchemeBase);

/*---------------------------------------------------------------------------*\
                      Class blendedSchemeBase Declaration
\*---------------------------------------------------------------------------*/

template<class Type>
class blendedSchemeBase
:
    public blendedSchemeBaseName
{

public:

    //- Constructor
    blendedSchemeBase()
    {}

    //- Destructor
    virtual ~blendedSchemeBase()
    {}


    // Member Functions

        //- Return the face-based blending factor
        virtual tmp<surfaceScalarField> blendingFactor
        (
             const VolField<Type>& vf
        ) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
