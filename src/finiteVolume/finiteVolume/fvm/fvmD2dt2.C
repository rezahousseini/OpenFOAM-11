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

#include "fields/volFields/volFields.H"
#include "fields/surfaceFields/surfaceFields.H"
#include "fvMatrices/fvMatrix/fvMatrix.H"
#include "finiteVolume/d2dt2Schemes/d2dt2Scheme/d2dt2Scheme.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace fvm
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

template<class Type>
tmp<fvMatrix<Type>>
d2dt2
(
    const VolField<Type>& vf
)
{
    return fv::d2dt2Scheme<Type>::New
    (
        vf.mesh(),
        vf.mesh().schemes().d2dt2("d2dt2(" + vf.name() + ')')
    ).ref().fvmD2dt2(vf);
}


template<class Type>
tmp<fvMatrix<Type>>
d2dt2
(
    const dimensionedScalar& rho,
    const VolField<Type>& vf
)
{
    return fv::d2dt2Scheme<Type>::New
    (
        vf.mesh(),
        vf.mesh().schemes().d2dt2("d2dt2(" + rho.name() + ',' + vf.name() + ')')
    ).ref().fvmD2dt2(rho, vf);
}


template<class Type>
tmp<fvMatrix<Type>>
d2dt2
(
    const volScalarField& rho,
    const VolField<Type>& vf
)
{
    return fv::d2dt2Scheme<Type>::New
    (
        vf.mesh(),
        vf.mesh().schemes().d2dt2("d2dt2(" + rho.name() + ',' + vf.name() + ')')
    ).ref().fvmD2dt2(rho, vf);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace fvm

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
