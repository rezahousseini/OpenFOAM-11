/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2020 OpenFOAM Foundation
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
    Foam::token

Description
    A token holds items read from Istream.

SourceFiles
    tokenI.H
    token.C
    tokenIO.C

\*---------------------------------------------------------------------------*/

#ifndef token_H
#define token_H

#include "primitives/ints/label/label.H"
#include "primitives/ints/uLabel/uLabel.H"
#include "primitives/Scalar/scalar/scalar.H"
#include "primitives/strings/word/word.H"
#include "primitives/strings/functionName/functionName.H"
#include "primitives/strings/variable/variable.H"
#include "primitives/strings/verbatimString/verbatimString.H"
#include "db/IOstreams/IOstreams/InfoProxy.H"
#include "memory/refCount/refCount.H"
#include "db/typeInfo/typeInfo.H"

#define NoHashTableC
#include "db/runTimeSelection/construction/runTimeSelectionTables.H"

#include <iostream>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of friend functions and operators

class token;

Istream& operator>>(Istream&, token&);
Ostream& operator<<(Ostream&, const token&);


/*---------------------------------------------------------------------------*\
                            Class token Declaration
\*---------------------------------------------------------------------------*/

class token
{

public:

    //- Enumeration defining the types of token
    enum tokenType : char
    {
        UNDEFINED      = 0,

        PUNCTUATION    = char(128),
        WORD,
        FUNCTIONNAME,
        VARIABLE,
        STRING,
        VERBATIMSTRING,
        LABEL,
        FLOAT_SCALAR,
        DOUBLE_SCALAR,
        LONG_DOUBLE_SCALAR,
        COMPOUND,

        ERROR
    };

    //- Standard punctuation tokens
    enum punctuationToken : char
    {
        NULL_TOKEN     = '\0',
        SPACE          = ' ',
        TAB            = '\t',
        NL             = '\n',

        END_STATEMENT  = ';',
        BEGIN_LIST     = '(',
        END_LIST       = ')',
        BEGIN_SQR      = '[',
        END_SQR        = ']',
        BEGIN_BLOCK    = '{',
        END_BLOCK      = '}',
        COLON          = ':',
        COMMA          = ',',
        HASH           = '#',

        BEGIN_STRING   = '"',
        END_STRING     = BEGIN_STRING,

        ASSIGN         = '=',
        ADD            = '+',
        SUBTRACT       = '-',
        MULTIPLY       = '*',
        DIVIDE         = '/'
    };

    //- Abstract base class for complex tokens
    class compound
    :
        public refCount
    {
        // Private Data

            bool empty_;


    public:

        //- Runtime type information
        TypeName("compound");


        //- Declare run-time constructor selection table
        declareRunTimeSelectionTable
        (
            autoPtr,
            compound,
            Istream,
            (Istream& is),
            (is)
        );


        // Constructors

            //- Construct null
            compound()
            :
                empty_(false)
            {}

            //- Disallow default bitwise copy construction
            compound(const compound&) = delete;


        // Selectors

            //- Select null constructed
            static autoPtr<compound> New(const word& type, Istream&);


        //- Destructor
        virtual ~compound();


        // Member Functions

            //- Return true if name is a compound type
            static bool isCompound(const word& name);

            bool empty() const
            {
                return empty_;
            }

            bool& empty()
            {
                return empty_;
            }

            virtual label size() const = 0;

            virtual void write(Ostream&) const = 0;


        // Member Operators

            //- Disallow default bitwise assignment
            void operator=(const compound&) = delete;


        // IOstream Operators

            friend Ostream& operator<<(Ostream&, const compound&);
    };


    //- A templated class for holding compound tokens
    template<class T>
    class Compound
    :
        public token::compound,
        public T
    {
    public:

        //- Runtime type information
        TypeName("Compound<T>");

        Compound(Istream& is)
        :
            T(is)
        {}

        label size() const
        {
            return T::size();
        }

        void write(Ostream& os) const
        {
            operator<<(os, static_cast<const T&>(*this));
        }
    };


    //- Static undefined token
    static token undefinedToken;


private:

    // Private Data

        //- The token type
        tokenType type_;

        //- Anonymous Union of token types
        union
        {
            punctuationToken punctuationToken_;
            word* wordTokenPtr_;
            functionName* functionNameTokenPtr_;
            variable* variableTokenPtr_;
            string* stringTokenPtr_;
            verbatimString* verbatimStringTokenPtr_;
            label labelToken_;
            floatScalar floatScalarToken_;
            doubleScalar doubleScalarToken_;
            longDoubleScalar* longDoubleScalarTokenPtr_;
            mutable compound* compoundTokenPtr_;
        };

        //- Line number in the file this token was read from
        label lineNumber_;


    // Private Member Functions

        //- Clear any allocated storage (word or string)
        inline void clear();

        // Parse error, expected 'expected', found ...
        void parseError(const char* expected) const;


public:

    // Static Data Members

        static const char* const typeName;


    // Constructors

        //- Construct null
        inline token();

        //- Copy constructor
        inline token(const token&);

        //- Construct punctuation character token
        inline token(punctuationToken, label lineNumber=0);

        //- Construct word token
        inline token(const word&, label lineNumber=0);

        //- Construct string token
        inline token(const string&, label lineNumber=0);

        //- Construct verbatimString token
        inline token(const verbatimString&, label lineNumber=0);

        //- Construct label token
        inline token(const label, label lineNumber=0);

        //- Construct floatScalar token
        inline token(const floatScalar, label lineNumber=0);

        //- Construct doubleScalar token
        inline token(const doubleScalar, label lineNumber=0);

        //- Construct longDoubleScalar token
        inline token(const longDoubleScalar, label lineNumber=0);

        //- Construct from Istream
        token(Istream&);


    //- Destructor
    inline ~token();


    // Member Functions

        // Access

            inline tokenType type() const;
            inline tokenType& type();

            inline bool good() const;
            inline bool undefined() const;
            inline bool error() const;

            inline bool isPunctuation() const;
            inline punctuationToken pToken() const;

            inline bool isWord() const;
            inline const word& wordToken() const;

            inline bool isFunctionName() const;
            inline const functionName& functionNameToken() const;

            inline bool isVariable() const;
            inline const variable& variableToken() const;

            inline bool isString() const;
            inline const string& stringToken() const;

            inline bool isVerbatimString() const;
            inline const verbatimString& verbatimStringToken() const;

            inline bool isAnyString() const;
            inline const string& anyStringToken() const;

            inline bool isLabel() const;
            inline label labelToken() const;

            inline bool isFloatScalar() const;
            inline floatScalar floatScalarToken() const;

            inline bool isDoubleScalar() const;
            inline doubleScalar doubleScalarToken() const;

            inline bool isLongDoubleScalar() const;
            inline longDoubleScalar longDoubleScalarToken() const;

            inline bool isScalar() const;
            inline scalar scalarToken() const;

            inline bool isNumber() const;
            inline scalar number() const;

            inline bool isCompound() const;
            inline const compound& compoundToken() const;
            compound& transferCompoundToken(const Istream& is);

            inline label lineNumber() const;
            inline label& lineNumber();


        // Edit

            //- Set bad
            inline void setBad();


        // Info

            //- Return info proxy.
            //  Used to print token information to a stream
            InfoProxy<token> info() const
            {
                return *this;
            }


    // Member Operators

        // Assignment

            inline void operator=(const token&);

            inline void operator=(const punctuationToken);

            inline void operator=(word*);
            inline void operator=(const word&);

            inline void operator=(functionName*);
            inline void operator=(const functionName&);

            inline void operator=(variable*);
            inline void operator=(const variable&);

            inline void operator=(string*);
            inline void operator=(const string&);

            inline void operator=(verbatimString*);
            inline void operator=(const verbatimString&);

            inline void operator=(const label);
            inline void operator=(const floatScalar);
            inline void operator=(const doubleScalar);
            inline void operator=(const longDoubleScalar);

            inline void operator=(compound*);


        // Equality

            inline bool operator==(const token&) const;
            inline bool operator==(const punctuationToken) const;
            inline bool operator==(const word&) const;
            inline bool operator==(const functionName&) const;
            inline bool operator==(const variable&) const;
            inline bool operator==(const string&) const;
            inline bool operator==(const verbatimString&) const;
            inline bool operator==(const label) const;
            inline bool operator==(const floatScalar) const;
            inline bool operator==(const doubleScalar) const;
            inline bool operator==(const longDoubleScalar) const;


        // Inequality

            inline bool operator!=(const token&) const;
            inline bool operator!=(const punctuationToken) const;
            inline bool operator!=(const word&) const;
            inline bool operator!=(const functionName&) const;
            inline bool operator!=(const variable&) const;
            inline bool operator!=(const string&) const;
            inline bool operator!=(const verbatimString&) const;
            inline bool operator!=(const label) const;
            inline bool operator!=(const floatScalar) const;
            inline bool operator!=(const doubleScalar) const;
            inline bool operator!=(const longDoubleScalar) const;


    // IOstream Operators

        friend Istream& operator>>(Istream&, token&);
        friend Ostream& operator<<(Ostream&, const token&);

        friend Ostream& operator<<(Ostream&, const punctuationToken&);
        friend ostream& operator<<(ostream&, const punctuationToken&);

        friend ostream& operator<<(ostream&, const InfoProxy<token>&);
};


Ostream& operator<<(Ostream&, const token::punctuationToken&);
ostream& operator<<(ostream&, const token::punctuationToken&);
Ostream& operator<<(Ostream&, const token::compound&);

ostream& operator<<(ostream&, const InfoProxy<token>&);

template<>
Ostream& operator<<(Ostream& os, const InfoProxy<token>& ip);

#define defineCompoundTypeName(Type, Name)                                     \
    defineTemplateTypeNameAndDebugWithName(token::Compound<Type>, #Type, 0);

#define addCompoundToRunTimeSelectionTable(Type, Name)                         \
    token::compound::addIstreamConstructorToTable<token::Compound<Type>>       \
        add##Name##IstreamConstructorToTable_;


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "db/IOstreams/token/tokenI.H"
#include "db/IOstreams/IOstreams/Istream.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
