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
    Foam::mappedFilmSurfacePointPatch

SourceFiles
    mappedFilmSurfacePointPatch.C

\*---------------------------------------------------------------------------*/

#ifndef mappedFilmSurfacePointPatch_H
#define mappedFilmSurfacePointPatch_H

#include "patches/filmSurface/filmSurfacePointPatch/filmSurfacePointPatch.H"
#include "patches/mappedFilmSurface/mappedFilmSurfacePolyPatch/mappedFilmSurfacePolyPatch.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class mappedFilmSurfacePointPatch Declaration
\*---------------------------------------------------------------------------*/

class mappedFilmSurfacePointPatch
:
    public filmSurfacePointPatch
{

public:

    //- Runtime type information
    TypeName(mappedFilmSurfacePolyPatch::typeName_());


    // Constructors

        //- Construct from polyPatch
        mappedFilmSurfacePointPatch
        (
            const polyPatch& patch,
            const pointBoundaryMesh& bm
        )
        :
            filmSurfacePointPatch(patch, bm)
        {}
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
