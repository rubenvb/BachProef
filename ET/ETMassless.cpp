/**
  * TransverseEnergyFlow.cpp
  * Function implementation.
  *
  * author: Ruben Van Boxem
  *
  **/

// Function include
#include "TransverseEnergyFlow.h"

// BachProef includes
#include "StructureFunction.h"
#include "StrongCoupling.h"
#include "UnintegratedGluonDensity.h"

// GSL includes
#include <ALGLIB/elliptic.h>

// C++ includes
#include <cmath> // M_PI, sqrt
#include <iostream>
using std::cout;
using std::endl;

namespace ET
{
namespace massless
{

double ET( const double xj, const double Q2 )
{
    const double F2 = SF::massless::F2( xj, Q2 );
    const double coeff = 3*alphaS/M_PI;

    return coeff;
}
void integrandET( unsigned /*ndim*/, const double* xValues,
                  void* input, unsigned /*fdim*/,
                  double* fval )
{
    const double x = static_cast<double*>(input)[0];
    const double Q2 = static_cast<double*>(input)[1];
    const double k2 = xValues[0];
    const double z = xValues[1];
    const double zeta = xValues[2];

    double result = 0.;

    *fval = result;
}

double phiIntegral( const double kp, const double kgamma )
{
    const double alpha = kp*kp + kgamma*kgamma;
    const double beta = 2.*kp*kgamma;
    const double term1 = 2.*sqrt( alpha+beta ) * ellipticintegralk( -2.*beta/(alpha-beta) );
    const double term2 = 2.*sqrt( alpha-beta ) * ellipticintegralk( 2.*beta/(alpha+beta) );
    const double denominator = sqrt( alpha*alpha-beta*beta );

    return (term1+term2)/denominator;
}

} // namespace massless

} // namespace ET
