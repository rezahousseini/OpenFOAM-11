/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2021 OpenFOAM Foundation
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

#include "repatchMesh/repatchPatch.H"
#include "db/dictionary/dictionary.H"
#include "db/IOstreams/IOstreams/Ostream.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::repatchPatch::repatchPatch
(
    const word& name,
    const label index,
    const label size,
    const label start,
    const word& physicalType
)
:
    patchIdentifier(name, index, physicalType),
    size_(size),
    start_(start)
{}


Foam::repatchPatch::repatchPatch
(
    const word& name,
    const dictionary& dict,
    const label index
)
:
    patchIdentifier(name, dict, index),
    size_(dict.lookup<label>("nFaces")),
    start_(dict.lookup<label>("startFace"))
{}


Foam::repatchPatch::repatchPatch(const repatchPatch& p, const label index)
:
    patchIdentifier(p.name(), index, p.physicalType()),
    size_(p.size()),
    start_(p.start())
{}


Foam::autoPtr<Foam::repatchPatch> Foam::repatchPatch::clone() const
{
    return autoPtr<repatchPatch>(new repatchPatch(*this));
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::repatchPatch::~repatchPatch()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::repatchPatch::write(Ostream& os) const
{
    patchIdentifier::write(os);
    writeEntry(os, "nFaces", size_);
    writeEntry(os, "startFace", start_);
}


// * * * * * * * * * * * * * * * Friend Operators  * * * * * * * * * * * * * //

Foam::Ostream& Foam::operator<<(Ostream& os, const repatchPatch& p)
{
    p.write(os);
    os.check("Ostream& operator<<(Ostream& f, const repatchPatch&)");
    return os;
}


// ************************************************************************* //
