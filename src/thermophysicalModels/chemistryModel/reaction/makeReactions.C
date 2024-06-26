/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2012-2023 OpenFOAM Foundation
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

#include "reaction/makeReaction.H"

#include "reaction/reactionRate/ArrheniusReactionRate/ArrheniusReactionRate.H"
#include "reaction/reactionRate/LandauTellerReactionRate/LandauTellerReactionRate.H"
#include "reaction/reactionRate/thirdBodyArrheniusReactionRate/thirdBodyArrheniusReactionRate.H"

#include "reaction/reactionRate/JanevReactionRate/JanevReactionRate.H"
#include "reaction/reactionRate/powerSeries/powerSeriesReactionRate.H"

#include "reaction/reactionRate/FallOffReactionRate/FallOffReactionRate.H"
#include "reaction/reactionRate/ChemicallyActivatedReactionRate/ChemicallyActivatedReactionRate.H"
#include "reaction/reactionRate/fallOffFunctions/LindemannFallOffFunction/LindemannFallOffFunction.H"
#include "reaction/reactionRate/fallOffFunctions/SRIFallOffFunction/SRIFallOffFunction.H"
#include "reaction/reactionRate/fallOffFunctions/TroeFallOffFunction/TroeFallOffFunction.H"

#include "reaction/reactionRate/MichaelisMenten/MichaelisMentenReactionRate.H"
#include "reaction/reactionRate/LangmuirHinshelwood/LangmuirHinshelwoodReactionRate.H"
#include "reaction/reactionRate/fluxLimitedLangmuirHinshelwoodReactionRate/fluxLimitedLangmuirHinshelwoodReactionRate.H"
#include "reaction/reactionRate/surfaceArrheniusReactionRate/surfaceArrheniusReactionRate.H"

#include "include/forGases.H"
#include "include/forLiquids.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

template<>
const char* const Foam::Tuple2<Foam::word, Foam::scalar>::typeName
(
    "Tuple2<word,scalar>"
);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    forCoeffGases(defineReaction, nullArg);
    forCoeffLiquids(defineReaction, nullArg);

    // Irreversible/reversible/non-equilibrium-reversible reactions
    forCoeffGases(makeIRNReactions, ArrheniusReactionRate);
    forCoeffLiquids(makeIRNReactions, ArrheniusReactionRate);
    forCoeffGases(makeIRNReactions, LandauTellerReactionRate);
    forCoeffLiquids(makeIRNReactions, LandauTellerReactionRate);
    forCoeffGases(makeIRNReactions, thirdBodyArrheniusReactionRate);
    forCoeffLiquids(makeIRNReactions, thirdBodyArrheniusReactionRate);

    // Irreversible/reversible reactions
    forCoeffGases(makeIRReactions, JanevReactionRate);
    forCoeffLiquids(makeIRReactions, JanevReactionRate);
    forCoeffGases(makeIRReactions, powerSeriesReactionRate);
    forCoeffLiquids(makeIRReactions, powerSeriesReactionRate);

    // Irreversible/reversible fall-off reactions
    forCoeffGases
    (
        makeIRTemplate2Reactions,
        FallOffReactionRate,
        ArrheniusReactionRate,
        LindemannFallOffFunction
    );
    forCoeffLiquids
    (
        makeIRTemplate2Reactions,
        FallOffReactionRate,
        ArrheniusReactionRate,
        LindemannFallOffFunction
    );
    forCoeffGases
    (
        makeIRTemplate2Reactions,
        FallOffReactionRate,
        ArrheniusReactionRate,
        TroeFallOffFunction
    );
    forCoeffLiquids
    (
        makeIRTemplate2Reactions,
        FallOffReactionRate,
        ArrheniusReactionRate,
        TroeFallOffFunction
    );
    forCoeffGases
    (
        makeIRTemplate2Reactions,
        FallOffReactionRate,
        ArrheniusReactionRate,
        SRIFallOffFunction
    );
    forCoeffLiquids
    (
        makeIRTemplate2Reactions,
        FallOffReactionRate,
        ArrheniusReactionRate,
        SRIFallOffFunction
    );

    // Irreversible/reversible chemically activated reactions
    forCoeffGases
    (
        makeIRTemplate2Reactions,
        ChemicallyActivatedReactionRate,
        ArrheniusReactionRate,
        LindemannFallOffFunction
    );
    forCoeffLiquids
    (
        makeIRTemplate2Reactions,
        ChemicallyActivatedReactionRate,
        ArrheniusReactionRate,
        LindemannFallOffFunction
    );
    forCoeffGases
    (
        makeIRTemplate2Reactions,
        ChemicallyActivatedReactionRate,
        ArrheniusReactionRate,
        TroeFallOffFunction
    );
    forCoeffLiquids
    (
        makeIRTemplate2Reactions,
        ChemicallyActivatedReactionRate,
        ArrheniusReactionRate,
        TroeFallOffFunction
    );
    forCoeffGases
    (
        makeIRTemplate2Reactions,
        ChemicallyActivatedReactionRate,
        ArrheniusReactionRate,
        SRIFallOffFunction
    );
    forCoeffLiquids
    (
        makeIRTemplate2Reactions,
        ChemicallyActivatedReactionRate,
        ArrheniusReactionRate,
        SRIFallOffFunction
    );

    // Michaelis-Menten Reactions
    forCoeffLiquids(makeIReactions, MichaelisMentenReactionRate);

    // Langmuir-Hinshelwood Reactions
    forCoeffGases(makeIRReactions, LangmuirHinshelwoodReactionRate);
    forCoeffLiquids(makeIRReactions, LangmuirHinshelwoodReactionRate);

    // Flux-limited Langmuir-Hinshelwood Reactions
    forCoeffGases
    (
        makeGeneralReaction,
        IrreversibleReaction,
        fluxLimitedLangmuirHinshelwoodReactionRate
    );

    // Surface-Arrhenius Reactions
    forCoeffGases
    (
        makeGeneralReaction,
        IrreversibleReaction,
        surfaceArrheniusReactionRate
    );
    forCoeffLiquids
    (
        makeGeneralReaction,
        IrreversibleReaction,
        surfaceArrheniusReactionRate
    );
}


// ************************************************************************* //
