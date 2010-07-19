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

double xTilde( const double x, const double Q2, const int quark )
{
    return x * ( 1 + 4*mass2[quark]/Q2 );
}

double gluonDensity( const double xTilde, const double k2 )
{
    const double coeff = 3*sigma0 / ( 4*M_PI*M_PI*alphaS );
    const double R02 = pow( xTilde/x0, lambda );

    return coeff * R02 * k2 * k2 * exp( -R02*k2 );
}

double impactFL( const double Q2, const double k2,
                       const double z, const double zeta,
                       const int quark )
{
    const double coeff = 2.*Q2*alphaS / (M_PI*M_PI);
    const double differentialFactor = M_PI / k2;
    const double numerator = zeta*(1-zeta)*z*(1-z)*z*(1-z)*Q2;
    const double denominator = ( Q2*z*(1-z) + k2*zeta*(1-zeta) + mass2[quark] )
                               * ( Q2*z*(1-z) + mass2[quark] );

    return coeff * charge2[quark] * differentialFactor * numerator/denominator;
}
double impactFT( const double Q2, const double k2,
                       const double z, const double zeta,
                       const int quark )
{
    const double coeff = 1.;//Q2 * alphaS / ( 4*M_PI*M_PI );
    const double differentialFactor = M_PI / k2;
    const double numerator = Q2 * ( z*z+(1-z)*(1-z) ) * z*(1-z) * ( zeta*zeta+(1-zeta)*(1-zeta) )
                             + ( z*z+(1-z)*(1-z) ) * mass2[quark]
                             + 4 * z*(1-z) * zeta*(1-zeta) * mass2[quark] / k2;
    const double denominator = ( Q2 * z*(1-z) + k2 * zeta*(1-zeta) + mass2[quark] )
                               * ( Q2 * z*(1-z) + mass2[quark] );
    const double fraction = numerator / denominator;

    return coeff * charge2[quark] * differentialFactor * fraction;
}
double impactF2( const double Q2, const double k2,
                       const double z, const double zeta,
                       const int quark )
{
    return impactFL( Q2, k2, z, zeta, quark ) + impactFT( Q2, k2, z, zeta, quark );

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

    double result = 0.;
    // sum over quarks
    for( int i=0; i<4; ++i )
    {
        result += impactF2( Q2, k2, z, zeta, i ) * gluonDensity( xTilde(x,Q2,i), k2 );
    }

    *fval = result;
}
void integrandFL( unsigned /*ndim*/, const double* xValues,
                  void* input, unsigned /*fdim*/,
                  double *fval )
{
    const double x = static_cast<double*>(input)[0];
    const double Q2 = static_cast<double*>(input)[1];
    const double k2 = xValues[0];
    const double z = xValues[2];
    const double zeta = xValues[1];

    double result = 0.;
    // sum over quarks
    for( int i=0; i<4; ++i )
    {
        result += impactFL( Q2, k2, z, zeta, i ) * gluonDensity( xTilde(x,Q2,i), k2 );
    }

    *fval = result;
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
