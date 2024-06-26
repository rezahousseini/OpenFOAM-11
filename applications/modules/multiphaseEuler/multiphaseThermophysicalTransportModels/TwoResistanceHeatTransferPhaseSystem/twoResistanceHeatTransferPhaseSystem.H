/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2020-2023 OpenFOAM Foundation
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

Class
    Foam::twoResistanceHeatTransferPhaseSystem

SourceFiles
    twoResistanceHeatTransferPhaseSystem.C

\*---------------------------------------------------------------------------*/

#ifndef twoResistanceHeatTransferPhaseSystem_H
#define twoResistanceHeatTransferPhaseSystem_H

#include "containers/NamedEnum/NamedEnum.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
         Class twoResistanceHeatTransferPhaseSystem Declaration
\*---------------------------------------------------------------------------*/

class twoResistanceHeatTransferPhaseSystem
{
public:

    //- Enumeration for the form of the latent heat transfer
    enum class latentHeatTransfer
    {
        heat,
        mass
    };

    //- Names of the forms of the latent heat transfer
    static const NamedEnum<latentHeatTransfer, 2> latentHeatTransferNames_;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
