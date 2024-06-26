/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2016-2023 OpenFOAM Foundation
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

#include "diameterModels/IATE/IATEsources/wallBoiling/IATEwallBoiling.H"
#include "derivedFvPatchFields/alphatWallBoilingWallFunction/alphatWallBoilingWallFunctionFvPatchScalarField.H"
#include "finiteVolume/fvm/fvmSup.H"
#include "db/runTimeSelection/construction/addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace diameterModels
{
namespace IATEsources
{
    defineTypeNameAndDebug(wallBoiling, 0);
    addToRunTimeSelectionTable(IATEsource, wallBoiling, dictionary);
}
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::diameterModels::IATEsources::wallBoiling::wallBoiling
(
    const IATE& iate,
    const dictionary& dict
)
:
    IATEsource(iate)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::fvScalarMatrix>
Foam::diameterModels::IATEsources::wallBoiling::R
(
    const volScalarField& alphai,
    volScalarField& kappai
) const
{
    volScalarField::Internal R
    (
        IOobject
        (
            typedName("R"),
            phase().time().name(),
            phase().mesh()
        ),
        phase().mesh(),
        dimensionedScalar(dimless/dimTime, 0)
    );

    volScalarField::Internal Rdk
    (
        IOobject
        (
            typedName("Rdk"),
            phase().time().name(),
            phase().mesh()
        ),
        phase().mesh(),
        dimensionedScalar(kappai.dimensions()/dimTime, 0)
    );

    const volScalarField& alphat =
        phase().mesh().lookupObject<volScalarField>
        (
            IOobject::groupName("alphat", otherPhase().name())
        );

    const volScalarField::Boundary& alphatBf = alphat.boundaryField();

    const scalarField& rho = phase().rho();

    typedef compressible::alphatWallBoilingWallFunctionFvPatchScalarField
        alphatWallBoilingWallFunction;

    forAll(alphatBf, patchi)
    {
        if (isA<alphatWallBoilingWallFunction>(alphatBf[patchi]))
        {
            const alphatWallBoilingWallFunction& alphatw =
                refCast<const alphatWallBoilingWallFunction>(alphatBf[patchi]);

            const scalarField& dmdt = alphatw.dmdtf();
            const scalarField& dDep = alphatw.dDeparture();

            const labelList& faceCells = alphatw.patch().faceCells();

            forAll(alphatw, facei)
            {
                if (dmdt[facei] > small)
                {
                    const label faceCelli = faceCells[facei];
                    R[faceCelli] =
                        dmdt[facei]/(alphai[faceCelli]*rho[faceCelli]);
                    Rdk[faceCelli] = R[faceCelli]*(6.0/dDep[facei]);
                }
            }
        }
    }

    return Rdk - fvm::Sp(R, kappai);
}


// ************************************************************************* //
