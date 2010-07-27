/**
  * Massives.h
  * Functions to calculate F2 and FL in the massive quark case (u,d,c,s).
  *  This file describes the interface (function declarations).
  *
  * author: Ruben Van Boxem
  *
  **/

#ifndef SFMASSIVE_H
#define SFMASSIVE_H

namespace SF
{
    namespace massive
    {
        // constants
        const double sigma0 = 29.12*2.57069; // 1 barn = 2.568 (\hbar c)²/Gev²
        const double lambda = .277;
        const double x0 = .41e-4;

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

        void integrandFL( unsigned /*ndim*/, const double* xValues,
                     void* input, unsigned /*fdim*/,
                     double *fval );
        void integrandFT( unsigned /*ndim*/, const double* xValues,
                     void* input, unsigned /*fdim*/,
                     double *fval );
        void integrandF2( unsigned /*ndim*/, const double* xValues,
                     void* input, unsigned /*fdim*/,
                     double *fval );

        double FL( const double x, const double Q2 );
        double FT( const double x, const double Q2 );
        double F2( const double x, const double Q2 );
   }
}

#endif // MASSIVE_H
