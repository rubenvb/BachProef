#ifndef STRUCTUREFUNCTION_H
#define STRUCTUREFUNCTION_H

// BachProef includes
#include "GluonDensity.h"

// Cubature includes
#include "Cubature/Cubature.h"

// C++ includes
#include <cmath>
#include <iostream>
    using std::cerr;
    using std::endl;
#include <utility>
    using std::pair;

inline void func( unsigned ndim, const double *xValues,
                  void *input, unsigned fdim,
                  double *fval )
{
    double x = static_cast<double*>(input)[0];
    double Qsquared = static_cast<double*>(input)[1];
    double kSquared = xValues[0];
    double z = xValues[1];
    double zeta = xValues[2];

    double density = gluonDensity( x, kSquared );
    double numerator = 1 - 2*z*(1-z) - 2*zeta*(1-zeta) + 12*z*(1-z)*zeta*(1-zeta);
    double denominator = Qsquared*z*(1-z) + kSquared*zeta*(1-zeta);

    *fval = density * numerator / denominator;
}

// Calculates F2 and returns value and error in a std::pair
inline const pair<double,double> F2( double x, double Qsquared )
{
    double ans = Qsquared / (4*M_PI);
    const double e_q[3] = { 2/3, -1/3, 2/3 };
    // integration boundaries { kSquared, z, zeta }
    double xmin[3] = { 0, 0, 0 }; // 0, 0, 0
    double xmax[3] = { 10000, 1, 1 }; // inf, 1, 1

    double input[2] = { x, Qsquared };
    double val = 0.;
    double err = 0.;
    bool fail = adapt_integrate( 1, func, input,  // fdim, integrand, fdata
                                 3, xmin, xmax, // dim, xbound, ybound
                                 0, 0, 1e-4,    // maxEval, absError, relError
                                 &val, &err);   // value, error
    if( fail )
        cerr << "Cubature returned an error (out of memory)" << endl;

    // sum over u,d,c quarks
    for( size_t i=0; i<3; ++i )
    {
        ans += e_q[i]*e_q[i] * val;
    }

    return pair<double,double>(ans, err);
}



#endif // STRUCTUREFUNCTION_H
