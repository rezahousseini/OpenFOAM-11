/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2019-2023 OpenFOAM Foundation
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
    Foam::fv::volumeFractionSource

Description
    This fvModel adds transport terms into the equations to account for the
    presence of a constant volume fraction. The volume fraction is read from
    constant/alpha.<volumePhase>, where <volumePhase> is given as a parameter
    to the fvModel. Both advective and diffusive terms are added, and the
    resulting solution is time-accurate. The flux and velocity are treated as
    superficial.

    This can be used to represent the effect of porous media that are caused
    purely by the reduction in volume of the fluid phase; i.e., additional
    blockage, and changes to transport and diffusion rates. It does not
    represent losses or transfers with the porous media. That requires separate
    sub-modelling.

Usage
    \table
        Property    | Description                        | Req'd? | Default
        phi         | Name of the flux field             | no     | phi
        rho         | Name of the density field          | no     | rho
        U           | Name of the velocity field         | no     | U
        volumePhase | Name of the phase associated with the volume fraction \\
                                                         | yes    |
    \endtable

    Example specification:
    \verbatim
    volumeFractionSource1
    {
        type        volumeFractionSource;

        phi         phi;
        rho         rho;
        U           U;

        volumePhase solid;
    }
    \endverbatim

SourceFiles
    volumeFractionSource.C

\*---------------------------------------------------------------------------*/

#ifndef volumeFractionSource_H
#define volumeFractionSource_H

#include "cfdTools/general/fvModels/fvModel.H"
#include "fields/surfaceFields/surfaceFields.H"
#include "fields/volFields/volFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace fv
{

/*---------------------------------------------------------------------------*\
                    Class volumeFractionSource Declaration
\*---------------------------------------------------------------------------*/

class volumeFractionSource
:
    public fvModel
{
    // Private Member Data

        //- The name of the flux field
        word phiName_;

        //- The name of the density field
        word rhoName_;

        //- The name of the velocity field
        word UName_;

        //- The name of the volume fraction phase
        word volumePhaseName_;


    // Private Member Functions

        //- Non-virtual read
        void readCoeffs();

        //- Get the volume fraction field
        const volScalarField& volumeAlpha() const;

        //- Get the diffusivity for a given field
        tmp<volScalarField> D(const word& fieldName) const;


        // Sources

            //- Add source terms to an equation
            template<class Type, class AlphaFieldType>
            void addGeneralSup
            (
                const AlphaFieldType& alpha,
                fvMatrix<Type>&,
                const word& fieldName
            ) const;

            //- Add a source term to an equation
            template<class Type, class AlphaFieldType>
            void addAlphaSupType
            (
                const AlphaFieldType& alpha,
                fvMatrix<Type>& eqn,
                const word& fieldName
            ) const;

            //- Add a source term to a scalar equation
            template<class AlphaFieldType>
            void addAlphaSupType
            (
                const AlphaFieldType& alpha,
                fvMatrix<scalar>& eqn,
                const word& fieldName
            ) const;

            //- Add a source term to a vector equation
            template<class AlphaFieldType>
            void addAlphaSupType
            (
                const AlphaFieldType& alpha,
                fvMatrix<vector>& eqn,
                const word& fieldName
            ) const;

            //- Add a source term to an equation
            template<class Type>
            void addSupType(fvMatrix<Type>& eqn, const word& fieldName) const;

            //- Add a source term to a compressible equation
            template<class Type>
            void addSupType
            (
                const volScalarField& rho,
                fvMatrix<Type>& eqn,
                const word& fieldName
            ) const;

            //- Add a source term to a phase equation
            template<class Type>
            void addSupType
            (
                const volScalarField& alpha,
                const volScalarField& rho,
                fvMatrix<Type>& eqn,
                const word& fieldName
            ) const;




public:

    //- Runtime type information
    TypeName("volumeFractionSource");


    // Constructors

        //- Construct from components
        volumeFractionSource
        (
            const word& name,
            const word& modelType,
            const fvMesh& mesh,
            const dictionary& dict
        );

        //- Disallow default bitwise copy construction
        volumeFractionSource(const volumeFractionSource&) = delete;


    //- Destructor
    virtual ~volumeFractionSource();


    // Member Functions

        // Checks

            //- Return true if the fvModel adds a source term to the given
            //  field's transport equation
            virtual bool addsSupToField(const word& fieldName) const;

            //- Return the list of fields for which the fvModel adds source term
            //  to the transport equation
            virtual wordList addSupFields() const;


        // Sources

            //- Add a source term to an equation
            FOR_ALL_FIELD_TYPES(DEFINE_FV_MODEL_ADD_SUP);

            //- Add a source term to a compressible equation
            FOR_ALL_FIELD_TYPES(DEFINE_FV_MODEL_ADD_RHO_SUP);

            //- Add a source term to a phase equation
            FOR_ALL_FIELD_TYPES(DEFINE_FV_MODEL_ADD_ALPHA_RHO_SUP);


        // Mesh changes

            //- Update for mesh motion
            virtual bool movePoints();

            //- Update topology using the given map
            virtual void topoChange(const polyTopoChangeMap&);

            //- Update from another mesh using the given map
            virtual void mapMesh(const polyMeshMap&);

            //- Redistribute or update using the given distribution map
            virtual void distribute(const polyDistributionMap&);


        // IO

            //- Read dictionary
            virtual bool read(const dictionary& dict);


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const volumeFractionSource&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace fv
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
