/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2014-2020 OpenFOAM Foundation
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
    Foam::DistortedSphereDragForce

Description
    Drag model for distorted spheres.

    Reference:
    \verbatim
        Liu, A. B., Mather, D., & Reitz, R. D. (1993).
        Modeling the effects of drop drag and breakup on fuel sprays.
        SAE Transactions, 83-95.
    \endverbatim

\*---------------------------------------------------------------------------*/

#ifndef DistortedSphereDragForce_H
#define DistortedSphereDragForce_H

#include "submodels/Momentum/ParticleForces/ParticleForce/ParticleForce.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                  Class DistortedSphereDragForce Declaration
\*---------------------------------------------------------------------------*/

template<class CloudType>
class DistortedSphereDragForce
:
    public ParticleForce<CloudType>
{
public:

    //- Runtime type information
    TypeName("distortedSphereDrag");


    // Constructors

        //- Construct from mesh
        DistortedSphereDragForce
        (
            CloudType& owner,
            const fvMesh& mesh,
            const dictionary& dict
        );

        //- Construct copy
        DistortedSphereDragForce(const DistortedSphereDragForce<CloudType>& df);

        //- Construct and return a clone
        virtual autoPtr<ParticleForce<CloudType>> clone() const
        {
            return autoPtr<ParticleForce<CloudType>>
            (
                new DistortedSphereDragForce<CloudType>(*this)
            );
        }


    //- Destructor
    virtual ~DistortedSphereDragForce();


    // Member Functions

        // Evaluation

            //- Calculate the coupled force
            virtual forceSuSp calcCoupled
            (
                const typename CloudType::parcelType& p,
                const typename CloudType::parcelType::trackingData& td,
                const scalar dt,
                const scalar mass,
                const scalar Re,
                const scalar muc
            ) const;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
    #include "submodels/Momentum/ParticleForces/Drag/DistortedSphereDrag/DistortedSphereDragForce.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
