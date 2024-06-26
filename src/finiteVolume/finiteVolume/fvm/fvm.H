/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2018 OpenFOAM Foundation
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

Namespace
    Foam::fvm

Description
    Namespace of functions to calculate implicit derivatives returning a
    matrix.

    Temporal derivatives are calculated using Euler-implicit, backward
    differencing or Crank-Nicolson. Spatial derivatives are calculated
    using Gauss' Theorem.


\*---------------------------------------------------------------------------*/

#ifndef fvm_H
#define fvm_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "finiteVolume/fvm/fvmDdt.H"
#include "finiteVolume/fvm/fvmD2dt2.H"
#include "finiteVolume/fvm/fvmDiv.H"
#include "finiteVolume/fvm/fvmLaplacian.H"
#include "finiteVolume/fvm/fvmSup.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
