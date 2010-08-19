/**
  * Massless.cpp
  * Function implementation.
  *
  * author: Ruben Van Boxem
  *
  **/

// Function include
#include "UGD/UGDMassless.h"

// Bachproef includes
#include "StrongCoupling.h"

// Cubature includes
#include "Cubature/Cubature.h"

// C++ includes
#include <cmath> // M_PI, exp
#include <iostream>
    using std::cout;
    using std::endl;
#include <stdexcept>
    using std::runtime_error;

namespace UGD
{
namespace massless
{

double impactF0( const double k2, const double Q2,
                 const double eta, const double rho )
{
    const double coeff = runningAlphaS(k2) * k2 * Q2 / (4*M_PI);
    const double numerator = 1 - 2.*rho*(1-rho) - 2.*eta*(1-eta) + 12.*rho*(1-rho)*eta*(1-eta);
    const double denominator = k2*eta*(1-eta) + Q2*rho*(1-rho);

    return charge2 * coeff * numerator / denominator;
}

double impactF0Evol( const double x,
                     const double k2, const double Q2,
                     const double eta, const double rho )
{
    const double R02 = pow( x/x0, lambda );
    const double alphaS = runningAlphaS( k2*R02 );
    const double coeff = charge2 * alphaS *k2*R02*Q2 / (4.*M_PI);
    const double numerator = 1 - 2.*rho*(1-rho) - 2.*eta*(1-eta) + 12.*rho*(1-rho)*eta*(1-eta);
    const double denominator = R02*k2*eta*(1-eta) + Q2*rho*(1-rho);
    const double exponential = exp( -log(k2*R02)*log(k2*R02) / (2.*48.*alphaS*log(.1/x)) );

    return coeff * exponential * numerator / denominator;
}

void integrandF0( unsigned /*ndim*/, const double* xValues,
                  void* input, unsigned /*fdim*/,
                  double* fval )
{
    const double k2 = static_cast<double*>(input)[0];
    const double Q2 = static_cast<double*>(input)[1];
    const double eta = xValues[0];
    const double rho = xValues[1];

    *fval = impactF0( k2, Q2, eta, rho );
}

void integrandF0Evol( unsigned /*ndim*/, const double* xValues,
                      void* input, unsigned /*fdim*/,
                      double* fval )
{
    const double x = static_cast<double*>(input)[0];
    const double k2 = static_cast<double*>(input)[1];
    const double Q2 = static_cast<double*>(input)[2];
    const double eta = xValues[0];
    const double rho = xValues[1];

    *fval = impactF0Evol( x, k2, Q2, eta, rho );
}

double F0( const double k2, const double Q2 )
{
    double val = 0.;
    double err = 0.;

    double xMin[] = { 0., 0. };
    double xMax[] = { 1., 1. };
    double input[] = { k2, Q2 };

    const bool fail = adapt_integrate( 1, integrandF0, input,
                                       2, xMin, xMax,
                                       0, 0, 1e-4,
                                       &val, &err);
    if( fail )
        throw runtime_error( "adapt_integrate returned an error." );

    return val;
}

double F0Evol( const double x, const double k2, const double Q2 )
{
    double val = 0.;
    double err = 0.;

    double xMin[] = { 0., 0. };
    double xMax[] = { 1., 1. };
    double input[] = { x, k2, Q2 };

    const bool fail = adapt_integrate( 1, integrandF0Evol, input,
                                       2, xMin, xMax,
                                       0, 0, 1e-4,
                                       &val, &err);
    if( fail )
        throw runtime_error( "adapt_integrate returned an error." );

    return val;
}
double F0EvolAlternate( const double z,
                        const double k2, const double Q2 )
{
    const double alphaP = 12.*alphaS/M_PI*log(2.)+1.;
    const double sumeq2 = 1./9.+1./9.+4./9.;
    const double coeff = 9. * M_PI * M_PI * 2. * sumeq2/
                         (512. * sqrt(21.*1.20205690315959428539973816/2.)); // Zeta(3) = 1.20...
    const double part2 = sqrt(alphaS * k2/Q2) * Q2*pow(z,1.-alphaP) / ( sqrt(log(1./z)) );

    return coeff*part2;
}

} // namespace massless

} // namespace UGD
