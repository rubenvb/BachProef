/**
  * Massless.h
  * Functions to calculate F2 and FL in the massless quark case.
  *  This file describes the interface (function declarations)
  *
  * author: Ruben Van Boxem
  *
  **/

#ifndef SFMASSLESS_H
#define SFMASSLESS_H

namespace SF
{
    namespace massless
    {
        // constants
        const double sigma0 = 23.03*2.57069; // 1 barn = 2.568 (\hbar c)²/Gev²
        const double lambda = .288;
        const double x0 = 3.04e-4;
        const double charge2 = 6./9.;

        double gluonDensity( const double x, const double k2 );

        double impactF2( const double Q2, const double k2,
                         const double z, const double zeta );
        double impactFL( const double Q2, const double k2,
                         const double z, const double zeta );

        void integrandF2( unsigned /*ndim*/, const double* xValues,
                          void* input, unsigned /*fdim*/,
                          double *fval );
        void integrandFL( unsigned /*ndim*/, const double* xValues,
                          void* input, unsigned /*fdim*/,
                          double *fval );

        double F2( const double x, const double Q2 );
        double FL( const double x, const double Q2 );
   }
}

#endif // SFMASSLESS_H
