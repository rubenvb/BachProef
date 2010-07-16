/**
  * Massive.cpp
  * Function implementation.
  *
  * author: Ruben Van Boxem
  *
  **/

// Function includes
#include "StructureFunction/Massive.h"

// BachProef includes
#include "StructureFunction/CouplingConstant.h"

// Cubature include
#include "Cubature/Cubature.h"

// C++ includes
#include <cmath> // M_PI, pow, exp
#include <stdexcept>
    using std::runtime_error;

namespace SF {
namespace massive {

double gluonDensity( const double x, const double k2 )
{
    const double coeff = 3*sigma0 / ( 4*M_PI*M_PI*alphaS );
    const double R02 = pow( x/x0, lambda );

    return coeff * R02 * k2 * k2 * exp( -R02*k2 );
}

double impactFactorF2( const double Q2, const double k2,
                       const double z, const double zeta )
{
    const double coeff = Q2 * alphaS / ( 4*M_PI*M_PI );
    const double differentialFactor = M_PI / k2;
    double numerator = 0.;
    double denominator = 0.;
    double sum = 0.;

    for( int i = 0; i<4; ++i )
    { // TODO
        numerator = 1. - 2.*z*(1-z) - 2.*zeta*(1.-zeta) + 12.*z*(1.-z)*zeta*(1.-zeta);
        denominator = Q2*z*(1.-z) + k2*zeta*(1.-zeta);
        sum += charge2[i] * numerator / denominator;
    }

    return coeff * differentialFactor * sum;
}
double impactFactorFL( const double Q2, const double k2,
                       const double z, const double zeta )
{
    const double coeff = 2.*Q2*alphaS / (M_PI*M_PI);
    const double differentialFactor = M_PI / k2;
    double numerator = 0.;
    double denominator = 0.;
    double sum = 0.;

    for( int i=0; i<4 ; ++i )
    {
        numerator = z*(1-z)*zeta*zeta*(1-zeta)*(1-zeta);
        denominator = ( Q2*z*(1-z) + k2*zeta*(1-zeta) + mass2[i] ) * ( Q2*zeta*(1-zeta) + mass2[i] );
        sum += charge2[i] * numerator / denominator;
    }

    return coeff * differentialFactor * sum;
}

void integrandF2( unsigned /*ndim*/, const double* xValues,
                  void* input, unsigned /*fdim*/,
                  double *fval )
{
    double x = static_cast<double*>(input)[0];
    double Q2 = static_cast<double*>(input)[1];
    double k2 = xValues[0];
    double z = xValues[1];
    double zeta = xValues[2];

    *fval = impactFactorF2( Q2, k2, z, zeta ) * gluonDensity( x, k2 );
}
void integrandFL( unsigned /*ndim*/, const double* xValues,
                  void* input, unsigned /*fdim*/,
                  double *fval )
{
    double x = static_cast<double*>(input)[0];
    double Q2 = static_cast<double*>(input)[1];
    double k2 = xValues[0];
    double z = xValues[2];
    double zeta = xValues[1];

    *fval = impactFactorFL( Q2, k2, z, zeta ) * gluonDensity( x, k2 );
}

double F2( const double x, const double Q2 )
{
    double val = 0.;
    double err = 0.;

    double xMin[] = { 0., 0., 0. };
    double xMax[] = { 1000., 1., 1. };
    double input[] = { x, Q2 };
    bool fail = adapt_integrate( 1, integrandF2, input,
                                 3, xMin, xMax,
                                 0, 0, 1e-4,
                                 &val, &err);
    if( fail )
        throw runtime_error( "adapt_integrate returned an error." );

    return val;
}
double FL( const double x, const double Q2 )
{
    double val = 0.;
    double err = 0.;

    double xMin[] = { 0., 0., 0. };
    double xMax[] = { 1000., 1., 1. };
    double input[] = { x, Q2 };

    bool fail = adapt_integrate( 1, integrandFL, input,
                                 3, xMin, xMax,
                                 0, 0, 1e-4,
                                 &val, &err);
    if( fail )
        throw runtime_error( "adapt_integrate returned an error." );

    return val;
}

} // namespace massless
} // namespace SF
