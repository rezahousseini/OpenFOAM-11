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

Description
    Map Surface internal field on topology change.  This is a partial
    template specialisation, see MapGeometricFields.

\*---------------------------------------------------------------------------*/

#ifndef MapFvSurfaceField_H
#define MapFvSurfaceField_H

#include "fields/GeometricFields/GeometricField/MapGeometricFields.H"
#include "surfaceMesh/surfaceMesh.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

template<class Type, class MeshMapper>
class MapInternalField<Type, MeshMapper, surfaceMesh>
{
public:

    MapInternalField()
    {}

    void operator()
    (
        DimensionedField<Type, surfaceMesh>& field,
        const MeshMapper& mapper
    ) const;
};


template<class Type, class MeshMapper>
void MapInternalField<Type, MeshMapper, surfaceMesh>::operator()
(
    DimensionedField<Type, surfaceMesh>& field,
    const MeshMapper& mapper
) const
{
    if (field.size() != mapper.surfaceMap().sizeBeforeMapping())
    {
        FatalErrorInFunction
           << "Incompatible size before mapping.  Field size: " << field.size()
           << " map size: " << mapper.surfaceMap().sizeBeforeMapping()
           << abort(FatalError);
    }

    mapper.surfaceMap()(field, field);

    // Flip the flux
    if (isFlux(field))
    {
        const labelList flipFaces = mapper.surfaceMap().flipFaceFlux().toc();

        forAll(flipFaces, i)
        {
            if (flipFaces[i] < field.size())
            {
                field[flipFaces[i]] *= -1.0;
            }
        }
    }
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
