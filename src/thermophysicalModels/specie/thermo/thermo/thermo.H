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

Class
    Foam::species::thermo

Description
    Basic thermodynamics type based on the use of fitting functions for
    cp, h, s obtained from the template argument type thermo.  All other
    properties are derived from these primitive functions.

SourceFiles
    thermoI.H
    thermo.C

\*---------------------------------------------------------------------------*/

#ifndef thermo_H
#define thermo_H

#include "global/constants/thermodynamic/thermodynamicConstants.H"
using namespace Foam::constant::thermodynamic;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace species
{

// Forward declaration of friend functions and operators

template<class Thermo, template<class> class Type> class thermo;

template<class Thermo, template<class> class Type>
inline thermo<Thermo, Type> operator+
(
    const thermo<Thermo, Type>&,
    const thermo<Thermo, Type>&
);

template<class Thermo, template<class> class Type>
inline thermo<Thermo, Type> operator*
(
    const scalar,
    const thermo<Thermo, Type>&
);

template<class Thermo, template<class> class Type>
inline thermo<Thermo, Type> operator==
(
    const thermo<Thermo, Type>&,
    const thermo<Thermo, Type>&
);

template<class Thermo, template<class> class Type>
Ostream& operator<<
(
    Ostream&,
    const thermo<Thermo, Type>&
);


/*---------------------------------------------------------------------------*\
                           Class thermo Declaration
\*---------------------------------------------------------------------------*/

template<class Thermo, template<class> class Type>
class thermo
:
    public Thermo,
    public Type<thermo<Thermo, Type>>
{
    // Private Data

        //- Convergence tolerance of energy -> temperature inversion functions
        static const scalar tol_;

        //- Max number of iterations in energy->temperature inversion functions
        static const int maxIter_;


public:

    // Public Typedefs

        //- The thermodynamics of the individual species'
        typedef thermo<Thermo, Type> thermoType;


    // Constructors

        //- Construct from components
        inline thermo(const Thermo& sp);

        //- Construct from name and dictionary
        thermo(const word& name, const dictionary& dict);

        //- Construct as named copy
        inline thermo(const word& name, const thermo&);


    // Member Functions

        //- Return the instantiated type name
        static word typeName()
        {
            return
                  Thermo::typeName() + ','
                + Type<thermo<Thermo, Type>>::typeName();
        }

        //- Return true if energy type is enthalpy
        static inline bool enthalpy();

        //- Name of Enthalpy/Internal energy
        static inline word heName();


        // Fundamental properties
        // (These functions must be provided in derived types)

            // Heat capacity at constant pressure [J/kg/K]
            // inline scalar Cp(const scalar p, const scalar T) const;

            // Sensible enthalpy [J/kg]
            // inline scalar Hs(const scalar p, const scalar T) const;

            // Enthalpy of formation [J/kg]
            // inline scalar Hf() const;

            // Absolute enthalpy [J/kg]
            // inline scalar Ha(const scalar p, const scalar T) const;

            // Heat capacity at constant volume [J/kg/K]
            // inline scalar Cv(const scalar p, const scalar T) const;

            // Sensible internal energy [J/kg]
            // inline scalar Es(const scalar p, const scalar T) const;

            // Absolute internal energy [J/kg]
            // inline scalar Ea(const scalar p, const scalar T) const;

            // Entropy [J/kg/K]
            // inline scalar S(const scalar p, const scalar T) const;


        // Mass specific derived properties

            //- Heat capacity at constant pressure/volume [J/kg/K]
            inline scalar Cpv(const scalar p, const scalar T) const;

            //- Gamma = Cp/Cv []
            inline scalar gamma(const scalar p, const scalar T) const;

            //- Enthalpy/Internal energy [J/kg]
            inline scalar HE(const scalar p, const scalar T) const;

            //- Gibbs free energy [J/kg]
            inline scalar G(const scalar p, const scalar T) const;

            //- Helmholtz free energy [J/kg]
            inline scalar A(const scalar p, const scalar T) const;


        // Mole specific derived properties

            //- Heat capacity at constant pressure [J/kmol/K]
            inline scalar cp(const scalar p, const scalar T) const;

            //- Absolute enthalpy [J/kmol]
            inline scalar ha(const scalar p, const scalar T) const;

            //- Sensible enthalpy [J/kmol]
            inline scalar hs(const scalar p, const scalar T) const;

            //- Enthalpy of formation [J/kmol]
            inline scalar hc() const;

            //- Entropy [J/kmol/K]
            inline scalar s(const scalar p, const scalar T) const;

            //- Enthalpy/Internal energy [J/kmol]
            inline scalar he(const scalar p, const scalar T) const;

            //- Heat capacity at constant volume [J/kmol/K]
            inline scalar cv(const scalar p, const scalar T) const;

            //- Sensible internal energy [J/kmol]
            inline scalar es(const scalar p, const scalar T) const;

            //- Absolute internal energy [J/kmol]
            inline scalar ea(const scalar p, const scalar T) const;

            //- Gibbs free energy [J/kmol]
            inline scalar g(const scalar p, const scalar T) const;

            //- Helmholtz free energy [J/kmol]
            inline scalar a(const scalar p, const scalar T) const;


        // Equilibrium reaction thermodynamics

            //- Equilibrium constant [] i.t.o fugacities
            //  = PIi(fi/Pstd)^nui
            inline scalar K(const scalar p, const scalar T) const;

            //- Equilibrium constant [] i.t.o. partial pressures
            //  = PIi(pi/Pstd)^nui
            //  For low pressures (where the gas mixture is near perfect) Kp = K
            inline scalar Kp(const scalar p, const scalar T) const;

            //- Equilibrium constant i.t.o. molar concentration
            //  = PIi(ci/cstd)^nui
            //  For low pressures (where the gas mixture is near perfect)
            //  Kc = Kp(pstd/(RR*T))^nu
            inline scalar Kc(const scalar p, const scalar T) const;

            //- Equilibrium constant [] i.t.o. mole-fractions
            //  For low pressures (where the gas mixture is near perfect)
            //  Kx = Kp(pstd/p)^nui
            inline scalar Kx
            (
                const scalar p,
                const scalar T
            ) const;

            //- Equilibrium constant [] i.t.o. number of moles
            //  For low pressures (where the gas mixture is near perfect)
            //  Kn = Kp(n*pstd/p)^nui where n = number of moles in mixture
            inline scalar Kn
            (
                const scalar p,
                const scalar T,
                const scalar n
            ) const;


        // Energy->temperature  inversion functions

            //- Return the temperature corresponding to the value of the
            //  thermodynamic property f, given the function f = F(p, T)
            //  and dF(p, T)/dT
            template
            <
                class ThermoType,
                class FType,
                class dFdTType,
                class LimitType
            >
            inline static scalar T
            (
                const ThermoType& thermo,
                const scalar f,
                const scalar p,
                const scalar T0,
                FType F,
                dFdTType dFdT,
                LimitType limit,
                const bool diagnostics = false
            );

            //- Temperature from enthalpy or internal energy
            //  given an initial temperature T0
            inline scalar THE
            (
                const scalar H,
                const scalar p,
                const scalar T0
            ) const;

            //- Temperature from sensible enthalpy given an initial T0
            inline scalar THs
            (
                const scalar Hs,
                const scalar p,
                const scalar T0
            ) const;

            //- Temperature from absolute enthalpy
            //  given an initial temperature T0
            inline scalar THa
            (
                const scalar H,
                const scalar p,
                const scalar T0
            ) const;

            //- Temperature from sensible internal energy
            //  given an initial temperature T0
            inline scalar TEs
            (
                const scalar E,
                const scalar p,
                const scalar T0
            ) const;

            //- Temperature from absolute internal energy
            //  given an initial temperature T0
            inline scalar TEa
            (
                const scalar E,
                const scalar p,
                const scalar T0
            ) const;


        // Derivative term used for Jacobian

            //- Derivative of B (according to Niemeyer et al.)
            //  w.r.t. temperature
            inline scalar dKcdTbyKc(const scalar p, const scalar T) const;

            //- Derivative of cp w.r.t. temperature
            inline scalar dcpdT(const scalar p, const scalar T) const;


        // I-O

            //- Write to Ostream
            void write(Ostream& os) const;


    // Member Operators

        inline void operator+=(const thermo&);
        inline void operator*=(const scalar);


    // Friend operators

        friend thermo operator+ <Thermo, Type>
        (
            const thermo&,
            const thermo&
        );

        friend thermo operator* <Thermo, Type>
        (
            const scalar s,
            const thermo&
        );

        friend thermo operator== <Thermo, Type>
        (
            const thermo&,
            const thermo&
        );


    // Ostream Operator

        friend Ostream& operator<< <Thermo, Type>
        (
            Ostream&,
            const thermo&
        );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace species
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "thermo/thermo/thermoI.H"

#ifdef NoRepository
    #include "thermo/thermo/thermo.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
