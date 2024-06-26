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
    Foam::fv::LeastSquaresVectors

Description
    Least-squares gradient scheme vectors

See also
    Foam::fv::LeastSquaresGrad

SourceFiles
    LeastSquaresVectors.C

\*---------------------------------------------------------------------------*/

#ifndef LeastSquaresVectors_H
#define LeastSquaresVectors_H

#include "fvMesh/extendedStencil/cellToCell/extendedCentredCellToCellStencil.H"
#include "meshes/meshObjects/DemandDrivenMeshObject.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace fv
{

/*---------------------------------------------------------------------------*\
                     Class LeastSquaresVectors Declaration
\*---------------------------------------------------------------------------*/

template<class Stencil>
class LeastSquaresVectors
:
    public DemandDrivenMeshObject
    <
        fvMesh,
        MoveableMeshObject,
        LeastSquaresVectors<Stencil>
    >
{
    // Private Data

        //- Least-squares gradient vectors
        List<List<vector>> vectors_;


    // Private Member Functions

        //- Calculate Least-squares gradient vectors
        void calcLeastSquaresVectors();


protected:

    friend class DemandDrivenMeshObject
    <
        fvMesh,
        MoveableMeshObject,
        LeastSquaresVectors<Stencil>
    >;

    // Protected Constructors

        //- Construct given an fvMesh and the minimum determinant criterion
        LeastSquaresVectors
        (
            const fvMesh&
        );


public:

    // Declare name of the class and its debug switch
    TypeName("LeastSquaresVectors");


    //- Destructor
    virtual ~LeastSquaresVectors();


    // Member Functions

        //- Return reference to the stencil
        const extendedCentredCellToCellStencil& stencil() const
        {
            return Stencil::New(this->mesh());
        }

        //- Return reference to the least square vectors
        const List<List<vector>>& vectors() const
        {
            return vectors_;
        }

        //- Update the least square vectors when the mesh moves
        virtual bool movePoints();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace fv

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
    #include "finiteVolume/gradSchemes/LeastSquaresGrad/LeastSquaresVectors.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
