/*---------------------------------------------------------------------------*\
 ##   ####  ######     |
 ##  ##     ##         | Copyright: ICE Stroemungsfoschungs GmbH
 ##  ##     ####       |
 ##  ##     ##         | http://www.ice-sf.at
 ##   ####  ######     |
-------------------------------------------------------------------------------
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 1991-2008 OpenCFD Ltd.
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is based on OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Contributors/Copyright:
    2012-2013 Bernhard F.W. Gschaider <bgschaid@ice-sf.at>

 SWAK Revision: $Id$
\*---------------------------------------------------------------------------*/

#ifndef LagrangianCloudSourcePluginFunctionI_H
#define LagrangianCloudSourcePluginFunctionI_H

namespace Foam {

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //


template<class LookupCloudType>
bool LagrangianCloudSourcePluginFunction::hasCloudAs()
{
    supportedTypes_.insert(typeid(LookupCloudType).name());
    //    supportedTypes_.insert(LookupCloudType::typeName);

    return mesh().template foundObject<LookupCloudType>
        (
            cloudName()
        );
}

template<class OtherCloudType,class LookupCloudType>
const OtherCloudType &LagrangianCloudSourcePluginFunction::getCloudAs()
{
    return
        //        dynamicCast<const OtherCloudType &>(
        dynamic_cast<const OtherCloudType &>(
            mesh().template lookupObject<LookupCloudType>
            (
                cloudName()
            )
        );
}



// * * * * * * * * * * * * * * * Concrete implementations * * * * * * * * * //


} // namespace

// ************************************************************************* //

#endif
