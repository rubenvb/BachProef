#ifndef STRUCTUREFUNCTION_H
#define STRUCTUREFUNCTION_H

// Cubature includes
#include "Cubature/Cubature.h"

// C++ includes
#include <cmath>
#include <stdexcept>
#include <utility>

const double impactFactor( const double qSquared, const double kSquared,
                           const double z, const double zeta )
{
    const double coeff = qSquared / ( 4*M_PI*M_PI );
    const double charge = 4./9. + 1./9. + 1./9.;
    const double differentialFactor = M_PI / kSquared;
    const double numerator = 1 - 2*z*(1-z) - 2*zeta*(1-zeta) + 12*z*(1-z)*zeta*(1-zeta);
    const double denominator = qSquared*z*(1-z) + kSquared*zeta*(1-zeta);
    const double fraction = numerator / denominator;

    return coeff * charge * differentialFactor * fraction;
}

const double gluonDensity( const double x, const double kSquared )
{
    const double sigma0 = 23.03*2.568; // 1 barn = 2.568 (\hbar c)²/Gev²
    const double lambda = .288;
    const double x0 = .000304;

    const double coeff = 3*sigma0 / ( 4*M_PI*M_PI );
    const double R0Squared = pow( x/x0, lambda );

    return coeff * R0Squared * kSquared * kSquared * exp( -R0Squared*kSquared );
}

void func( unsigned ndim, const double* xValues,
           void* input, unsigned fdim,
           double *fval )
{
    double x = static_cast<double*>(input)[0];
    double qSquared = static_cast<double*>(input)[1];
    double kSquared = xValues[0];
    double z = xValues[1];
    double zeta = xValues[2];

    *fval = impactFactor( qSquared, kSquared, z, zeta ) * gluonDensity( x, kSquared );
}

std::pair<double, double> F2( const double x, const double qSquared )
{
    double val = 0.;
    double err = 0.;

    double xMin[] = { 0, 0, 0 };
    double xMax[] = { 1000, 1, 1 };
    double input[] = { x, qSquared };

    bool fail = adapt_integrate( 1, func, input,
                                 3, xMin, xMax,
                                 0, 0, 1e-4,
                                 &val, &err);
    if( fail )
        throw std::runtime_error( "adapt_integrate returned an error." );

    return std::pair<double, double>( val, err );
}

#endif // STRUCTUREFUNCTION_H
