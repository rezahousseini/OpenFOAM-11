/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2021 OpenFOAM Foundation
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

#include "db/dynamicLibrary/codedBase/codedBase.H"
#include "primitives/hashes/SHA1/SHA1Digest.H"
#include "db/dynamicLibrary/dynamicCode/dynamicCode.H"
#include "db/dynamicLibrary/dynamicCode/dynamicCodeContext.H"
#include "db/dynamicLibrary/dlLibraryTable/dlLibraryTable.H"
#include "db/regIOobject/regIOobject.H"
#include "db/IOstreams/Pstreams/PstreamReduceOps.H"
#include "include/OSspecific.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(codedBase, 0);
}


// * * * * * * * * * * * * * Static Member Functions * * * * * * * * * * * * //

void* Foam::codedBase::loadLibrary
(
    const fileName& libPath,
    const string& globalFuncName,
    const dictionary& contextDict
) const
{
    void* lib = 0;

    // avoid compilation by loading an existing library
    if (!libPath.empty())
    {
        if (libs.open(libPath, false))
        {
            lib = libs.findLibrary(libPath);

            // verify the loaded version and unload if needed
            if (lib)
            {
                // provision for manual execution of code after loading
                if (dlSymFound(lib, globalFuncName))
                {
                    loaderFunctionType function =
                        reinterpret_cast<loaderFunctionType>
                        (
                            dlSym(lib, globalFuncName)
                        );

                    if (function)
                    {
                        (*function)(true);    // force load
                    }
                    else
                    {
                        FatalIOErrorInFunction
                        (
                            contextDict
                        )   << "Failed looking up symbol " << globalFuncName
                            << nl << "from " << libPath << exit(FatalIOError);
                    }
                }
                else
                {
                    FatalIOErrorInFunction
                    (
                        contextDict
                    )   << "Failed looking up symbol " << globalFuncName << nl
                        << "from " << libPath << exit(FatalIOError);

                    lib = 0;
                    if (!libs.close(libPath, false))
                    {
                        FatalIOErrorInFunction
                        (
                            contextDict
                        )   << "Failed unloading library "
                            << libPath
                            << exit(FatalIOError);
                    }
                }
            }
        }
    }

    return lib;
}


void Foam::codedBase::unloadLibrary
(
    const fileName& libPath,
    const string& globalFuncName,
    const dictionary& contextDict
) const
{
    void* lib = 0;

    if (libPath.empty())
    {
        return;
    }

    lib = libs.findLibrary(libPath);

    if (!lib)
    {
        return;
    }

    // provision for manual execution of code before unloading
    if (dlSymFound(lib, globalFuncName))
    {
        loaderFunctionType function =
            reinterpret_cast<loaderFunctionType>
            (
                dlSym(lib, globalFuncName)
            );

        if (function)
        {
            (*function)(false);    // force unload
        }
        else
        {
            FatalIOErrorInFunction
            (
                contextDict
            )   << "Failed looking up symbol " << globalFuncName << nl
                << "from " << libPath << exit(FatalIOError);
        }
    }

    if (!libs.close(libPath, false))
    {
        FatalIOErrorInFunction
        (
            contextDict
        )   << "Failed unloading library " << libPath
            << exit(FatalIOError);
    }
}


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

Foam::string Foam::codedBase::description() const
{
    return this->type() + " " + codeName();
}


void Foam::codedBase::createLibrary
(
    dynamicCode& dynCode,
    const dynamicCodeContext& context
) const
{
    bool create =
        Pstream::master()
     || (regIOobject::fileModificationSkew <= 0);   // not NFS

    if (create)
    {
        // Write files for new library
        if (!dynCode.upToDate(context))
        {
            // filter with this context
            dynCode.reset(context);

            this->prepare(dynCode, context);

            if (!dynCode.copyOrCreateFiles(true))
            {
                FatalIOErrorInFunction
                (
                    context.dict()
                )   << "Failed writing files for" << nl
                    << dynCode.libRelPath() << nl
                    << exit(FatalIOError);
            }
        }

        if (!dynCode.wmakeLibso())
        {
            FatalIOErrorInFunction
            (
                context.dict()
            )   << "Failed wmake " << dynCode.libRelPath() << nl
                << exit(FatalIOError);
        }
    }


    // all processes must wait for compile to finish
    if (regIOobject::fileModificationSkew > 0)
    {
        //- Since the library has only been compiled on the master the
        //  other nodes need to pick this library up through NFS
        //  We do this by just polling a few times using the
        //  fileModificationSkew.

        const fileName libPath = dynCode.libPath();

        off_t mySize = Foam::fileSize(libPath);
        off_t masterSize = mySize;
        Pstream::scatter(masterSize);

        if (debug)
        {
            Pout<< endl<< "on processor " << Pstream::myProcNo()
                << " have masterSize:" << masterSize
                << " and localSize:" << mySize
                << endl;
        }


        if (mySize < masterSize)
        {
            if (debug)
            {
                Pout<< "Local file " << libPath
                    << " not of same size (" << mySize
                    << ") as master ("
                    << masterSize << "). Waiting for "
                    << regIOobject::fileModificationSkew
                    << " seconds." << endl;
            }
            Foam::sleep(regIOobject::fileModificationSkew);

            // Recheck local size
            mySize = Foam::fileSize(libPath);

            if (mySize < masterSize)
            {
                FatalIOErrorInFunction
                (
                    context.dict()
                )   << "Cannot read (NFS mounted) library " << nl
                    << libPath << nl
                    << "on processor " << Pstream::myProcNo()
                    << " detected size " << mySize
                    << " whereas master size is " << masterSize
                    << " bytes." << nl
                    << "If your case is not NFS mounted"
                    << " (so distributed) set fileModificationSkew"
                    << " to 0"
                    << exit(FatalIOError);
            }
        }

        if (debug)
        {
            Pout<< endl<< "on processor " << Pstream::myProcNo()
                << " after waiting: have masterSize:" << masterSize
                << " and localSize:" << mySize
                << endl;
        }
    }
}


// * * * * * * * * * * * * Protected Member Functions  * * * * * * * * * * * //

void Foam::codedBase::updateLibrary() const
{
    const word& name = codeName();
    const dictionary& dict = codeDict();

    dynamicCode::checkSecurity
    (
        "codedBase::updateLibrary()",
        dict
    );

    dynamicCodeContext context(dict, codeKeys());

    // codeName: name + _<sha1>
    // codeDir : name
    dynamicCode dynCode
    (
        name + context.sha1().str(true),
        name
    );
    const fileName libPath = dynCode.libPath();


    // the correct library was already loaded => we are done
    if (libs.findLibrary(libPath))
    {
        return;
    }

    Info<< "Using dynamicCode for " << this->description().c_str()
        << " at line " << dict.startLineNumber()
        << " in " << dict.name() << endl;


    // remove instantiation of fvPatchField provided by library
    this->clearRedirect();

    // may need to unload old library
    unloadLibrary
    (
        oldLibPath_,
        dynamicCode::libraryBaseName(oldLibPath_),
        context.dict()
    );

    // try loading an existing library (avoid compilation when possible)
    if (!loadLibrary(libPath, dynCode.codeName(), context.dict()))
    {
        createLibrary(dynCode, context);

        if (!loadLibrary(libPath, dynCode.codeName(), context.dict()))
        {
            FatalIOErrorInFunction(context.dict())
                << "Failed to load " << libPath << exit(FatalIOError);
        }
    }

    // retain for future reference
    oldLibPath_ = libPath;
}


const Foam::word& Foam::codedBase::codeName() const
{
    return codeName_;
}


const Foam::dictionary& Foam::codedBase::codeDict() const
{
    return dict_;
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::codedBase::codedBase()
{}


Foam::codedBase::codedBase(const word& name, const dictionary& dict)
:
    codeName_(name.replaceAll("-", "_")),
    dict_(dict)
{}


Foam::codedBase::codedBase(const dictionary& dict)
:
    codeName_(dict.lookup("name")),
    dict_(dict)
{}


Foam::codedBase::codedBase(const codedBase& cb)
:
    codeName_(cb.codeName_),
    dict_(cb.dict_)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::codedBase::~codedBase()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::word Foam::codedBase::codeTemplateC(const word& baseTypeName) const
{
    return baseTypeName + "Template.C";
}


Foam::word Foam::codedBase::codeTemplateH(const word& baseTypeName) const
{
    return baseTypeName + "Template.H";
}


void Foam::codedBase::writeCode(Ostream& os) const
{
    if (codeName().size())
    {
        writeEntry(os, "name", codeName());
    }

    wordList codeAndBuildKeys(codeKeys());
    codeAndBuildKeys.append("codeOptions");
    codeAndBuildKeys.append("codeLibs");

    forAll(codeAndBuildKeys, i)
    {
        if (codeDict().found(codeAndBuildKeys[i]))
        {
            writeKeyword(os, codeAndBuildKeys[i]);
            os.write(verbatimString(codeDict()[codeAndBuildKeys[i]]))
                << token::END_STATEMENT << nl;
        }
    }
}


// ************************************************************************* //
