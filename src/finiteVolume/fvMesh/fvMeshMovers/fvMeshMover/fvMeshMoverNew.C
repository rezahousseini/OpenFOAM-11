/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2021-2022 OpenFOAM Foundation
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

#include "fvMesh/fvMeshMovers/none/fvMeshMoversNone.H"

// * * * * * * * * * * * * * * * * Selectors * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::fvMeshMover> Foam::fvMeshMover::New(fvMesh& mesh)
{
    typeIOobject<IOdictionary> dictHeader
    (
        IOobject
        (
            "dynamicMeshDict",
            mesh.time().constant(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::NO_WRITE,
            false
        )
    );

    if (dictHeader.headerOk())
    {
        IOdictionary dict(dictHeader);

        if (dict.found("mover"))
        {
            const dictionary& moverDict = dict.subDict("mover");

            const word fvMeshMoverTypeName(moverDict.lookup("type"));

            Info<< "Selecting fvMeshMover " << fvMeshMoverTypeName << endl;

            libs.open
            (
                moverDict,
                "libs",
                fvMeshConstructorTablePtr_
            );

            if (!fvMeshConstructorTablePtr_)
            {
                FatalErrorInFunction
                    << "fvMeshMovers table is empty"
                    << exit(FatalError);
            }

            fvMeshConstructorTable::iterator cstrIter =
                fvMeshConstructorTablePtr_->find(fvMeshMoverTypeName);

            if (cstrIter == fvMeshConstructorTablePtr_->end())
            {
                FatalErrorInFunction
                    << "Unknown fvMeshMover type "
                    << fvMeshMoverTypeName << nl << nl
                    << "Valid fvMeshMovers are :" << endl
                    << fvMeshConstructorTablePtr_->sortedToc()
                    << exit(FatalError);
            }

            return autoPtr<fvMeshMover>(cstrIter()(mesh));
        }
    }

    return autoPtr<fvMeshMover>(new fvMeshMovers::none(mesh));
}


// ************************************************************************* //
