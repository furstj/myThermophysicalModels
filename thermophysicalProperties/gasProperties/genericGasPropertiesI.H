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

\*---------------------------------------------------------------------------*/

namespace Foam
{


template<typename TransportModel>
genericGasProperties<TransportModel>::genericGasProperties(const dictionary& dict):
    gasProperties(dict),
    transport_(dict.subDict("mixture"))
{
}


template<typename TransportModel>
scalar genericGasProperties<TransportModel>::W() const
{
    return transport_.W();
}


template<typename TransportModel>
scalar genericGasProperties<TransportModel>::rho(scalar p, scalar T) const
{
    return transport_.rho(p,T);
}


template<typename TransportModel>
scalar genericGasProperties<TransportModel>::psi(scalar p, scalar T) const
{
    return transport_.psi(p,T);
}


template<typename TransportModel>
scalar genericGasProperties<TransportModel>::CpMCv(scalar p, scalar T) const
{
    return transport_.CpMCv(p,T);
}


template<typename TransportModel>
scalar genericGasProperties<TransportModel>::Cp(scalar p, scalar T) const
{
    return transport_.Cp(p,T);
}


template<typename TransportModel>
scalar genericGasProperties<TransportModel>::Ha(scalar p, scalar T) const
{
    return transport_.Ha(p,T);
}


template<typename TransportModel>
scalar genericGasProperties<TransportModel>::Hs(scalar p, scalar T) const
{
    return transport_.Hs(p,T);
}


template<typename TransportModel>
scalar genericGasProperties<TransportModel>::Hc() const
{
    return transport_.Hc();
}


template<typename TransportModel>
scalar genericGasProperties<TransportModel>::S(scalar p, scalar T) const
{
    return transport_.S(p,T);
}


template<typename TransportModel>
scalar genericGasProperties<TransportModel>::mu(scalar p, scalar T) const
{
    return transport_.mu(p,T);
}


template<typename TransportModel>
scalar genericGasProperties<TransportModel>::kappa(scalar p, scalar T) const
{
    return transport_.kappa(p,T);
}


template<typename TransportModel>
scalar genericGasProperties<TransportModel>::alphah(scalar p, scalar T) const
{
    return transport_.alphah(p,T);
}

}



// ************************************************************************* //
