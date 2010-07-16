/**
  * Massives.h
  * Functions to calculate F2 and FL in the massive quark case (u,d,c,s).
  *  This file describes the interface (function declarations).
  *
  * author: Ruben Van Boxem
  *
  **/

#ifndef MASSIVE_H
#define MASSIVE_H

namespace SF
{
    namespace massive
    {
        // constants
        const double sigma0 = 29.12*2.57069; // 1 barn = 2.568 (\hbar c)²/Gev²
        const double lambda = .277;
        const double x0 = .000041;
        const double charge2[] = { 4./9, 1./9, 4./9, 1./9 }; // { u, d, c, s }
        const double mass2[] = { .14, .14, 1.5, .14 }; // { u, d, c, s }

        double gluonDensity( const double x, const double kSquared );
        double impactFactorF2( const double qSquared, const double kSquared,
                               const double z, const double zeta );
        double impactFactorFL( const double qSquared, const double kSquared,
                               const double z, const double zeta );
        void integrandF2( unsigned /*ndim*/, const double* xValues,
                     void* input, unsigned /*fdim*/,
                     double *fval );
        void integrandFL( unsigned /*ndim*/, const double* xValues,
                     void* input, unsigned /*fdim*/,
                     double *fval );
        double F2( const double x, const double qSquared );
        double F2( const double x, const double qSquared );
   }
}

#endif // MASSIVE_H
