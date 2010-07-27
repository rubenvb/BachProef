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
#include <gsl/gsl_sf_ellint.h>

// C++ includes
#include <cmath> // M_PI, sqrt

namespace ET
{
namespace massless
{

double ET( const double xj, const double Q2 )
{
    const double F2 = SF::massless::F2( xj, Q2 );
    const double coeff = 3*alphaS/M_PI;
}

double phiIntegral( const double kp, const double kgamma )
{
    const double alpha = kp*kp + kgamma*kgamma;
    const double beta = 2.*kp*kgamma;
    const double term1 = 2.*sqrt( alpha+beta ) * gsl_sf_ellint_Kcomp( sqrt(-2.*beta/(alpha-beta)), GSL_PREC_DOUBLE );
    const double term2 = 2.*sqrt( alpha-beta ) * gsl_sf_ellint_Kcomp( sqrt(2.*beta/(alpha+beta)), GSL_PREC_DOUBLE );
    const double denominator = sqrt( alpha*alpha-beta*beta );

    return (term1+term2)/denominator;
}

} // namespace massless

} // namespace ET
