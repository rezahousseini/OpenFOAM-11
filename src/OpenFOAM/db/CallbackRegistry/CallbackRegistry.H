/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2020 OpenFOAM Foundation
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
    Foam::CallbackRegistry

Description
    Base class with which callbacks are registered.

    Derive from this class and extend by adding the appropriate callback
    functions that loop and call the callback functions for each entry.

SourceFiles
    CallbackRegistry.C

\*---------------------------------------------------------------------------*/

#ifndef CallbackRegistry_H
#define CallbackRegistry_H

#include "containers/LinkedLists/user/UIDLList.H"
#include "db/typeInfo/className.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of classes

template<class CallbackType>
class Callback;


/*---------------------------------------------------------------------------*\
                      Class CallbackRegistry Declaration
\*---------------------------------------------------------------------------*/

TemplateName(CallbackRegistry);


/*---------------------------------------------------------------------------*\
                      Class CallbackRegistry Declaration
\*---------------------------------------------------------------------------*/

template<class CallbackType>
class CallbackRegistry
:
    public CallbackRegistryName,
    public UIDLList<CallbackType>
{

public:

    // Constructors

        //- Construct null
        CallbackRegistry();

        //- Disallow default bitwise copy construction
        CallbackRegistry(const CallbackRegistry&) = delete;


    //- Destructor
    virtual ~CallbackRegistry();


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const CallbackRegistry&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
    #include "db/CallbackRegistry/CallbackRegistry.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
