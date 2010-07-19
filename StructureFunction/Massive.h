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
        const double x0 = .41e-4;
        const double charge2[] = { 4./9, 1./9, 4./9, 1./9 }; // { u, d, c, s }
        const double mass2[] = { .14*.14, .14*.14, 1.5*1.5, .14*.14 }; // { u, d, c, s }

        double xTilde( const double x, const double Q2, const int quark );

        double gluonDensity( const double xTilde, const double k2 );

        double impactFT( const double Q2, const double k2,
                               const double z, const double zeta,
                               const int quark );
        double impactFL( const double Q2, const double k2,
                               const double z, const double zeta,
                               const int quark );
        double impactF2( const double Q2, const double k2,
                               const double z, const double zeta,
                               const int quark );

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

#endif // MASSIVE_H
