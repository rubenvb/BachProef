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

static gsl_spline* spline;
static gsl_interp_accel* accel;
static gsl_rng* r;

void init();
void deinit();
double ETFlow( const double x, const double Q2,
           const double xj );
double integrandET( double x[], size_t dim, void* p );



#endif // ETMONTECARLO_H
