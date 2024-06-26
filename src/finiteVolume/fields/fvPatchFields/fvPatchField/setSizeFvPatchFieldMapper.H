/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2023 OpenFOAM Foundation
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
    Foam::setSizeFvPatchFieldMapper

Description
    Set size fvPatchFieldMapper

\*---------------------------------------------------------------------------*/

#ifndef setSizeFvPatchFieldMapper_H
#define setSizeFvPatchFieldMapper_H

#include "fields/fvPatchFields/fvPatchField/fvPatchFieldMapper.H"
#include "fields/Fields/fieldMappers/setSizeFieldMapper/setSizeFieldMapper.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                  Class setSizeFvPatchFieldMapper Declaration
\*---------------------------------------------------------------------------*/

class setSizeFvPatchFieldMapper
:
    public fvPatchFieldMapper,
    public setSizeFieldMapper
{
public:

    // Constructors

        //- Construct
        setSizeFvPatchFieldMapper(const label size)
        :
            setSizeFieldMapper(size)
        {}


    //- Destructor
    virtual ~setSizeFvPatchFieldMapper()
    {}
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
