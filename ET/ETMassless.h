/**
  * TransverseEnergyFlow.h
  * Formulae to calculate ET from main Kwiecinski paper.
  *
  * author: Ruben Van Boxem
  *
  **/

#ifndef ETMASSLESS_H
#define ETMASSLESS_H

// GSL includes
#include <gsl/gsl_spline.h>

// C++ includes
#include <vector>

namespace ET
{
    namespace massless
    {
        // global interpolators
        static gsl_interp_accel *accel_ptr;
        static gsl_spline *spline_ptr;

        const std::vector<double> ETPlot( const double x, const double Q2,
                                          const std::vector<double> &xj );
        double ETFlow( const double x, const double Q2,
                       const double xj );
        void integrandET( unsigned /*ndim*/, const double* xValues,
                          void* input, unsigned /*fdim*/,
                          double *fval );
        double impactET( const double x, const double Q2,
                         const double xj, const double phi,
                         const double kp2, const double kg2 );
        double impactPhi( const double kp2, const double kgamma2, const double phi );

        namespace evolution
        {
            double ETFlow( const double x, const double Q2,
                       const double xj );
            void integrandET( unsigned /*ndim*/, const double* xValues,
                              void* input, unsigned /*fdim*/,
                              double *fval );
            double impactET( const double x, const double Q2,
                             const double xj, const double phi,
                             const double kp2, const double kg2 );
            double impactPhi( const double kp2, const double kgamma2, const double phi );
        }
    }
}

#endif // ETMASSLESS_H
