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

\*---------------------------------------------------------------------------*/

#include "containers/LinkedLists/accessTypes/ULPtrList/ULPtrList.H"
#include "db/IOstreams/IOstreams/Ostream.H"

// * * * * * * * * * * * * * * * Ostream Operators * * * * * * * * * * * * * //

template<class LListBase, class T>
Foam::Ostream& Foam::operator<<(Ostream& os, const ULPtrList<LListBase, T>& lst)
{
    // Write size
    os << nl << lst.size();

    // Write beginning of contents
    os << nl << token::BEGIN_LIST << nl;

    // Write contents
    for
    (
        typename ULPtrList<LListBase, T>::const_iterator iter = lst.begin();
        iter != lst.end();
        ++iter
    )
    {
        os << iter() << nl;
    }

    // Write end of contents
    os << token::END_LIST;

    // Check state of IOstream
    os.check("Ostream& operator<<(Ostream&, const ULPtrList<LListBase, T>&)");

    return os;
}

// ************************************************************************* //
