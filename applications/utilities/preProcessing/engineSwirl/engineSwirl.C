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

Application
    engineSwirl

Description
    Generates a swirling flow for engine calculations.

\*---------------------------------------------------------------------------*/

#include "global/argList/argList.H"
#include "fields/volFields/volFields.H"
#include "global/constants/mathematical/mathematicalConstants.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "include/setRootCase.H"
    #include "include/createTime.H"
    #include "include/createMeshNoChangers.H"
    #include "createFields.H"

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    scalar Vphi = (constant::mathematical::pi*swirlRPMRatio*rpm/30).value();
    scalar b1 = j1(swirlProfile).value();
    scalar b2 = 2.0*b1/swirlProfile.value() - j0(swirlProfile).value();

    scalar omega = 0.125*(Vphi*bore*swirlProfile/b2).value();

    scalar cylinderRadius = 0.5*bore.value();

    scalar Umax = 0.0;
    forAll(mesh.C(), celli)
    {
        vector c = mesh.C()[celli] - swirlCenter;
        scalar r = ::pow(sqr(c & xT) + sqr(c & yT), 0.5);

        if (r <= cylinderRadius)
        {
            scalar b = j1(swirlProfile*r/cylinderRadius).value();
            scalar vEff = omega*b;
            r = max(r, small);
            U[celli] = ((vEff/r)*(c & yT))*xT + (-(vEff/r)*(c & xT))*yT;
            Umax = max(Umax, mag(U[celli]));
        }
    }

    Info<< "Umax = " << Umax << endl;

    U.write();

    Info<< "\n end\n";

    return 0;
}


// ************************************************************************* //
