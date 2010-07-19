/**
  * Massless.h
  * Functions to calculate F2 and FL in the massless quark case.
  *  This file describes the interface (function declarations)
  *
  * author: Ruben Van Boxem
  *
  **/

#ifndef MASSLESS_H
#define MASSLESS_H

namespace SF
{
    namespace massless
    {
        // constants
        const double sigma0 = 23.03*2.57069; // 1 barn = 2.568 (\hbar c)²/Gev²
        const double lambda = .288;
        const double x0 = 3.04e-4;
        const double charge2 = 6./9.;

        double gluonDensity( const double x, const double kSquared );

        double impactF2( const double qSquared, const double kSquared,
                               const double z, const double zeta );
        double impactFL( const double qSquared, const double kSquared,
                               const double z, const double zeta );

        void integrandF2( unsigned /*ndim*/, const double* xValues,
                     void* input, unsigned /*fdim*/,
                     double *fval );
        void integrandFL( unsigned /*ndim*/, const double* xValues,
                     void* input, unsigned /*fdim*/,
                     double *fval );

        double F2( const double x, const double qSquared );
        double FL( const double x, const double qSquared );
   }
}

#endif // MASSLESS_H
