/**
  * Main.cpp
  * Test program for the cubature functions
  *
  * Author: Ruben Van Boxem
  *
  **/

// BachProef includes
#include "StructureFunction.h"

// Cubpack includes
#include "Stroud/Stroud.h"

// C++ includes
#include <algorithm>
    using std::max_element;
    using std::min_element;
#include <cmath> // exp()
#include <fstream>
    using std::ofstream;
#include <iomanip>
    using std::setprecision;
#include <iostream>
    using std::cout;
    using std::endl;
#include <utility>
    using std::pair;

// adapt_integrate testFunction
void func( unsigned /*ndim*/, const double* xValues,
             void*, unsigned /*fdim*/,
             double *fval )
{
    const double x = xValues[0];
    const double y = xValues[1];
    const double z = xValues[2];

    *fval =  sin(x*y*z)/(x*y*z);
    //*fval = x*x*y*z*z*z;
}

int main()
{
    cout << setprecision(14);

    double val = 0.;
    double err = 0.;
    double xMin[] = { 0., 0., 0. };
    double xMax[] = { 1., 1., 1.};

    adapt_integrate( 1, func, NULL,
                     3, xMin, xMax,
                     0, 0, 1e-4,
                     &val, &err );



    cout << "testFunction is = " << 0.8468 << " ?=\t" << val << endl;

    cout << "Gluon density function" << endl;
    cout << "f(.001,1)\t= 7.74 ?=\t" << gluonDensity( .001, 1 ) << endl;
    cout << "f(.00001,3.6)\t= 28.36 ?=\t" << gluonDensity( .00001, 3.6 ) << endl;

    cout << "Impact factors" << endl;
    cout << "I2(10,10,.5,.5)\t= .00159 ?=\t" << F2::impactFactor(10,10,.5,.5) << endl;
    cout << "IL(20,10,.5,.5) = .0014147 ?=\t" << FL::impactFactor( 20, 10, .5, .5 ) << endl;

    cout << "FL" << endl;
    cout << "FL(.0001,60)\t= .290 ?=\t" << fL( .0001, 60 ).first << " +- " << fL( .0001, 60 ).second << endl;
    cout << "FL(.0001,24)\t= .307 ?=\t" << fL( .0001, 24 ).first << " +- " << fL( .0001, 24 ).second <<endl;

    cout << "F2" << endl;
    cout << "F2(.00001,1.5)\t= .9<x<1 ?=\t" << f2( .00001, 1.5 ).first << " +- " << f2( .00001, 1.5 ).second << endl;
    cout << "F2(.00001,2)\t= 1.1<x<1.2 ?=\t" << f2( .00001, 2. ).first << " +- " << f2( .00001, 2. ).second <<endl;
}
