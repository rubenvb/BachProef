/**
  * Main.cpp
  * Test program for the cubature functions
  *
  * Author: Ruben Van Boxem
  *
  **/

// BachProef includes
#include "StructureFunction.h"

// Cubature include
#include "Cubature/Cubature.h"

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
    cout << "f(.0001,10) = " << gluonDensity( .0001, 10 ) << endl;
    cout << "f(.0001,20) = " << gluonDensity( .0001, 20 ) << endl;
    cout << "I(10,10,.5,.5) = " << impactFactor( 10, 10, .5, .5 )*6/9 << endl;

    const double qSquared[] = { 1.5, 2, 2.5, 3.5, 4.5, 5, 6.5, 8.5, 10, 12, 15, 18 };
    pair<double,double> result; // F2 with error

    double x = 1e-5;
    cout << "F2 with x=1e-5" << endl;
    for( int i=0; i<12; ++i )
    {
        result = F2( x, qSquared[i] );
        cout << "F2( 1e-5, " << qSquared[i] << ")\t= " << result.first << " +/- " << result.second << endl;
    }

    x = 1e-4;
    cout << "F2 with x=1e-4" << endl;
    for( int i=0; i<12; ++i )
    {
        result = F2( x, qSquared[i] );
        cout << "F2( 1e-4, " << qSquared[i] << ")\t= " << result.first << " +/- " << result.second << endl;
    }

    x = 1e-3;
    cout << "F2 with x=1e-3" << endl;
    for( int i=0; i<12; ++i )
    {
        result = F2( x, qSquared[i] );
        cout << "F2( 1e-3, " << qSquared[i] << ")\t= " << result.first << " +/- " << result.second << endl;
    }
}
