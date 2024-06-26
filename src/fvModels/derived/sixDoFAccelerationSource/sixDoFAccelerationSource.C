/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2015-2023 OpenFOAM Foundation
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

#include "derived/sixDoFAccelerationSource/sixDoFAccelerationSource.H"
#include "fvMatrices/fvMatrices.H"
#include "fields/GeometricFields/geometricOneField/geometricOneField.H"
#include "db/runTimeSelection/construction/addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace fv
{
    defineTypeNameAndDebug(sixDoFAccelerationSource, 0);
    addToRunTimeSelectionTable
    (
        fvModel,
        sixDoFAccelerationSource,
        dictionary
    );
}
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "primitives/functions/Function1/None/None.H"
#include "primitives/functions/Function1/Constant/Constant.H"
#include "primitives/functions/Function1/Uniform/Uniform.H"
#include "primitives/functions/Function1/Zero/ZeroConstant.H"
#include "primitives/functions/Function1/One/OneConstant.H"
#include "primitives/functions/Function1/Polynomial1/Polynomial1.H"
#include "primitives/functions/Function1/Sine/Sine.H"
#include "primitives/functions/Function1/Square/Square.H"
#include "primitives/functions/Function1/Table/Table.H"
#include "primitives/functions/Function1/UniformTable1/UniformTable1.H"
#include "primitives/functions/Function1/NonUniformTable1/NonUniformTable1.H"
#include "primitives/functions/Function1/Table/TableReader/Embedded/EmbeddedTableReader.H"
#include "primitives/functions/Function1/Table/TableReader/Foam/FoamTableReader.H"
#include "primitives/functions/Function1/Scale/Scale.H"
#include "primitives/functions/Function1/Coded/CodedFunction1.H"

typedef Foam::fv::sixDoFAccelerationSource::accelerationVectors avType;

template<>
const char* const avType::vsType::typeName = "vectorVector";

template<>
const char* const avType::vsType::componentNames[] = {"x", "y", "z"};

template<>
const avType avType::vsType::vsType::zero(avType::uniform(vector::uniform(0)));

template<>
const avType avType::vsType::one(avType::uniform(vector::uniform(1)));

template<>
const avType avType::vsType::max(avType::uniform(vector::uniform(vGreat)));

template<>
const avType avType::vsType::min(avType::uniform(vector::uniform(-vGreat)));

template<>
const avType avType::vsType::rootMax
(
    avType::uniform(vector::uniform(rootVGreat))
);

template<>
const avType avType::vsType::rootMin
(
    avType::uniform(vector::uniform(-rootVGreat))
);

namespace Foam
{

    makeFunction1s(avType, nullArg);

    defineTableReader(avType);
    namespace TableReaders
    {
        makeTableReader(Embedded, avType);
        makeTableReader(Foam, avType);
    }
}


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

void Foam::fv::sixDoFAccelerationSource::readCoeffs()
{
    UName_ = coeffs().lookupOrDefault<word>("U", "U");

    accelerations_.reset
    (
        Function1<accelerationVectors>::New
        (
            "accelerations",
            coeffs()
        ).ptr()
    );
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::fv::sixDoFAccelerationSource::sixDoFAccelerationSource
(
    const word& name,
    const word& modelType,
    const fvMesh& mesh,
    const dictionary& dict
)
:
    fvModel(name, modelType, mesh, dict),
    UName_(coeffs().lookupOrDefault<word>("U", "U")),
    accelerations_(nullptr),
    g_
    (
        mesh.foundObject<uniformDimensionedVectorField>("g")
      ? dimensionedVector(mesh.lookupObject<uniformDimensionedVectorField>("g"))
      : dimensionedVector("g", dimAcceleration, Zero)
    )
{
    readCoeffs();
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::wordList Foam::fv::sixDoFAccelerationSource::addSupFields() const
{
    return wordList(1, UName_);
}


void Foam::fv::sixDoFAccelerationSource::addSup
(
    fvMatrix<vector>& eqn,
    const word& fieldName
) const
{
    addForce(geometricOneField(), geometricOneField(), eqn, fieldName);
}


void Foam::fv::sixDoFAccelerationSource::addSup
(
    const volScalarField& rho,
    fvMatrix<vector>& eqn,
    const word& fieldName
) const
{
    addForce(geometricOneField(), rho, eqn, fieldName);
}


void Foam::fv::sixDoFAccelerationSource::addSup
(
    const volScalarField& alpha,
    const volScalarField& rho,
    fvMatrix<vector>& eqn,
    const word& fieldName
) const
{
    addForce(alpha, rho, eqn, fieldName);
}


bool Foam::fv::sixDoFAccelerationSource::movePoints()
{
    return true;
}


void Foam::fv::sixDoFAccelerationSource::topoChange(const polyTopoChangeMap&)
{}


void Foam::fv::sixDoFAccelerationSource::mapMesh(const polyMeshMap& map)
{}


void Foam::fv::sixDoFAccelerationSource::distribute
(
    const polyDistributionMap&
)
{}


bool Foam::fv::sixDoFAccelerationSource::read(const dictionary& dict)
{
    if (fvModel::read(dict))
    {
        readCoeffs();
        return true;
    }
    else
    {
        return false;
    }
}


// ************************************************************************* //
