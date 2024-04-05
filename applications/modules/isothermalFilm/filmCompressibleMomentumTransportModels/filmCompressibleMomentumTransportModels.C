/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2023 OpenFOAM Foundation
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

#include "filmCompressibleMomentumTransportModels/makeFilmCompressibleMomentumTransportModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    defineRunTimeSelectionTable
    (
        filmCompressibleMomentumTransportModel,
        dictionary
    );

    defineNamedTemplateTypeNameAndDebug
    (
        laminarfilmCompressibleMomentumTransportModel,
        0
    );

    defineTemplateRunTimeSelectionTable
    (
        laminarfilmCompressibleMomentumTransportModel,
        dictionary
    );

    addToRunTimeSelectionTable
    (
        filmCompressibleMomentumTransportModel,
        laminarfilmCompressibleMomentumTransportModel,
        dictionary
    );
}


// -------------------------------------------------------------------------- //
// Laminar models
// -------------------------------------------------------------------------- //

#include "laminar/Stokes/Stokes.H"
makeLaminarModel(Stokes);

#include "laminar/generalisedNewtonian/generalisedNewtonian.H"
makeLaminarModel(generalisedNewtonian);

#include "laminar/lambdaThixotropic/lambdaThixotropic.H"
makeLaminarModel(lambdaThixotropic);

#include "laminar/Maxwell/Maxwell.H"
makeLaminarModel(Maxwell);

#include "laminar/Giesekus/Giesekus.H"
makeLaminarModel(Giesekus);

#include "laminar/PTT/PTT.H"
makeLaminarModel(PTT);


// ************************************************************************* //
