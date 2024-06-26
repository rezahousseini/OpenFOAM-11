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

#include "submodels/Momentum/PatchInteractionModel/StandardWallInteraction/StandardWallInteraction.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class CloudType>
Foam::StandardWallInteraction<CloudType>::StandardWallInteraction
(
    const dictionary& dict,
    CloudType& cloud
)
:
    PatchInteractionModel<CloudType>(dict, cloud, typeName),
    interactionType_
    (
        this->wordToInteractionType(this->coeffDict().lookup("type"))
    ),
    e_(0),
    mu_(0),
    nEscape_(0),
    massEscape_(0),
    nStick_(0),
    massStick_(0)
{
    switch (interactionType_)
    {
        case PatchInteractionModel<CloudType>::itOther:
        {
            FatalErrorInFunction
                << "Unknown patch interaction type "
                << this->coeffDict().template lookup<word>("type")
                << ". Valid types are:"
                << PatchInteractionModel<CloudType>::interactionTypeNames_
                << nl << exit(FatalError);

            break;
        }

        case PatchInteractionModel<CloudType>::itRebound:
        {
            e_ = this->coeffDict().template lookupOrDefault<scalar>("e", 1);
            mu_ = this->coeffDict().template lookupOrDefault<scalar>("mu", 0);

            break;
        }
        default:

        {}
    }
}


template<class CloudType>
Foam::StandardWallInteraction<CloudType>::StandardWallInteraction
(
    const StandardWallInteraction<CloudType>& pim
)
:
    PatchInteractionModel<CloudType>(pim),
    interactionType_(pim.interactionType_),
    e_(pim.e_),
    mu_(pim.mu_),
    nEscape_(pim.nEscape_),
    massEscape_(pim.massEscape_),
    nStick_(pim.nStick_),
    massStick_(pim.massStick_)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

template<class CloudType>
Foam::StandardWallInteraction<CloudType>::~StandardWallInteraction()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class CloudType>
bool Foam::StandardWallInteraction<CloudType>::correct
(
    typename CloudType::parcelType& p,
    const polyPatch& pp,
    bool& keepParticle
)
{
    if (!isA<wallPolyPatch>(pp))
    {
        return false;
    }

    switch (interactionType_)
    {
        case PatchInteractionModel<CloudType>::itNone:
        {
            return false;
        }

        case PatchInteractionModel<CloudType>::itEscape:
        {
            keepParticle = false;
            p.moving() = false;
            p.U() = Zero;
            nEscape_++;
            massEscape_ += p.mass()*p.nParticle();

            return true;
        }

        case PatchInteractionModel<CloudType>::itStick:
        {
            keepParticle = true;
            p.moving() = false;
            p.U() = Zero;
            nStick_++;

            return true;
        }

        case PatchInteractionModel<CloudType>::itRebound:
        {
            keepParticle = true;
            p.moving() = true;

            vector nw, Up;
            this->owner().patchData(p, pp, nw, Up);

            // Make motion relative to patch velocity
            p.U() -= Up;

            const scalar Un = p.U() & nw;
            const vector Ut = p.U() - Un*nw;

            if (Un > 0)
            {
                p.U() -= (1 + e_)*Un*nw;
            }

            p.U() -= mu_*Ut;

            // Return velocity to global space
            p.U() += Up;

            return true;
        }

        default:
        {
            return false;
        }
    }
}


template<class CloudType>
void Foam::StandardWallInteraction<CloudType>::info(Ostream& os)
{
    label npe0 = this->template getBaseProperty<scalar>("nEscape");
    label npe = npe0 + returnReduce(nEscape_, sumOp<label>());

    scalar mpe0 = this->template getBaseProperty<scalar>("massEscape");
    scalar mpe = mpe0 + returnReduce(massEscape_, sumOp<scalar>());

    label nps0 = this->template getBaseProperty<scalar>("nStick");
    label nps = nps0 + returnReduce(nStick_, sumOp<label>());

    scalar mps0 = this->template getBaseProperty<scalar>("massStick");
    scalar mps = mps0 + returnReduce(massStick_, sumOp<scalar>());

    os  << "    Parcel fate (number, mass)" << nl
        << "      - escape                      = " << npe << ", " << mpe << nl
        << "      - stick                       = " << nps << ", " << mps << nl;

    if (this->writeTime())
    {
        this->setModelProperty("nEscape", npe);
        this->setModelProperty("massEscape", mpe);
        this->setModelProperty("nStick", nps);
        this->setModelProperty("massStick", mps);
    }
}


// ************************************************************************* //
