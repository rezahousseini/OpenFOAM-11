/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2022 OpenFOAM Foundation
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

#include "mixtures/egrMixture/egrMixture.H"
#include "mixtures/homogeneousMixture/homogeneousMixture.H"
#include "mixtures/inhomogeneousMixture/inhomogeneousMixture.H"
#include "mixtures/veryInhomogeneousMixture/veryInhomogeneousMixture.H"

#include "psiThermo/psiThermo.H"
#include "psiuMulticomponentThermo/psiuMulticomponentThermo.H"
#include "psiuMulticomponentThermo/heheuPsiThermo.H"

#include "include/forAbsoluteGases.H"
#include "makeMulticomponentThermo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    forAbsoluteGases(makePsiuMulticomponentThermos, egrMixture);
    forAbsoluteGases(makePsiuMulticomponentThermos, homogeneousMixture);
    forAbsoluteGases(makePsiuMulticomponentThermos, inhomogeneousMixture);
    forAbsoluteGases(makePsiuMulticomponentThermos, veryInhomogeneousMixture);
}

// ************************************************************************* //
