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

Description
    Attach/detach boundary mesh modifier.  This modifier takes a set of
    internal faces and converts them into boundary faces and vice versa
    based on the given activation switch.

\*---------------------------------------------------------------------------*/

#include "attachDetach/attachDetach.H"
#include "polyTopoChange/polyTopoChanger/polyTopoChanger.H"
#include "meshes/polyMesh/polyMesh.H"
#include "db/Time/Time.H"
#include "meshes/primitiveMesh/primitiveMesh.H"
#include "polyTopoChange/polyTopoChange/polyTopoChange.H"
#include "db/runTimeSelection/construction/addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(attachDetach, 0);
    addToRunTimeSelectionTable
    (
        polyMeshModifier,
        attachDetach,
        dictionary
    );
}


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

void Foam::attachDetach::checkDefinition()
{
    if
    (
        !faceZoneID_.active()
     || !masterPatchID_.active()
     || !slavePatchID_.active()
    )
    {
        FatalErrorInFunction
            << "Not all zones and patches needed in the definition "
            << "have been found.  Please check your mesh definition."
            << abort(FatalError);
    }

    const polyMesh& mesh = topoChanger().mesh();

    if (debug)
    {
        Pout<< "Attach/detach object " << name() << " :" << nl
            << "    faceZoneID:   " << faceZoneID_ << nl
            << "    masterPatchID: " << masterPatchID_ << nl
            << "    slavePatchID: " << slavePatchID_ << endl;
    }

    // Check the sizes and set up state
    if
    (
        mesh.boundaryMesh()[masterPatchID_.index()].empty()
     && mesh.boundaryMesh()[slavePatchID_.index()].empty()
    )
    {
        // Boundary is attached
        if (debug)
        {
            Pout<< "    Attached on construction" << endl;
        }

        state_ = ATTACHED;

        // Check if there are faces in the master zone
        if (mesh.faceZones()[faceZoneID_.index()].empty())
        {
            FatalErrorInFunction
                << "mesh definition."
                << abort(FatalError);
        }

        // Check that all the faces in the face zone are internal
        if (debug)
        {
            const labelList& addr = mesh.faceZones()[faceZoneID_.index()];

            DynamicList<label> bouFacesInZone(addr.size());

            forAll(addr, facei)
            {
                if (!mesh.isInternalFace(addr[facei]))
                {
                    bouFacesInZone.append(addr[facei]);
                }
            }

            if (bouFacesInZone.size())
            {
                FatalErrorInFunction
                    << "Found boundary faces in the zone defining "
                    << "attach/detach boundary "
                    << " for object " << name()
                    << " : .  This is not allowed." << nl
                    << "Boundary faces: " << bouFacesInZone
                    << abort(FatalError);
            }
        }
    }
    else
    {
        // Boundary is detached
        if (debug)
        {
            Pout<< "    Detached on construction" << endl;
        }

        state_ = DETACHED;

        // Check that the sizes of master and slave patch are identical
        // and identical to the size of the face zone
        if
        (
            (
                mesh.boundaryMesh()[masterPatchID_.index()].size()
             != mesh.boundaryMesh()[slavePatchID_.index()].size()
            )
         || (
                mesh.boundaryMesh()[masterPatchID_.index()].size()
             != mesh.faceZones()[faceZoneID_.index()].size()
            )
        )
        {
            FatalErrorInFunction
                << "Problem with sizes in mesh modifier. The face zone,"
                << " master and slave patch should have the same size"
                << " for object " << name() << ". " << nl
                << "Zone size: "
                << mesh.faceZones()[faceZoneID_.index()].size()
                << " Master patch size: "
                << mesh.boundaryMesh()[masterPatchID_.index()].size()
                << " Slave patch size: "
                << mesh.boundaryMesh()[slavePatchID_.index()].size()
                << abort(FatalError);
        }

        // Check that all the faces belong to either master or slave patch
        if (debug)
        {
            const labelList& addr = mesh.faceZones()[faceZoneID_.index()];

            DynamicList<label> zoneProblemFaces(addr.size());

            forAll(addr, facei)
            {
                label facePatch =
                    mesh.boundaryMesh().whichPatch(addr[facei]);

                if
                (
                    facePatch != masterPatchID_.index()
                 && facePatch != slavePatchID_.index()
                )
                {
                    zoneProblemFaces.append(addr[facei]);
                }
            }

            if (zoneProblemFaces.size())
            {
                FatalErrorInFunction
                    << "Found faces in the zone defining "
                    << "attach/detach boundary which do not belong to "
                    << "either master or slave patch.  "
                    << "This is not allowed." << nl
                    << "Problem faces: " << zoneProblemFaces
                    << abort(FatalError);
            }
        }
    }

    // Check that trigger times are in ascending order
    bool triggersOK = true;

    for (label i = 0; i < triggerTimes_.size() - 1; i++)
    {
        triggersOK = triggersOK && (triggerTimes_[i] < triggerTimes_[i + 1]);
    }

    if
    (
        !triggersOK
     || (triggerTimes_.empty() && !manualTrigger())
    )
    {
        FatalErrorInFunction
            << "Problem with definition of trigger times: "
            << triggerTimes_
            << abort(FatalError);
    }
}


void Foam::attachDetach::clearAddressing() const
{
    deleteDemandDrivenData(pointMatchMapPtr_);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::attachDetach::attachDetach
(
    const word& name,
    const label index,
    const polyTopoChanger& mme,
    const word& faceZoneName,
    const word& masterPatchName,
    const word& slavePatchName,
    const scalarField& triggerTimes,
    const bool manualTrigger
)
:
    polyMeshModifier(name, index, mme, true),
    faceZoneID_(faceZoneName, mme.mesh().faceZones()),
    masterPatchID_(masterPatchName, mme.mesh().boundaryMesh()),
    slavePatchID_(slavePatchName, mme.mesh().boundaryMesh()),
    triggerTimes_(triggerTimes),
    manualTrigger_(manualTrigger),
    triggerIndex_(0),
    state_(UNKNOWN),
    trigger_(false),
    pointMatchMapPtr_(nullptr)
{
    checkDefinition();
}


Foam::attachDetach::attachDetach
(
    const word& name,
    const dictionary& dict,
    const label index,
    const polyTopoChanger& mme
)
:
    polyMeshModifier(name, index, mme, Switch(dict.lookup("active"))),
    faceZoneID_
    (
        dict.lookup("faceZoneName"),
        mme.mesh().faceZones()
    ),
    masterPatchID_
    (
        dict.lookup("masterPatchName"),
        mme.mesh().boundaryMesh()
    ),
    slavePatchID_
    (
        dict.lookup("slavePatchName"),
        mme.mesh().boundaryMesh()
    ),
    triggerTimes_(dict.lookup("triggerTimes")),
    manualTrigger_(dict.lookup("manualTrigger")),
    triggerIndex_(0),
    state_(UNKNOWN),
    trigger_(false),
    pointMatchMapPtr_(nullptr)
{
    checkDefinition();
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::attachDetach::~attachDetach()
{
    clearAddressing();
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool Foam::attachDetach::setAttach() const
{
    if (!attached())
    {
        trigger_ = true;
    }
    else
    {
        trigger_ = false;
    }

    return trigger_;
}


bool Foam::attachDetach::setDetach() const
{
    if (attached())
    {
        trigger_ = true;
    }
    else
    {
        trigger_ = false;
    }

    return trigger_;
}


bool Foam::attachDetach::changeTopology() const
{
    if (manualTrigger())
    {
        if (debug)
        {
            Pout<< "bool attachDetach::changeTopology() const "
                << " for object " << name() << " : "
                << "Manual trigger" << endl;
        }

        return trigger_;
    }

    // To deal with multiple calls within the same time step, return true
    // if trigger is already set
    if (trigger_)
    {
        if (debug)
        {
            Pout<< "bool attachDetach::changeTopology() const "
                << " for object " << name() << " : "
                << "Already triggered for current time step" << endl;
        }

        return true;
    }

    // If the end of the list of trigger times has been reached, no
    // new topological changes will happen
    if (triggerIndex_ >= triggerTimes_.size())
    {
        if (debug)
        {
            Pout<< "bool attachDetach::changeTopology() const "
                << " for object " << name() << " : "
                << "Reached end of trigger list" << endl;
        }
        return false;
    }

    if (debug)
    {
        Pout<< "bool attachDetach::changeTopology() const "
            << " for object " << name() << " : "
            << "Triggering attach/detach topology change." << nl
            << "Current time: " << topoChanger().mesh().time().value()
            << " current trigger time: " << triggerTimes_[triggerIndex_]
            << " trigger index: " << triggerIndex_ << endl;
    }

    // Check if the time is greater than the currentTime.  If so, increment
    // the current lookup and request topology change
    if (topoChanger().mesh().time().value() >= triggerTimes_[triggerIndex_])
    {
        trigger_ = true;

        // Increment the trigger index
        triggerIndex_++;

        return true;
    }

    // No topological change
    return false;
}


void Foam::attachDetach::setRefinement(polyTopoChange& ref) const
{
    // Insert the attach/detach instructions into the topological change

    if (trigger_)
    {
        // Clear point addressing from previous attach/detach event
        clearAddressing();

        if (state_ == ATTACHED)
        {
            detachInterface(ref);

            // Set the state to detached
            state_ = DETACHED;
        }
        else if (state_ == DETACHED)
        {
            attachInterface(ref);

            // Set the state to attached
            state_ = ATTACHED;
        }
        else
        {
            FatalErrorInFunction
                << "Requested attach/detach event and current state "
                << "is not known."
                << abort(FatalError);
        }

        trigger_ = false;
    }
}


void Foam::attachDetach::topoChange(const polyTopoChangeMap&)
{
    // Mesh has changed topologically.  Update local topological data
    const polyMesh& mesh = topoChanger().mesh();

    faceZoneID_.update(mesh.faceZones());
    masterPatchID_.update(mesh.boundaryMesh());
    slavePatchID_.update(mesh.boundaryMesh());

    clearAddressing();
}


void Foam::attachDetach::write(Ostream& os) const
{
    os  << nl << type() << nl
        << name()<< nl
        << faceZoneID_.name() << nl
        << masterPatchID_.name() << nl
        << slavePatchID_.name() << nl
        << triggerTimes_ << endl;
}


void Foam::attachDetach::writeDict(Ostream& os) const
{
    os  << nl << name() << nl << token::BEGIN_BLOCK << nl
        << "    type " << type()
        << token::END_STATEMENT << nl
        << "    faceZoneName " << faceZoneID_.name()
        << token::END_STATEMENT << nl
        << "    masterPatchName " << masterPatchID_.name()
        << token::END_STATEMENT << nl
        << "    slavePatchName " << slavePatchID_.name()
        << token::END_STATEMENT << nl
        << "    triggerTimes " << triggerTimes_
        << token::END_STATEMENT << nl
        << "    manualTrigger " << manualTrigger()
        << token::END_STATEMENT << nl
        << "    active " << active()
        << token::END_STATEMENT << nl
        << token::END_BLOCK << endl;
}


// ************************************************************************* //
