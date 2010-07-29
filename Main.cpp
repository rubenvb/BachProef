/**
  * Main.cpp
  * Main function with small Cubature test.
  *
  * Author: Ruben Van Boxem
  *
  **/

// BachProef includes
#include "StrongCoupling.h"
#include "StructureFunction.h"
#include "TransverseEnergyFlow.h"
#include "UnintegratedGluonDensity.h"
#include "Plots.h"

// Cubature includes
#include "Cubature/Cubature.h"

// GSL includes
#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>
#include <gsl/gsl_sf_hyperg.h>

// C++ includes
#include <cmath>
#include <iomanip>
    using std::setprecision;
#include <iostream>
    using std::cout;
    using std::endl;

// adapt_integrate testFunction
void func( unsigned /*ndim*/, const double* xValues,
           void*, unsigned /*fdim*/,
           double *fval );
void testIntegration();
void testGSL();
void testSFMassless();
void testSFMassive();
void testUGDMassless();
void testETMassless();
void testInterpolation();

int main()
{
    cout << setprecision(14);

    testGSL();
    //testIntegration();

    //testSFMassless();
    //testSFMassive();

    //testUGDMassless();

    testETMassless();

    //outputSFMassive();
    //outputSFMassless();
    //outputUGDMassless();

    //testInterpolation();

    return 0;
}

void func( unsigned /*ndim*/, const double* xValues,
             void*, unsigned /*fdim*/,
             double *fval )
{
    const double x = xValues[0];
    const double y = xValues[1];
    const double z = xValues[2];

    *fval =  sin(x*y*z)/(x*y*z);
}
void testIntegration()
{
    double val = 0.;
    double err = 0.;
    double xMin[] = { 0., 0., 0. };
    double xMax[] = { 1., 1., 1.};

    adapt_integrate( 1, func, NULL,
                     3, xMin, xMax,
                     0, 0, 1e-4,
                     &val, &err );

    cout << "testFunction is = .99389 ?=\t" << val << endl;
}
void testGSL()
{
}

void testSFMassless()
{
    using namespace SF::massless;

    cout << "-----------\nSF MASSLESS\n-----------" << endl;

    cout << "Gluon density function" << endl;
    cout << "f(.001,1)\t= 7.74 ?=\t" << gluonDensity( .001, 1 ) << endl;
    cout << "f(.00001,3.6)\t= 28.36 ?=\t" << gluonDensity( .00001, 3.6 ) << endl;

    cout << "Impact factors" << endl;
    cout << "IL(20,10,.5,.5) = .0014147 ?=\t" << impactFL( 20, 10, .5, .5 ) << endl;
    cout << "I2(10,10,.5,.5)\t= .00159 ?=\t" << impactF2(10,10,.5,.5) << endl;

    cout << "FL" << endl;
    cout << "FL(.0001,60)\t= .403459 ?=\t" << FL( .0001, 60 ) << endl;
    cout << "FL(.0001,24)\t= .370688 ?=\t" << FL( .0001, 24 ) << endl;

    cout << "F2" << endl;
    cout << "F2(.00001,1.5)\t= .992435 ?=\t" << F2( .00001, 1.5 ) << endl;
    cout << "F2(.001,2)\t= .576248 ?=\t" << F2( .001, 2. ) <<endl;
}
void testSFMassive()
{
    using namespace SF::massive;

    cout << "-----------\nSF MASSIVE\n-----------" << endl;

    cout << "Light quarks" << endl;
    cout << "Gluon density function" << endl;
    cout << "f(.001,1), Q2=10\t= 6.0929 ?=\t" << gluonDensity( xTilde(.001,10,0), 1 ) << endl;
    cout << "f(.00001,3.6), Q2=20\t= 21.802 ?=\t" << gluonDensity( xTilde(.00001,20,0), 3.6 ) << endl;
    cout << "Impact factors" << endl;
    cout << "impactFL(20,15,.5,.5)\t= .0005356 ?=\t" << impactFL( 20, 15, .5, .5, 0 ) << endl;
    cout << "impactFT(10,15,.5,.5)\t= .0001896 ?=\t" << impactFT( 10, 15, .5, .5, 0 ) << endl;
    cout << "impactF2(10,10,.5,.5)\t= .0010544 ?=\t" << impactF2( 10, 10, .5, .5, 0 ) << endl;

    cout << "Charm quark" << endl;
    cout << "Gluon density function" << endl;
    cout << "f(.001,1), Q2=10\t= 4.5569 ?=\t" << gluonDensity( xTilde(.001,10,2), 1 ) << endl;
    cout << "f(.00001,3.6), Q2=20\t= 18.5874 ?=\t" << gluonDensity( xTilde(.00001,20,2), 3.6 ) << endl;
    cout << "Impact factors" << endl;
    cout << "impactFL(20,15,.5,.5)\t= .0002957 ?=\t" << impactFL( 20, 15, .5, .5, 2 ) << endl;
    cout << "impactFT(10,15,.5,.5)\t= .000208776 ?=\t" << impactFT( 10, 15, .5, .5, 2 ) << endl;
    cout << "impactF2(10,10,.5,.5)\t= .000627762 ?=\t" << impactF2( 10, 10, .5, .5, 2 ) << endl;

    cout << "Structure Functions" << endl;
    cout << "FL" << endl;
    cout << "FL(.0001,60)\t= .41642 ?=\t" << FL( .0001, 60 ) << endl;
    cout << "FL(.0001,24)\t= .34798 ?=\t" << FL( .0001, 24 ) << endl;

    cout << "F2" << endl;
    cout << "F2(1e-5,2)\t= 1.14777 ?=\t" << F2( .00001, 2 ) << endl;
    cout << "F2(1e-5,1.5)\t= .974856 ?=\t" << F2( .00001, 1.5 ) << endl;
    cout << "F2(1e-3,2)  \t= .519629 ?=\t" << F2( .001, 2. ) <<endl;

    cout << "F2 by integrating twice" << endl;
    cout << "F2(1e-5,2)\t=" << FT(1e-5,2) + FL(1e-5,2) << endl;
}

void testUGDMassless()
{
    using namespace UGD::massless;
    cout << "-----------\nUGD MASSLESS\n-----------" << endl;

    cout << "Running strong coupling." << endl;
    cout << "alphaS(10)\t= .3569 ?=\t" << runningAlphaS(10.) << endl;

    cout << "no evolution." << endl;
    cout << "impactF0(4,8,.5,.5) = .1978 ?=\t" << impactF0(4,8,.5,.5) << endl;
    cout << "F0(10,15) = .5823 ?=\t" << F0(10,15) << endl;

    cout << "With evolution." << endl;
    cout << "impactF0(.001,4,8,.5,.5)\t= .21656 ?=\t" << impactF0Evol(.001,4,8,.5,.5) << endl;
    cout << "F0(.0001,5,10)\t= .36289 ?=\t" << F0Evol(.0001,5,10) << endl;
}

void testETMassless()
{
    using namespace ET::massless;

    cout << "-----------\nET MASSLESS NO EVOLUTION\n-----------" << endl;
    cout << "impactPhi(20,30,pi) = .158349 ?=\t" << impactPhi(20,30,M_PI) << endl;
    //cout << "impactET(.0001,20,.01,2,3) = .128646  ?=\t " << impactET(.0001, 20, .01, M_PI, 2, 3) << endl;
    cout << "ET() = ????? ?=\t " << ETFlow(.0001, 10., .0001 ) << endl;
}
void testInterpolation()
{
/*
 *  create interpolating spline stuff
 */
    const size_t nPoints = 20;
    gsl_interp_accel* accel = gsl_interp_accel_alloc();
    gsl_spline* spline = gsl_spline_alloc( gsl_interp_cspline, nPoints );

    double kgammaInt[nPoints];

    double fancyF2Int[nPoints];
    const double deltak = 10./(nPoints-1);
    for( int i =0; i<nPoints; ++i )
    {
        kgammaInt[i] = deltak*i;
        fancyF2Int[i] = UGD::massless::F0( kgammaInt[i], 10 );
    }
    gsl_spline_init( spline, kgammaInt, fancyF2Int, nPoints );

    cout << "Interpolated value: fancyF2( 5.333, 10 ) = " << gsl_spline_eval( spline, 5.333, accel ) << endl;
    cout << "Fully calculated value: " << UGD::massless::F0(5.333,10) << endl;

    // Step 5: free the accelerator and spline object
    gsl_spline_free( spline );
    gsl_interp_accel_free( accel );
}
