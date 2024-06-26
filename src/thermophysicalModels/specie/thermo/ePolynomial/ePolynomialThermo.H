/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2021-2023 OpenFOAM Foundation
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
    Foam::ePolynomialThermo

Description
    Internal energy based thermodynamics package using a polynomial function
    of temperature for the constant heat capacity at constant volume:

    \verbatim
        Cv = CvCoeffs[0] + CvCoeffs[1]*T + CvCoeffs[2]*sqr(T)
           + CvCoeffs[3]*pow3(T) + CvCoeffs[4]*pow4(T)
           + CvCoeffs[5]*pow(T, 5) + CvCoeffs[6]*pow(T, 6)
           + CvCoeffs[7]*pow(T, 7)
    \endverbatim

    The polynomial function is templated on the order of the polynomial which
    defaults to 8.

Usage
    \table
        Property     | Description
        Hf           | Heat of formation
        Sf           | Standard entropy
        CvCoeffs<8>  | Specific heat at constant volume polynomial coeffs
    \endtable

    Example of the specification of the thermodynamic properties:
    \verbatim
    thermodynamics
    {
        Hf              0;
        Sf              0;
        CvCoeffs<8>     (1000 -0.05 0.003 0 0 0 0 0);
    }
    \endverbatim

    Note:
        Specific heat at constant volume polynomial coefficients evaluate to an
        expression in [J/kg/K].

SourceFiles
    ePolynomialThermoI.H
    ePolynomialThermo.C

See also
    Foam::Polynomial

\*---------------------------------------------------------------------------*/

#ifndef ePolynomialThermo_H
#define ePolynomialThermo_H

#include "primitives/Scalar/scalar/scalar.H"
#include "primitives/functions/Polynomial/Polynomial.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of friend functions and operators

template<class EquationOfState, int PolySize>
class ePolynomialThermo;

template<class EquationOfState, int PolySize>
inline ePolynomialThermo<EquationOfState, PolySize> operator+
(
    const ePolynomialThermo<EquationOfState, PolySize>&,
    const ePolynomialThermo<EquationOfState, PolySize>&
);

template<class EquationOfState, int PolySize>
inline ePolynomialThermo<EquationOfState, PolySize> operator*
(
    const scalar,
    const ePolynomialThermo<EquationOfState, PolySize>&
);

template<class EquationOfState, int PolySize>
inline ePolynomialThermo<EquationOfState, PolySize> operator==
(
    const ePolynomialThermo<EquationOfState, PolySize>&,
    const ePolynomialThermo<EquationOfState, PolySize>&
);

template<class EquationOfState, int PolySize>
Ostream& operator<<
(
    Ostream&,
    const ePolynomialThermo<EquationOfState, PolySize>&
);


/*---------------------------------------------------------------------------*\
                      Class ePolynomialThermo Declaration
\*---------------------------------------------------------------------------*/

template<class EquationOfState, int PolySize=8>
class ePolynomialThermo
:
    public EquationOfState
{
    // Private Data

        //- Heat of formation
        scalar Hf_;

        //- Standard entropy
        scalar Sf_;

        //- Specific heat at constant volume polynomial coeffs [J/kg/K/K^i]
        Polynomial<PolySize> CvCoeffs_;

        //- Internal energy polynomial coeffs [J/kg/K^i]
        //  Derived from Cv coeffs. Relative to Tstd.
        typename Polynomial<PolySize>::intPolyType eCoeffs_;

        //- Entropy polynomial coeffs [J/kg/K/K^i]
        //  Derived from Cv coeffs. Relative to Tstd.
        Polynomial<PolySize> sCoeffs_;


    // Private Member Functions

        //- Construct from components
        inline ePolynomialThermo
        (
            const EquationOfState& pt,
            const scalar Hf,
            const scalar Sf,
            const Polynomial<PolySize>& CvCoeffs,
            const typename Polynomial<PolySize>::intPolyType& eCoeffs,
            const Polynomial<PolySize>& sCoeffs
        );


public:

    // Constructors

        //- Construct from name and dictionary
        ePolynomialThermo(const word& name, const dictionary& dict);

        //- Construct as a named copy
        inline ePolynomialThermo(const word&, const ePolynomialThermo&);


    // Member Functions

        //- Return the instantiated type name
        static word typeName()
        {
            return "ePolynomial<" + EquationOfState::typeName() + '>';
        }

        //- Limit the temperature to be in the range Tlow_ to Thigh_
        inline scalar limit(const scalar) const;


        // Fundamental properties

            //- Heat capacity at constant volume [J/kg/K]
            inline scalar Cv(const scalar p, const scalar T) const;

            //- Sensible internal energy [J/kg]
            inline scalar Es(const scalar p, const scalar T) const;

            //- Absolute internal energy [J/kg]
            inline scalar Ea(const scalar p, const scalar T) const;

            //- Enthalpy of formation [J/kg]
            inline scalar Hf() const;

            //- Entropy [J/kg/K]
            inline scalar S(const scalar p, const scalar T) const;

            //- Gibbs free energy of the mixture in the standard state [J/kg]
            inline scalar Gstd(const scalar T) const;

            #include "thermo/thermo/EtoHthermo.H"


        // Derivative term used for Jacobian

            //- Temperature derivative of heat capacity at constant pressure
            inline scalar dCpdT(const scalar p, const scalar T) const;


        // I-O

            //- Write to Ostream
            void write(Ostream& os) const;


    // Member Operators

        inline void operator+=(const ePolynomialThermo&);
        inline void operator*=(const scalar);


    // Friend operators

        friend ePolynomialThermo operator+ <EquationOfState, PolySize>
        (
            const ePolynomialThermo&,
            const ePolynomialThermo&
        );

        friend ePolynomialThermo operator* <EquationOfState, PolySize>
        (
            const scalar,
            const ePolynomialThermo&
        );

        friend ePolynomialThermo operator== <EquationOfState, PolySize>
        (
            const ePolynomialThermo&,
            const ePolynomialThermo&
        );


    // Ostream Operator

        friend Ostream& operator<< <EquationOfState, PolySize>
        (
            Ostream&,
            const ePolynomialThermo&
        );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "thermo/ePolynomial/ePolynomialThermoI.H"

#ifdef NoRepository
    #include "thermo/ePolynomial/ePolynomialThermo.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
