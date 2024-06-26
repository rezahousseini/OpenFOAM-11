/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2021 OpenFOAM Foundation
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

\*---------------------------------------------------------------------------*/

#ifndef ZoneIDs_H
#define ZoneIDs_H

#include "meshes/Identifiers/DynamicID/DynamicID.H"

#include "meshes/polyMesh/zones/MeshZones/meshCellZonesFwd.H"
#include "meshes/polyMesh/zones/MeshZones/meshFaceZonesFwd.H"
#include "meshes/polyMesh/zones/MeshZones/meshPointZonesFwd.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

    //- Foam::cellZoneID
    typedef DynamicID<meshCellZones> cellZoneID;

    //- Foam::faceZoneID
    typedef DynamicID<meshFaceZones> faceZoneID;

    //- Foam::pointZoneID
    typedef DynamicID<meshPointZones> pointZoneID;

}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
