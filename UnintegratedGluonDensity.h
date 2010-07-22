/**
  *
  * UnintegratedGluonDensity.h
  * Functions to calculate the unintegrated gluon density in a photon.
  *
  * author: Ruben Van Boxem
  *
  **/

#ifndef UNINTEGRATEDGLUONDENSITY_H
#define UNINTEGRATEDGLUONDENSITY_H

namespace UGD
{
    double phiT2( const double z, const double r );
    double phiL2( const double z, const double r );

    double Nd( const double mu2 );

    double Fg( const double x, const double k2,
               const double mu2);
}

#endif // UNINTEGRATEDGLUONDENSITY_H
