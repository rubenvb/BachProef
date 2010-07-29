/**
  * TransverseEnergyFlow.cpp
  * Function implementation.
  *
  * author: Ruben Van Boxem
  *
  **/

// Function include
#include "TransverseEnergyFlow.h"

// BachProef includes
#include "StructureFunction.h"
#include "StrongCoupling.h"
#include "UnintegratedGluonDensity.h"

// Cubature includes
#include "Cubature/Cubature.h"

// GSL includes
#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>

// C++ includes
#include <cmath> // M_PI, sqrt
#include <iostream>
    using std::cout;
    using std::endl;
#include <stdexcept>
    using std::runtime_error;
#include <vector>
    using std::vector;

namespace ET
{
namespace massless
{

const vector<double> ETPlot( const double x, const double Q2,
                             const vector<double> &xj )
{


}

double ETFlow( const double x, const double Q2,
               const double xj )
{
    const double limit = Q2/(x/xj);
    const double F2 = SF::massless::F2( x, Q2 );
    double val = 0.;
    double err = 0.;

/*
 *  Interpolate fancyF2 (photon hadron structure function)
 */
    const size_t nPoints = 30;
    accel_ptr = gsl_interp_accel_alloc();
    spline_ptr = gsl_spline_alloc( gsl_interp_cspline, nPoints );
    cout << "allocated splines" << endl;
    double kgammaInt[nPoints];
    double fancyF2Int[nPoints];
    const double deltak = limit/(nPoints-1);
    for( int i =0; i<nPoints; ++i )
    {
        kgammaInt[i] = deltak*i;
        fancyF2Int[i] = UGD::massless::F0(kgammaInt[i], Q2);
    }
    gsl_spline_init( spline_ptr, kgammaInt, fancyF2Int, nPoints );
    cout << "spline ready for use" << endl;
    // phi, kp2, kg2
    double xMin[] = { 0., 0. };
    double xMax[] = { limit, limit };
    double input[] = { x, Q2, xj, M_PI };

    const bool fail = adapt_integrate( 1, integrandET, input,
                                       3, xMin, xMax,
                                       0, 0, 1e-4,
                                       &val, &err);
    // deallocate spline stuff before possible throw
    gsl_spline_free (spline_ptr);
    gsl_interp_accel_free (accel_ptr);

    if( fail )
        throw runtime_error( "adapt_integrate returned an error." );

    return val/F2;
}
void integrandET( unsigned /*ndim*/, const double* xValues,
                  void* input, unsigned /*fdim*/,
                  double* fval )
{
    const double x = static_cast<double*>(input)[0];
    const double Q2 = static_cast<double*>(input)[1];
    const double xj = static_cast<double*>(input)[2];
    const double phi = static_cast<double*>(input)[3];
    //const double phi = xValues[0];
    const double kp2 = xValues[0];
    const double kg2 = xValues[1];

    //cout << "integrandET called at\nphi=" << phi
    //        << "\nkp2=" << kp2
    //        << "\nkg2=" << kg2 << endl;

    const double result = impactET( x, Q2, xj, phi, kp2, kg2 );

    *fval = result;
}
double impactET( const double x, const double Q2,
                 const double xj, const double phi,
                 const double kp2, const double kg2 )
{
    const double coeff = 3. * runningAlphaS(kp2) / M_PI;
    const double fancyF2 = gsl_spline_eval( spline_ptr, kg2, accel_ptr );
    //const double fancyF2 = UGD::massless::F0( kg2, Q2 );
    const double f = SF::massless::gluonDensity( xj, kp2 );
    const double phipart = impactPhi( kp2, kg2, phi );

    return coeff *fancyF2 * f * phipart;
}

double impactPhi( const double kp2, const double kgamma2, const double phi )
{
    return 1/(2*M_PI) * 1/sqrt( kp2 + kgamma2 + 2*sqrt(kp2*kgamma2)*cos(phi) );
}

} // namespace massless

} // namespace ET
