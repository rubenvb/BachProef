/**
  * ETMonteCarlo.cpp
  * Function implementation.
  *
  * author: Ruben Van Boxem
  *
  **/

// Function include
#include "ETMonteCarlo.h"

// BachProef includes
#include "StrongCoupling.h"
#include "StructureFunction.h"
#include "UnintegratedGluonDensity.h"

// GSL includes
#include <gsl/gsl_monte.h>
#include <gsl/gsl_monte_vegas.h>
#include <gsl/gsl_spline.h>

// C++ includes
#include <cmath> // M_PI, cos
#include <ctime> // time()
#include <iostream>
    using std::cout;
    using std::endl;


void init()
{
    gsl_rng_env_setup();
    const gsl_rng_type* T = gsl_rng_default;
    r = gsl_rng_alloc( T );
    gsl_rng_set( r, time(0) );
}
void deinit()
{
    gsl_rng_free( r );
}

double ETFlow( const double x, const double Q2,
           const double xj )
{
    const double limit = Q2/(x/xj);
    const double F2 = SF::massless::F2( x, Q2 );

    // fancyF2 interpolation
    const size_t nPoints = 30;
    accel = gsl_interp_accel_alloc();
    spline = gsl_spline_alloc( gsl_interp_cspline, nPoints );
    //cout << "allocated splines" << endl;
    double kgammaInt[nPoints];
    double fancyF2Int[nPoints];
    const double deltak = limit/(nPoints-1);
    for( int i =0; i<nPoints; ++i )
    {
        kgammaInt[i] = deltak*i;
        fancyF2Int[i] = UGD::massless::F0(kgammaInt[i], Q2);
    }
    gsl_spline_init( spline, kgammaInt, fancyF2Int, nPoints );
    /*cout << "Checking spline validity: " << endl;
    for( int i=0; i<nPoints; ++i )
    {
        cout << "Exact value: " << UGD::massless::F0( i*deltak+.1,Q2) << "\t"
               << gsl_spline_eval(spline, i*deltak+.1, accel) << endl;
    }
    cout << "spline ready for use" << endl;*/

    // integration
    double res = 0.;
    double err = 0.;
    const size_t calls = 1000000;
    // phi, kp2, kg2
    double xl[3] = { 0., 0., 0. };
    double xu[3] = { 2*M_PI, limit, limit };

    double params[] = { xj };

    gsl_monte_function F;
    F.dim = 3;
    F.params = &params;
    F.f = &integrandET;

    gsl_monte_vegas_state *s = gsl_monte_vegas_alloc (3);
    gsl_monte_vegas_integrate( &F, xl, xu, 3, calls, r, s,
                               &res, &err);
    cout << err << endl;

    // free the resources
    gsl_spline_free( spline );
    gsl_interp_accel_free( accel );
    gsl_monte_vegas_free( s );

    return res/F2;
}

double integrandET( double x[], size_t dim, void* p )
{
    const double phi = x[0];
    const double kp2 = x[1];
    const double kg2 = x[2];
    const double xj = static_cast<double*>(p)[0];

    const double coeff = 3. * alphaS/*runningAlphaS(kp2+kg2+2*sqrt(kp2*kg2)*cos(phi))*/ / M_PI;
    const double fancyF2 = gsl_spline_eval( spline, kg2, accel );
    const double f = SF::massless::gluonDensity( xj, kp2 );
    const double phiPart = 1/(2*M_PI) * 1/sqrt( kp2+kg2+2*sqrt(kp2*kg2)*cos(phi) );

    return coeff*fancyF2*f*phiPart/(kp2*kg2);
}


