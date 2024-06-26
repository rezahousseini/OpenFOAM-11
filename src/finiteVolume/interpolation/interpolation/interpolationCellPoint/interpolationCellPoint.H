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
    Foam::interpolationCellPoint

Description
    Given cell centre values and point (vertex) values decompose into
    tetrahedra and linear interpolate within them.

\*---------------------------------------------------------------------------*/

#ifndef interpolationCellPoint_H
#define interpolationCellPoint_H

#include "interpolation/interpolation/interpolationVolPointInterpolation/interpolationVolPointInterpolation.H"
#include "interpolation/interpolation/interpolationCellPoint/cellPointWeight/cellPointWeight.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                   Class interpolationCellPoint Declaration
\*---------------------------------------------------------------------------*/

template<class Type>
class interpolationCellPoint
:
    public fieldInterpolation<Type, interpolationCellPoint<Type>>,
    public interpolationVolPointInterpolation<Type>
{
public:

    //- Runtime type information
    TypeName("cellPoint");


    // Constructors

        //- Construct from components
        interpolationCellPoint
        (
            const VolField<Type>& psi
        );

        //- Copy construct
        interpolationCellPoint
        (
            const interpolationCellPoint<Type>& i
        );

        //- Construct from components
        interpolationCellPoint
        (
            const VolField<Type>& psi,
            tmp<PointField<Type>> psip
        );

        //- Clone
        virtual autoPtr<interpolation<Type>> clone() const
        {
            return autoPtr<interpolation<Type>>
            (
                new interpolationCellPoint<Type>(*this)
            );
        }


    // Member Functions

        //- Inherit interpolate from interpolation
        using interpolation<Type>::interpolate;

        //- Interpolate field for the given cellPointWeight
        inline Type interpolate(const cellPointWeight& cpw) const;

        //- Interpolate field to the given point in the given cell
        inline Type interpolate
        (
            const vector& position,
            const label celli,
            const label facei = -1
        ) const;

        //- Interpolate field to the given coordinates in the tetrahedron
        //  defined by the given indices.
        inline Type interpolate
        (
            const barycentric& coordinates,
            const tetIndices& tetIs,
            const label facei = -1
        ) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "interpolation/interpolation/interpolationCellPoint/interpolationCellPointI.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
    #include "interpolation/interpolation/interpolationCellPoint/interpolationCellPoint.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
