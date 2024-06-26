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
    Foam::upwindCFCCellToFaceStencilObject

Description

SourceFiles

\*---------------------------------------------------------------------------*/

#ifndef upwindCFCCellToFaceStencilObject_H
#define upwindCFCCellToFaceStencilObject_H

#include "fvMesh/extendedStencil/cellToFace/extendedUpwindCellToFaceStencil.H"
#include "fvMesh/extendedStencil/cellToFace/globalIndexStencils/CFCCellToFaceStencil.H"
#include "meshes/meshObjects/DemandDrivenMeshObject.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
              Class upwindCFCCellToFaceStencilObject Declaration
\*---------------------------------------------------------------------------*/

class upwindCFCCellToFaceStencilObject
:
    public DemandDrivenMeshObject
    <
        fvMesh,
        TopologicalMeshObject,
        upwindCFCCellToFaceStencilObject
    >,
    public extendedUpwindCellToFaceStencil
{

protected:

    friend class DemandDrivenMeshObject
    <
        fvMesh,
        TopologicalMeshObject,
        upwindCFCCellToFaceStencilObject
    >;

    // Protected Constructors

        //- Construct from uncompacted face stencil
        upwindCFCCellToFaceStencilObject
        (
            const fvMesh& mesh,
            const bool pureUpwind,
            const scalar minOpposedness
        )
        :
            DemandDrivenMeshObject
            <
                fvMesh,
                TopologicalMeshObject,
                upwindCFCCellToFaceStencilObject
            >(mesh),
            extendedUpwindCellToFaceStencil
            (
                CFCCellToFaceStencil(mesh),
                pureUpwind,
                minOpposedness
            )
        {
            if (extendedCellToFaceStencil::debug)
            {
                Info<< "Generated off-centred stencil " << type()
                    << nl << endl;
                writeStencilStats(Info, ownStencil(), ownMap());
            }
        }


public:

    TypeName("upwindCFCCellToFaceStencil");

    //- Destructor
    virtual ~upwindCFCCellToFaceStencilObject()
    {}
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
