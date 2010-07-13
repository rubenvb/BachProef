/**
  * Main.cpp
  * Test program for the cubature functions
  *
  * Author: Ruben Van Boxem
  *
  **/

// BachProef includes
#include "StructureFunction.h"

// C++ includes
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



int main()
{
    cout << setprecision(14);
    cout << "f(.001,1)\t= 7.74 ?=\t" << gluonDensity( .001, 1 ) << endl;
    cout << "f(.00001,3.6)\t= .278 ?=\t" << gluonDensity( .00001, 3.6 ) << endl;
    cout << "I2(20,10,.5,.5)\t= ?????? ?=\t" << F2::impactFactor(20,10,.5,.5) << endl;
    cout << "I2(10,10,.5,.5)\t= .00159 ?=\t" << F2::impactFactor(10,10,.5,.5) << endl;
    cout << "IL(10,20,.7,.15)= .0048876 ?=\t" << FL::impactFactor( 10, 20, .7, .15 ) << endl;
    cout << "IL(20,20,.7,.15)= .0067 ?=\t" << FL::impactFactor( 20, 20, .7, .15 ) << endl;

    cout << "FL(.0001,32)\t= .286 ?=\t" << fL( .0001, 32 ).first << endl;
    cout << "FL(.0001,24)\t= .278 ?=\t" << fL( .0001, 24 ).first << endl;

    const double qSquared[] = { 1.5, 2, 2.5, 3.5, 4.5, 5 };
    pair<double,double> result; // F2 with error

    double x = 1e-5;
    cout << "F2 with x=1e-5" << endl;
    for( int i=0; i<6; ++i )
    {
        result = f2( x, qSquared[i] );
        cout << "F2( 1e-5, " << qSquared[i] << " )\t=\t" << result.first << endl;
    }

    x = 1e-4;
    cout << "F2 with x=1e-4" << endl;
    for( int i=0; i<6; ++i )
    {
        result = f2( x, qSquared[i] );
        cout << "F2( 1e-4, " << qSquared[i] << " )\t=\t" << result.first << endl;
    }

    x = 1e-3;
    cout << "F2 with x=1e-3" << endl;
    for( int i=0; i<6; ++i )
    {
        result = f2( x, qSquared[i] );
        cout << "F2( 1e-3, " << qSquared[i] << " )\t=\t" << result.first << endl;
    }
}
