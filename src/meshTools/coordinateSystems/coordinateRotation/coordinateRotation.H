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
    Foam::coordinateRotation

Description
    Abstract base class for coordinate rotation

    \verbatim
    coordinateRotation
    {
        type        axesRotation
        e1          (1 0 0);
        e2          (0 1 0);
    }
    \endverbatim

    Types of coordinateRotation:
      -# axesRotation
      -# STARCDRotation
      -# cylindrical
      -# EulerCoordinateRotation

SourceFiles
    coordinateRotation.C
    coordinateRotationNew.C

\*---------------------------------------------------------------------------*/

#ifndef coordinateRotation_H
#define coordinateRotation_H

#include "primitives/Vector/vector/vector.H"
#include "primitives/Tensor/tensor/tensor.H"
#include "fields/Fields/tensorField/tensorField.H"
#include "db/dictionary/dictionary.H"
#include "db/runTimeSelection/construction/runTimeSelectionTables.H"
#include "db/objectRegistry/objectRegistry.H"
#include "meshes/polyMesh/polyMesh.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                     Class coordinateRotation Declaration
\*---------------------------------------------------------------------------*/

class coordinateRotation
{
protected:

    // Protected member functions

        //- Transform the vector as if it is a diagonal tensor
        symmTensor transformVectorDiagTensor
        (
            const tensor&,
            const vector&
        ) const;


public:


    //- Runtime type information
    TypeName("coordinateRotation");


    // Declare run-time constructor selection table
    // for constructors with dictionary
    declareRunTimeSelectionTable
    (
        autoPtr,
        coordinateRotation,
        dictionary,
        (
            const dictionary& dict
        ),
        (dict)
    );

    // Declare run-time constructor selection table
    // for constructors with dictionary and list of points
    declareRunTimeSelectionTable
    (
        autoPtr,
        coordinateRotation,
        points,
        (
            const dictionary& dict, const UList<vector>& points
        ),
        (dict, points)
    );


    // Constructors

        //- Construct and return a clone
        virtual autoPtr<coordinateRotation> clone() const = 0;


    // Selectors

        //- Select constructed from dictionary and list of points
        static autoPtr<coordinateRotation> New
        (
            const dictionary& dict, const UList<vector>& points
        );

        //- Select constructed from dictionary
        static autoPtr<coordinateRotation> New
        (
            const dictionary& dict
        );


    //- Destructor
    virtual ~coordinateRotation()
    {}


    // Member Functions

        //- Update the rotation for a list of points
        virtual void updatePoints(const UList<vector>& points) = 0;

        //- Return local-to-global transformation tensor
        virtual const tensor& R() const = 0;

        //- Return local Cartesian x-axis
        virtual const vector e1() const = 0;

        //- Return local Cartesian y-axis
        virtual const vector e2() const = 0;

        //- Return local Cartesian z-axis
        virtual const vector e3() const = 0;

        //- Return true if the rotation tensor is uniform
        virtual bool uniform() const
        {
            return true;
        }

        //- Transform vector using transformation tensor
        virtual vector transform(const vector& v) const = 0;

        //- Transform vectorField using transformation tensor field
        virtual tmp<vectorField> transform(const vectorField& vf) const = 0;

        //- Inverse transform vector using transformation tensor
        virtual vector invTransform(const vector& v) const = 0;

        //- Inverse transform vectorField using transformation tensor field
        virtual tmp<vectorField> invTransform(const vectorField& vf) const = 0;

        //- Transform tensor using transformation tensorField
        virtual tensor transform
        (
            const vector& p,
            const tensor& t
        ) const = 0;

        //- Transform tensor field using transformation tensorField
        virtual tmp<tensorField> transform
        (
            const tensorField& tf
        ) const = 0;

        //- Transform diagTensor masquerading as a vector using transformation
        //  tensor and return symmTensor
        virtual symmTensor transformDiagTensor
        (
            const vector& p,
            const vector& v
        ) const = 0;

        //- Transform diagTensorField masquerading as a vectorField
        //  using transformation tensorField and return symmTensorField
        virtual tmp<symmTensorField> transformDiagTensor
        (
            const vectorField& vf
        ) const = 0;


    // Write

            //- Write
            virtual void write(Ostream&) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
