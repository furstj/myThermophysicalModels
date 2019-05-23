/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2019 OpenFOAM Foundation
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
    Foam::genericGasProperties

Description

SourceFiles
    genericGasPropertiesI.H
    genericGasProperties.C
    genericGasPropertiesIO.C

\*---------------------------------------------------------------------------*/

#ifndef genericGasProperties_H
#define genericGasProperties_H

#include "gasProperties.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                         Class genericGasProperties Declaration
\*---------------------------------------------------------------------------*/

template<typename TransportModel>
class genericGasProperties
:
    public gasProperties
{
    // Private data

    //- Transport model
    TransportModel transport_;


    // Private Member Functions

    //- Disallow default bitwise copy construct
    genericGasProperties(const genericGasProperties&);
    
    //- Disallow default bitwise assignment
    void operator=(const genericGasProperties&);


public:

    //- Runtime type information
    TypeName("genericGasProperties");

    
    // Constructors

    //- Construct from dictionary
    genericGasProperties(const dictionary& dict);

    //- Destructor
    ~genericGasProperties() {};


    // Member Functions

    //- Molecular weight [kg/kmol]
    virtual scalar W() const;
    
    // Fundamental equation of state properties
    
    //- Gas density rho [kg/m^3]
    virtual scalar rho(scalar p, scalar T) const;

    //- Gas compressibility rho/p [s^2/m^2]
    virtual scalar psi(scalar p, scalar T) const;
    
    //- Return (Cp - Cv) [J/(kg K]
    virtual scalar CpMCv(scalar p, scalar T) const;

     // Fundamental thermodynamic properties
    
    //- Heat capacity at constant pressure [J/(kg K)]
    virtual scalar Cp(const scalar p, const scalar T) const;
    
    //- Absolute Enthalpy [J/kg]
    virtual scalar Ha(const scalar p, const scalar T) const;
    
    //- Sensible enthalpy [J/kg]
    virtual scalar Hs(const scalar p, const scalar T) const;
    
    //- Chemical enthalpy [J/kg]
    virtual scalar Hc() const;
    
    // Entropy [J/(kg K)]
    virtual scalar S(const scalar p, const scalar T) const;
    
    // Physical properties
    
    //- Gas viscosity [Pa s]
    virtual scalar mu(scalar p, scalar T) const;
    
    //- Gas thermal conductivity  [W/(m K)]
    virtual scalar kappa(scalar p, scalar T) const;
    
    //- Gas thermal diffusivity of enthalpy [kg/ms]
    virtual scalar alphah(const scalar p, const scalar T) const;

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "genericGasPropertiesI.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
