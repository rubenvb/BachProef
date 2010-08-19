/**
  * ETMonteCarlo.h
  * Attempt at using GSL's Monte Carlo integration for ET
  *
  * author: Ruben Van Boxem
  *
  **/

#ifndef ETMONTECARLO_H
#define ETMONTECARLO_H

// GSL includes
#include <gsl/gsl_spline.h>
#include <gsl/gsl_rng.h>

namespace ET
{
    namespace MonteCarlo
    {

        static gsl_spline* spline;
        static gsl_interp_accel* accel;
        static gsl_rng* r;

        void init();
        void deinit();

        const size_t calls = 1000000;

        double integrandET( double x[], size_t dim, void* p );
        double integrandETRunningAlpha( double x[], size_t dim, void* p );

        double ETFlow( const double x, const double Q2,
                       const double xj );
        double ETFlowRunningAlpha( const double x, const double Q2,
                                   const double xj );

        double ETFlowEvol( const double x, const double Q2,
                           const double xj );
        double ETFlowEvolRunningAlpha( const double x, const double Q2,
                                       const double xj );

        namespace Alternate
        {
            double integrandET( double x[], size_t dim, void* p );
            double integrandETRunningAlpha( double x[], size_t dim, void* p );

            double ETFlow( const double x, const double Q2,
                           const double xj );
            double ETFlowRunningAlpha( const double x, const double Q2,
                                       const double xj );
        }
    }

}
#endif // ETMONTECARLO_H
