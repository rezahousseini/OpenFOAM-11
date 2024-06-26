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

#include "fft/writeEk.H"
#include "fft/fft.H"
#include "fft/kShellIntegration.H"
#include "fields/volFields/volFields.H"
#include "sampledSet/writers/setWriter.H"
#include "db/functionObjects/writeFile/writeFile.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

void writeEk
(
    const volVectorField& U,
    const Kmesh& K
)
{
    const Pair<scalarField> Ek
    (
        kShellIntegration
        (
            fft::forwardTransform
            (
                ReComplexField(U.primitiveField()),
                K.nn()
            ),
            K
        )
    );

    autoPtr<setWriter> writer
    (
        setWriter::New(U.time().controlDict().lookup("graphFormat"))
    );

    writer->write
    (
        U.time().path()
       /functionObjects::writeFile::outputPrefix
       /"graphs"
       /U.time().name(),
        "Ek",
        coordSet(true,"k", Ek.first()),
        "E(k)",
        Ek.second()
    );
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
