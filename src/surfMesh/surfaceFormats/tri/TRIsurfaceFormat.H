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
    Foam::fileFormats::TRIsurfaceFormat

Description
    Provide a means of reading/writing .tri format.

    Note:
        For efficiency, the zones are sorted before creating the faces.
        The class is thus derived from MeshedSurface.

SourceFiles
    TRIsurfaceFormat.C

\*---------------------------------------------------------------------------*/

#ifndef TRIsurfaceFormat_H
#define TRIsurfaceFormat_H

#include "surfaceFormats/tri/TRIsurfaceFormatCore.H"
#include "MeshedSurface/MeshedSurface.H"
#include "MeshedSurfaceProxy/MeshedSurfaceProxy.H"
#include "UnsortedMeshedSurface/UnsortedMeshedSurface.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace fileFormats
{

/*---------------------------------------------------------------------------*\
                      Class TRIsurfaceFormat Declaration
\*---------------------------------------------------------------------------*/

template<class Face>
class TRIsurfaceFormat
:
    public MeshedSurface<Face>
{
    // Private Member Functions

        static inline void writeShell
        (
            Ostream&,
            const pointField&,
            const Face&,
            const label zoneI
        );


public:

    // Constructors

        //- Construct from file name
        TRIsurfaceFormat(const fileName&);

        //- Disallow default bitwise copy construction
        TRIsurfaceFormat(const TRIsurfaceFormat<Face>&) = delete;


    // Selectors

        //- Read file and return surface
        static autoPtr<MeshedSurface<Face>> New(const fileName& name)
        {
            return autoPtr<MeshedSurface<Face>>
            (
                new TRIsurfaceFormat<Face>(name)
            );
        }


    //- Destructor
    virtual ~TRIsurfaceFormat()
    {}


    // Member Functions

        //- Write surface mesh components by proxy
        static void write(const fileName&, const MeshedSurfaceProxy<Face>&);

        //- Write UnsortedMeshedSurface,
        //  by default the output is not sorted by zones
        static void write(const fileName&, const UnsortedMeshedSurface<Face>&);

        //- Read from file
        virtual bool read(const fileName&);

        //- Write object
        virtual void write(const fileName& name) const
        {
            write(name, MeshedSurfaceProxy<Face>(*this));
        }


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const TRIsurfaceFormat<Face>&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace fileFormats
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
    #include "surfaceFormats/tri/TRIsurfaceFormat.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
