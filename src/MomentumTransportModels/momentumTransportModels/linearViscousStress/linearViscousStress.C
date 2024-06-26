/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2013-2023 OpenFOAM Foundation
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

#include "linearViscousStress/linearViscousStress.H"
#include "finiteVolume/fvc/fvcGrad.H"
#include "finiteVolume/fvc/fvcDiv.H"
#include "finiteVolume/fvm/fvmLaplacian.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class BasicMomentumTransportModel>
Foam::linearViscousStress<BasicMomentumTransportModel>::linearViscousStress
(
    const word& modelName,
    const alphaField& alpha,
    const rhoField& rho,
    const volVectorField& U,
    const surfaceScalarField& alphaRhoPhi,
    const surfaceScalarField& phi,
    const viscosity& viscosity
)
:
    BasicMomentumTransportModel
    (
        modelName,
        alpha,
        rho,
        U,
        alphaRhoPhi,
        phi,
        viscosity
    )
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class BasicMomentumTransportModel>
bool Foam::linearViscousStress<BasicMomentumTransportModel>::read()
{
    return BasicMomentumTransportModel::read();
}


template<class BasicMomentumTransportModel>
Foam::tmp<Foam::volSymmTensorField>
Foam::linearViscousStress<BasicMomentumTransportModel>::devTau() const
{
    return volSymmTensorField::New
    (
        this->groupName("devTau"),
        (-(this->alpha_*this->rho_*this->nuEff()))
       *dev(twoSymm(fvc::grad(this->U_)))
    );
}


template<class BasicMomentumTransportModel>
Foam::tmp<Foam::fvVectorMatrix>
Foam::linearViscousStress<BasicMomentumTransportModel>::divDevTau
(
    volVectorField& U
) const
{
    const fvVectorMatrix divDevTauCorr
    (
        this->divDevTauCorr
        (
            -(this->alpha_*this->rho_*this->nuEff())*dev2(T(fvc::grad(U))),
            U
        )
    );

    return
    (
        divDevTauCorr
      - fvm::laplacian(this->alpha_*this->rho_*this->nuEff(), U)
    );
}


template<class BasicMomentumTransportModel>
Foam::tmp<Foam::fvVectorMatrix>
Foam::linearViscousStress<BasicMomentumTransportModel>::divDevTau
(
    const volScalarField& rho,
    volVectorField& U
) const
{
    return
    (
      - fvm::laplacian(this->alpha_*rho*this->nuEff(), U)
      + this->divDevTauCorr
        (
            -(this->alpha_*rho*this->nuEff())*dev2(T(fvc::grad(U))),
            U
        )
    );
}


template<class BasicMomentumTransportModel>
void Foam::linearViscousStress<BasicMomentumTransportModel>::correct()
{
    BasicMomentumTransportModel::correct();
}


// ************************************************************************* //
