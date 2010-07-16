/**
  * Main.cpp
  * Main function with small Cubature test.
  *
  * Author: Ruben Van Boxem
  *
  **/

// BachProef includes
#include "StructureFunction.h"
#include "Plots.h"

// Cubature includes
#include "Cubature/Cubature.h"

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
void testStructureFunctions();

int main()
{
    cout << setprecision(14);

    testIntegration();
    testStructureFunctions();

    calcOutput();

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
void testStructureFunctions()
{
    using namespace SF::massless;

    cout << "Gluon density function" << endl;
    cout << "f(.001,1)\t= 7.74 ?=\t" << gluonDensity( .001, 1 ) << endl;
    cout << "f(.00001,3.6)\t= 28.36 ?=\t" << gluonDensity( .00001, 3.6 ) << endl;

    cout << "Impact factors" << endl;
    cout << "I2(10,10,.5,.5)\t= .00159 ?=\t" << impactFactorF2(10,10,.5,.5) << endl;
    cout << "IL(20,10,.5,.5) = .0014147 ?=\t" << impactFactorFL( 20, 10, .5, .5 ) << endl;

    cout << "FL" << endl;
    cout << "FL(.0001,60)\t= .403459 ?=\t" << FL( .0001, 60 ) << endl;
    cout << "FL(.0001,24)\t= .370688 ?=\t" << FL( .0001, 24 ) << endl;

    cout << "F2" << endl;
    cout << "F2(.00001,1.5)\t= .992435 ?=\t" << F2( .00001, 1.5 ) << endl;
    cout << "F2(.001,2)\t= .576248 ?=\t" << F2( .001, 2. ) <<endl;
}
