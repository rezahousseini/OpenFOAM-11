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
    Foam::TimePaths

Description
    A class for addressing time paths without using the Time class.

SourceFiles
    TimePaths.C

\*---------------------------------------------------------------------------*/

#ifndef TimePaths_H
#define TimePaths_H

#include "primitives/strings/fileName/fileName.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                          Class TimePaths Declaration
\*---------------------------------------------------------------------------*/

class TimePaths
{
    // Private Data

        bool processorCase_;
        const fileName rootPath_;
        fileName globalCaseName_;
        const fileName case_;

public:

    // Static Data

        static const word systemName;
        static const word constantName;


    // Constructors

        //- Construct given database name, rootPath and casePath
        TimePaths
        (
            const fileName& rootPath,
            const fileName& caseName
        );


        //- Construct given database name, rootPath and casePath
        TimePaths
        (
            const bool processorCase,
            const fileName& rootPath,
            const fileName& globalCaseName,
            const fileName& caseName
        );


    // Member Functions

            //- Return true if this is a processor case
            bool processorCase() const
            {
                return processorCase_;
            }

            //- Return root path
            const fileName& rootPath() const
            {
                return rootPath_;
            }

            //- Return global case name
            const fileName& globalCaseName() const
            {
                return globalCaseName_;
            }

            //- Return case name
            const fileName& caseName() const
            {
                return case_;
            }

            //- Return system name
            static const word& system()
            {
                return systemName;
            }

            //- Return system name for the case
            //  which for parallel runs returns ../system()
            fileName caseSystem() const;

            //- Return constant name
            static const word& constant()
            {
                return constantName;
            }

            //- Return constant name for the case
            //  which for parallel runs returns ../constant()
            fileName caseConstant() const;

            //- Return the global path
            fileName globalPath() const
            {
                return rootPath()/globalCaseName();
            }

            //- Return path
            fileName path() const
            {
                return rootPath()/caseName();
            }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
