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
    Foam::string

Description
    A class for handling character strings derived from std::string.

    Strings may contain any characters and therefore are delimited by quotes
    for IO : "any list of characters".

    Used as a base class for word and fileName.

See also
    Foam::findEtcFile() for information about the site/user OpenFOAM
    configuration directory

SourceFiles
    string.C
    stringIO.C

\*---------------------------------------------------------------------------*/

#ifndef string_H
#define string_H

#include "primitives/chars/char/char.H"
#include "primitives/hashes/Hasher/Hasher.H"

#include <string>
#include <cstring>
#include <cstdlib>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of classes
class Istream;
class Ostream;

// Forward declaration of friend functions and operators
class string;
Istream& operator>>(Istream&, string&);
Ostream& operator<<(Ostream&, const string&);
Ostream& operator<<(Ostream&, const std::string&);

template<class T>
class UList;

/*---------------------------------------------------------------------------*\
                           Class string Declaration
\*---------------------------------------------------------------------------*/

class string
:
    public std::string
{
public:

    // Static Data Members

        static const char* const typeName;
        static int debug;

        //- An empty string
        static const string null;


    //- Hashing function class, shared by all the derived classes
    class hash
    {
    public:
        hash()
        {}

        inline unsigned operator()(const string&, unsigned seed = 0) const;
    };


    // Constructors

        //- Construct null
        inline string();

        //- Construct from std::string
        inline string(const std::string&);

        //- Copy constructor
        inline string(const string&);

        //- Move constructor
        inline string(string&&);

        //- Construct as copy of character array
        inline string(const char*);

        //- Construct as copy of UList of character
        string(const UList<char>&);

        //- Construct as copy of specified number of characters
        inline string(const char*, const size_type);

        //- Construct from a single character
        inline string(const char);

        //- Construct from copies of a single character
        inline string(const size_type, const char);

        //- Construct from Istream
        string(Istream&);


    // Member Functions

        //- Count and return the number of a given character in the string
        size_type count(const char) const;

        //- Is this string type valid?
        template<class String>
        static inline bool valid(const string&);

        //- Does this string have particular meta-characters?
        //  The meta characters can be optionally quoted.
        template<class String>
        static inline bool meta(const string&, const char quote='\\');

        //- Strip invalid characters from the given string
        template<class String>
        static inline bool stripInvalid(string&);

        //- Return a valid String from the given string
        template<class String>
        static inline String validate(const string&);

        //- Return a String with quoted meta-characters from the given string
        template<class String>
        static inline string quotemeta(const string&, const char quote='\\');

        //- True when strings match literally
        inline bool match(const std::string&) const;

        //- Avoid masking the normal std::string replace
        using std::string::replace;

        //- In this string replace first occurrence of sub-string oldStr
        //  with newStr starting at start
        string& replace
        (
            const string& oldStr,
            const string& newStr,
            size_type start = 0
        );

        //- Replace first occurrence of sub-string oldStr with newStr
        //  starting at start
        string replace
        (
            const string& oldStr,
            const string& newStr,
            size_type start = 0
        ) const;

        //- In this string replace all occurrences of sub-string oldStr
        //  with newStr starting at start
        string& replaceAll
        (
            const string& oldStr,
            const string& newStr,
            size_type start = 0
        );

        //- Replace all occurrences of sub-string oldStr with newStr
        //  starting at start
        string replaceAll
        (
            const string& oldStr,
            const string& newStr,
            size_type start = 0
        ) const;

        //- Expand initial tildes and all occurrences of environment variables
        //  Expansion includes:
        //  -# environment variables
        //    - "$VAR", "${VAR}"
        //  -# current directory
        //    - leading "./" : the current directory
        //  -# tilde expansion
        //    - leading "~/" : home directory
        //    - leading "~user" : home directory for specified user
        //    - leading "~OpenFOAM" : site/user OpenFOAM configuration directory
        //
        //  Any unknown entries are removed silently if allowEmpty is true
        //  \sa
        //  Foam::findEtcFile
        string& expand(const bool allowEmpty = false);

        //- Remove all occurrences of character returning true if string changed
        bool remove(const char);

        //- Remove all occurrences of character and return the string
        string remove(const char) const;

        //- Remove repeated character returning true if string changed
        bool removeRepeated(const char);

        //- Remove repeated character and return the string
        string removeRepeated(const char) const;

        //- Remove trailing character returning true if string changed
        bool removeTrailing(const char);

        //- Return string with trailing character removed
        string removeTrailing(const char) const;

        //- Remove trailing string returning true if string changed
        bool removeTrailing(const string&);

        //- Return string with trailing string removed
        string removeTrailing(const string&) const;

        //- Strip characters from the start and end of the string
        void strip(const string&);

        //- Find the closing character. Brackets counting algorithm. The
        //  opening bracket character is taken to be the one at the starting
        //  position. The closing character is provided by argument.
        //
        //  Examples:
        //
        //          [char #1]       [char #15]
        //               |             |
        //               V             V
        //      string("0(2(4,6)8,a(c)e)g").findClosing(')',1) == 15
        //
        //          [char #3] [char #7]
        //                 |   |
        //                 V   V
        //      string("0(2(4,6)8,a(c)e)g").findClosing(')',3) == 7
        //
        size_type findClosing(const char, const size_type) const;


    // Member Operators

        //- Return the sub-string from the i-th character for \a n characters
        inline string operator()
        (
            const size_type i,
            const size_type n
        ) const;

        //- Return the sub-string from the first character for \a n characters
        inline string operator()
        (
            const size_type n
        ) const;

        inline void operator=(const string&);
        inline void operator=(string&&);


    // IOstream Operators

        friend Istream& operator>>(Istream&, string&);
        friend Ostream& operator<<(Ostream&, const string&);
};


void writeEntry(Ostream& os, const char* value);
void writeEntry(Ostream& os, const string& value);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "primitives/strings/string/stringI.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
