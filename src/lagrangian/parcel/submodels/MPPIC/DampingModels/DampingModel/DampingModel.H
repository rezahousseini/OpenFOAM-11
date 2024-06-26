/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2013-2020 OpenFOAM Foundation
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
    Foam::DampingModel

Description
    Base class for collisional damping models.

SourceFiles
    DampingModel.C
    DampingModelNew.C

\*---------------------------------------------------------------------------*/

#ifndef DampingModel_H
#define DampingModel_H

#include "db/IOobjects/IOdictionary/IOdictionary.H"
#include "memory/autoPtr/autoPtr.H"
#include "db/runTimeSelection/construction/runTimeSelectionTables.H"
#include "submodels/CloudSubModelBase.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of classes

class TimeScaleModel;

/*---------------------------------------------------------------------------*\
                        Class DampingModel Declaration
\*---------------------------------------------------------------------------*/

template<class CloudType>
class DampingModel
:
    public CloudSubModelBase<CloudType>
{
protected:

    // Protected data

        //- Time scale model
        autoPtr<TimeScaleModel> timeScaleModel_;


public:

    //- Runtime type information
    TypeName("dampingModel");

    //- Declare runtime constructor selection table
    declareRunTimeSelectionTable
    (
        autoPtr,
        DampingModel,
        dictionary,
        (
            const dictionary& dict,
            CloudType& owner
        ),
        (dict, owner)
    );


    // Constructors

        //- Construct null from owner
        DampingModel(CloudType& owner);

        //- Construct from components
        DampingModel
        (
            const dictionary& dict,
            CloudType& owner,
            const word& type
        );

        //- Construct copy
        DampingModel(const DampingModel<CloudType>& cm);

        //- Construct and return a clone
        virtual autoPtr<DampingModel<CloudType>> clone() const = 0;


    //- Destructor
    virtual ~DampingModel();


    //- Selector
    static autoPtr<DampingModel<CloudType>> New
    (
        const dictionary& dict,
        CloudType& owner
    );


    // Member Functions

        //- Calculate the velocity correction
        virtual vector velocityCorrection
        (
            typename CloudType::parcelType& p,
            const scalar deltaT
        ) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define makeDampingModel(CloudType)                                            \
                                                                               \
    typedef Foam::CloudType::MPPICCloudType MPPICCloudType;                    \
    defineNamedTemplateTypeNameAndDebug                                        \
    (                                                                          \
        Foam::DampingModel<MPPICCloudType>,                                    \
        0                                                                      \
    );                                                                         \
                                                                               \
    namespace Foam                                                             \
    {                                                                          \
        defineTemplateRunTimeSelectionTable                                    \
        (                                                                      \
            DampingModel<MPPICCloudType>,                                      \
            dictionary                                                         \
        );                                                                     \
    }


#define makeDampingModelType(SS, CloudType)                                    \
                                                                               \
    typedef Foam::CloudType::MPPICCloudType MPPICCloudType;                    \
    defineNamedTemplateTypeNameAndDebug                                        \
        (Foam::DampingModels::SS<MPPICCloudType>, 0);                          \
                                                                               \
    Foam::DampingModel<MPPICCloudType>::                                       \
        adddictionaryConstructorToTable                                        \
        <Foam::DampingModels::SS<MPPICCloudType>>                              \
            add##SS##CloudType##MPPICCloudType##ConstructorToTable_;


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
    #include "submodels/MPPIC/DampingModels/DampingModel/DampingModel.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
