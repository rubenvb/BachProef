/**
  * Massless.h
  * Provides a calculation for the unintegrated gluon density for nf=3.
  *
  * author: Ruben Van Boxem
  *
  **/

#ifndef UGDMASSLESS_H
#define UGDMASSLESS_H

namespace UGD
{
    namespace massless
    {
        const double lambda = .288;
        const double x0 = 3.04e-4;
        const double charge2 = 6./9;
        const double nf = 3.;

        double impactF0( const double k2, const double Q2,
                         const double eta, const double rho );
        double impactF0Evol( const double x,
                             const double k2, const double Q2,
                             const double eta, const double rho );
        void integrandF0( unsigned /*ndim*/, const double* xValues,
                          void* input, unsigned /*fdim*/,
                          double *fval );
        void integrandF0Evol( unsigned /*ndim*/, const double* xValues,
                              void* input, unsigned /*fdim*/,
                              double *fval );
        double F0( const double k2, const double Q2 );
        double F0Evol( const double x,
                       const double k2, const double Q2 );

    }
}


#endif // UGDMASSLESS_H
