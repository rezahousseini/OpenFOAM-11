/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2015-2022 OpenFOAM Foundation
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
    Foam::wallDist

Description
    Interface to run-time selectable methods to calculate the distance-to-wall
    and normal-to-wall fields.

    Example of the wallDist specification in fvSchemes:
    \verbatim
        wallDist
        {
            method meshWave;

            // Optional entry enabling the calculation
            // of the normal-to-wall field
            nRequired false;
        }
    \endverbatim

See also
    Foam::patchDistMethod::meshWave
    Foam::patchDistMethod::Poisson
    Foam::patchDistMethod::advectionDiffusion

SourceFiles
    wallDist.C

\*---------------------------------------------------------------------------*/

#ifndef wallDist_H
#define wallDist_H

#include "meshes/meshObjects/DemandDrivenMeshObject.H"
#include "fvMesh/wallDist/patchDistMethods/patchDistMethod/patchDistMethod.H"
#include "fields/volFields/volFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                          Class wallDist Declaration
\*---------------------------------------------------------------------------*/

class wallDist
:
    public DemandDrivenMeshObject<fvMesh, UpdateableMeshObject, wallDist>
{
    // Private Data

        //- Set of patch IDs
        const labelHashSet patchIDs_;

        //- Name for the patch set, e.g. "wall"
        const word patchTypeName_;

        //- Run-time selected method to generate the distance-to-wall field
        mutable autoPtr<patchDistMethod> pdm_;

        //- Distance-to-wall field
        mutable volScalarField y_;

        //- Flag to indicate if the distance-to-wall field is required
        mutable bool nRequired_;

        //- Normal-to-wall field
        mutable autoPtr<volVectorField> n_;


    // Private Member Functions

        //- Construct the normal-to-wall field as required
        void constructn() const;


protected:

    friend class DemandDrivenMeshObject
    <
        fvMesh,
        UpdateableMeshObject,
        wallDist
    >;

    // Protected Constructors

        //- Construct from mesh and optional patch type name
        wallDist
        (
            const fvMesh& mesh,
            const word& patchTypeName = "wall"
        );

        //- Construct from mesh, patch IDs and optional patch type name
        wallDist
        (
            const fvMesh& mesh,
            const labelHashSet& patchIDs,
            const word& patchTypeName = "patch"
        );


public:

    // Declare name of the class and its debug switch
    ClassName("wallDist");


    // Constructors

        //- Disallow default bitwise copy construction
        wallDist(const wallDist&) = delete;


    //- Destructor
    virtual ~wallDist();


    // Member Functions

        //- Return the patchIDs
        const labelHashSet& patchIDs() const
        {
            return patchIDs_;
        }

        //- Return reference to cached distance-to-wall field
        const volScalarField& y() const
        {
            return y_;
        }

        //- Return reference to cached normal-to-wall field
        const volVectorField& n() const;

        //- Update the y-field when the mesh moves
        virtual bool movePoints();

        //- Update the y-field when the mesh changes
        virtual void topoChange(const polyTopoChangeMap&);

        //- Update from another mesh using the given map
        virtual void mapMesh(const polyMeshMap&);

        //- Redistribute or update using the given distribution map
        virtual void distribute(const polyDistributionMap&);


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const wallDist&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
