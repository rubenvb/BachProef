/**
  *
  * UnintegratedGluonDensity.cpp
  * Function implementation.
  *
  * author: Ruben Van Boxem
  *
  **/

// Function include
#include "UnintegratedGluonDensity.h"

// BachProef includes
#include "Quarks.h"
    using namespace quarks;

// C++ includes
#include <cmath> // M_PI

namespace UGD
{

double phiT2( const double z, const double r )
{
    const double coeff = 6 / (4*M_PI*M_PI);
    double eps2 = 0.;
    double sum = 0.;

    for( int i=0; i<4; ++i )
    {
        eps2 = z*(1-z) * 1.4*1.4 + mass2[i];
        sum += eps2;
    }
    return 0.;
}

double phiL2( const double z, const double r )
{
    return 0.;
}

double Nd( const double mu2 )
{
    return 0.;
}

double Fg( const double x, const double k2,
           const double mu2)
{
    return 0.;
}

} // namespace UGD
