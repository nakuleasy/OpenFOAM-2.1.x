/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011 OpenFOAM Foundation
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
    Foam::fileFormats::VTKedgeFormat

Description
    Provide a means of writing VTK legacy format.

SourceFiles
    VTKedgeFormat.C

\*---------------------------------------------------------------------------*/

#ifndef VTKedgeFormat_H
#define VTKedgeFormat_H

#include "edgeMesh.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace fileFormats
{

/*---------------------------------------------------------------------------*\
                     Class VTKedgeFormat Declaration
\*---------------------------------------------------------------------------*/

class VTKedgeFormat
:
    public edgeMesh
{
    // Private Member Functions

        //- Disallow default bitwise copy construct
        VTKedgeFormat(const VTKedgeFormat&);

        //- Disallow default bitwise assignment
        void operator=(const VTKedgeFormat&);


protected:

    // Protected Member Functions

        //- Write header information with points
        static void writeHeader
        (
            Ostream&,
            const pointField&
        );

        //- Write edges
        static void writeEdges(Ostream&, const UList<edge>&);


public:

    // Constructors

        //- Construct null
        VTKedgeFormat();


    //- Destructor
    virtual ~VTKedgeFormat()
    {}


    // Member Functions

        // Write

            //- Write edgeMesh
            static void write(const fileName&, const edgeMesh&);

//            //- Write object
//            virtual void write(Ostream& os) const
//            {
//                write(os, *this);
//            }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace fileFormats
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
