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
    Foam::skewCorrectionVectors

Description
    Skew-correction vectors for the skewness-corrected interpolation scheme

SourceFiles
    skewCorrectionVectors.C

\*---------------------------------------------------------------------------*/

#ifndef skewCorrectionVectors_H
#define skewCorrectionVectors_H

#include "meshes/meshObjects/DemandDrivenMeshObject.H"
#include "fvMesh/fvMesh.H"
#include "fields/surfaceFields/surfaceFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class fvMesh;

/*---------------------------------------------------------------------------*\
                    Class skewCorrectionVectors Declaration
\*---------------------------------------------------------------------------*/

class skewCorrectionVectors
:
    public DemandDrivenMeshObject
    <
        fvMesh,
        MoveableMeshObject,
        skewCorrectionVectors
    >
{
    // Private Data

        //- Is mesh skew
        bool skew_;

        //- Skew correction vectors
        surfaceVectorField skewCorrectionVectors_;

        //- Calculate skewness correction vectors
        void calcSkewCorrectionVectors();


protected:

    friend class DemandDrivenMeshObject
    <
        fvMesh,
        MoveableMeshObject,
        skewCorrectionVectors
    >;

    // Protected Constructors

        explicit skewCorrectionVectors(const fvMesh& mesh);


public:

    TypeName("skewCorrectionVectors");


    //- Destructor
    virtual ~skewCorrectionVectors();


    // Member Functions

        //- Return whether mesh is skew or not
        bool skew() const
        {
            return skew_;
        }

        //- Return reference to skew vectors array
        const surfaceVectorField& operator()() const
        {
            return skewCorrectionVectors_;
        }

        //- Update the correction vectors when the mesh moves
        virtual bool movePoints();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
