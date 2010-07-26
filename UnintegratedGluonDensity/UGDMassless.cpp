/**
  * Massless.cpp
  * Function implementation.
  *
  * author: Ruben Van Boxem
  *
  **/

// Function include
#include "UnintegratedGluonDensity/UGDMassless.h"

// Bachproef includes
#include "StrongCoupling.h"

// Cubature includes
#include "Cubature/Cubature.h"

// C++ includes
#include <cmath> // M_PI
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

double impactF0Evol( const double k2, const double Q2,
                     const double eta, const double rho )
{
    const double coeff = 0.;

    return coeff;
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

} // namespace massless

} // namespace UGD
