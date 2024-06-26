/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2018-2022 OpenFOAM Foundation
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

#include "cfdTools/general/solutionControl/pimpleControl/pimpleLoop/pimpleLoop.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(pimpleLoop, 0);
}


// * * * * * * * * * * * * Protected Member Functions  * * * * * * * * * * * //

bool Foam::pimpleLoop::read()
{
    nCorr_ =
        control_.dict().lookupOrDefault<label>("nOuterCorrectors", 1);

    return true;
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::pimpleLoop::pimpleLoop(const solutionControl& control)
:
    control_(control),
    nCorr_(-1),
    corr_(0),
    converged_(false)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::pimpleLoop::~pimpleLoop()
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

bool Foam::pimpleLoop::loop(correctorConvergenceControl& convergence)
{
    read();

    // Handle quit conditions first
    {
        // If converged on the last iteration then end the correction loop
        if (converged_)
        {
            Info<< control_.algorithmName() << ": Converged in " << corr_
                << " iterations" << endl;

            corr_ = 0;
            converged_ = false;

            return false;
        }

        // If all corrections have been completed then end the correction loop
        if (corr_ >= nCorr_)
        {
            if (convergence.hasCorrResidualControls() && nCorr_ > 1)
            {
                Info<< control_.algorithmName() << ": Not converged within "
                    << nCorr_ << " iterations" << endl;
            }

            corr_ = 0;
            converged_ = false;

            return false;
        }
    }

    // If we reached here, we are doing another loop
    corr_++;

    // Set up the next loop
    {
        // If convergence has been reached then set the flag so that the loop
        // exits next time around
        if (!firstIter() && convergence.corrCriteriaSatisfied())
        {
            Info<< control_.algorithmName() << ": Converged " << nl
                << control_.algorithmSpace() << "  Doing final iteration"
                << endl;
            converged_ = true;
        }

        // Set up the next iteration by storing the index of the solution to
        // check the convergence of
        if (firstIter())
        {
            convergence.resetCorrSolveIndex();
        }
        else
        {
            convergence.updateCorrSolveIndex();
        }

        // Print the number of the iteration about to take place
        if (nCorr_ > 1)
        {
            Info<< control_.algorithmName() << ": Iteration " << corr_
                << endl;
        }

        return true;
    }
}


// ************************************************************************* //
