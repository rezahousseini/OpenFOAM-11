/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2023 OpenFOAM Foundation
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
    Foam::surfMesh

Description
    A surface mesh consisting of general polygon faces.

SourceFiles
    surfMesh.C
    surfMeshClear.C
    surfMeshIO.C

\*---------------------------------------------------------------------------*/

#ifndef surfMesh_H
#define surfMesh_H

#include "surfaceRegistry/surfaceRegistry.H"
#include "MeshedSurfaceAllocator/MeshedSurfaceIOAllocator.H"
#include "meshes/primitiveMesh/PrimitivePatch/PrimitivePatch.H"
#include "fields/Fields/Field/SubField.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

template<class Face> class MeshedSurface;

/*---------------------------------------------------------------------------*\
                          Class surfMesh Declaration
\*---------------------------------------------------------------------------*/

class surfMesh
:
    public surfaceRegistry,
    private MeshedSurfaceIOAllocator,
    public PrimitivePatch<UList<face>, SubField<point>>
{
    // Friendship

        template<class Face> friend class MeshedSurface;

        template<class Face> friend class UnsortedMeshedSurface;


public:

    // Public data types

        //- Enumeration defining the state of the mesh after a read update.
        //  Used for post-processing applications, where the mesh
        //  needs to update based on the files written in time directories
        enum readUpdateState
        {
            UNCHANGED,
            POINTS_MOVED,
            TOPO_CHANGE,
            TOPO_PATCH_CHANGE
        };


private:

    // Private Typedefs

        typedef MeshedSurfaceIOAllocator Allocator;

        typedef PrimitivePatch<UList<face>, SubField<point>> MeshReference;


protected:

    // Protected Member Functions

        //- Non-const access to global points
        pointField& storedPoints()
        {
            return Allocator::storedIOPoints();
        }

        //- Non-const access to the faces
        faceList& storedFaces()
        {
            return Allocator::storedIOFaces();
        }

        //- Non-const access to the zones
        surfZoneList& storedZones()
        {
            return Allocator::storedIOZones();
        }

        //- Update references to storedFaces
        virtual void updateFacesRef();

        //- Update references to storedPoints
        virtual void updatePointsRef();

        //- Update references to storedPoints/storedFaces
        virtual void updateRefs();


public:

    // Public Typedefs

        typedef surfMesh Mesh;

        //- Placeholder only, but do not remove - it is needed for GeoMesh
        typedef bool BoundaryMesh;


    // Public Static Data

        //- The mesh sub-directory name (normally "surfMesh")
        static word meshSubDir;


    //- Runtime type information
    TypeName("surfMesh");


    // Constructors

        //- Construct from IOobject, with alternative surface name
        explicit surfMesh(const IOobject&, const word& surfName="");

        //- Construct by transferring components (points, faces) without zones.
        //  surfZones are added using addZones() member function
        surfMesh
        (
            const IOobject&,
            pointField&&,
            faceList&&,
            const word& surfName=""
        );

        //- Construct copy/move from MeshedSurface
        surfMesh
        (
            const IOobject&,
            MeshedSurface<face>&& surf,
            const word& surfName=""
        );

        //- Disallow default bitwise copy construction
        surfMesh(const surfMesh&) = delete;


    //- Destructor
    virtual ~surfMesh();


    // Member Functions

        // Database

            //- Return the local mesh directory (dbDir()/meshSubDir)
            fileName meshDir() const;

            //- Return the current instance directory for points
            //  Used in the construction of geometric mesh data dependent
            //  on points
            const fileName& pointsInstance() const;

            //- Return the current instance directory for faces
            const fileName& facesInstance() const;

            //- Set the instance for mesh files
            void setInstance(const fileName&);


        // Access

            //- Return the number of raw points
            virtual label nPoints() const;

            //- Return the number of raw faces
            virtual label nFaces() const;

            //- Return number of faces
            virtual label size() const
            {
                return nFaces();
            }

            //- Return points
            virtual const pointField& points() const;

            //- Return faces
            virtual const faceList& faces() const;

            //- Return surface zones
            virtual const surfZoneList& surfZones() const
            {
                return Allocator::storedIOZones();
            }

            //- Check the surface zone definitions
            void checkZones();

            //- Add surface zones
            void addZones
            (
                const List<surfZone>&,
                const bool validate = true
            );

            //- Update the mesh based on the mesh files saved in
            //  time directories
            virtual readUpdateState readUpdate();

            //- Update the mesh corresponding to given map

            //- Remove surface zones
            void removeZones();

            //- Reset mesh primitive data.
            void resetPrimitives
            (
                pointField&& points,
                faceList&& faces,
                surfZoneList&& zones,
                const bool validate = true
            );


            //- Transfer the contents of the argument and annul the argument
            void transfer(MeshedSurface<face>&);


        //- Avoid masking the normal objectRegistry write
        using surfaceRegistry::write;

        //- Write to file
        static void write(const fileName&, const surfMesh&);

        //- Write to file
        void write(const fileName&);


        //  Storage management

            //- Clear geometry
            void clearGeom();

            //- Clear addressing
            void clearAddressing();

            //- Clear all geometry and addressing unnecessary for CFD
            void clearOut();

            //- Clear primitive data (points, faces and cells)
            void clearPrimitives();

            //- Remove all files from mesh instance
            void removeFiles(const fileName& instanceDir) const;

            //- Remove all files from mesh instance()
            void removeFiles() const;


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const surfMesh&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
