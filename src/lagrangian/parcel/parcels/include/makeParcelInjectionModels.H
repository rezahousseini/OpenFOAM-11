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

#ifndef makeParcelInjectionModels_H
#define makeParcelInjectionModels_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "submodels/Momentum/InjectionModel/CellZoneInjection/CellZoneInjection.H"
#include "submodels/Momentum/InjectionModel/ConeInjection/ConeInjection.H"
#include "submodels/Momentum/InjectionModel/FieldActivatedInjection/FieldActivatedInjection.H"
#include "submodels/Momentum/InjectionModel/MomentumLookupTableInjection/MomentumLookupTableInjection.H"
#include "submodels/Momentum/InjectionModel/ManualInjection/ManualInjection.H"
#include "submodels/Momentum/InjectionModel/NoInjection/NoInjection.H"
#include "submodels/Momentum/InjectionModel/PatchInjection/PatchInjection.H"
#include "submodels/Momentum/InjectionModel/PatchFlowRateInjection/PatchFlowRateInjection.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define makeParcelInjectionModels(CloudType)                                   \
                                                                               \
    makeInjectionModel(CloudType);                                             \
                                                                               \
    makeInjectionModelType(CellZoneInjection, CloudType);                      \
    makeInjectionModelType(ConeInjection, CloudType);                          \
    makeInjectionModelType(FieldActivatedInjection, CloudType);                \
    makeInjectionModelType(MomentumLookupTableInjection, CloudType);           \
    makeInjectionModelType(ManualInjection, CloudType);                        \
    makeInjectionModelType(NoInjection, CloudType);                            \
    makeInjectionModelType(PatchInjection, CloudType);                         \
    makeInjectionModelType(PatchFlowRateInjection, CloudType);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
