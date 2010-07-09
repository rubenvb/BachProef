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
#include <iomanip>
    using std::setprecision;
#include <iostream>
    using std::cout;
    using std::endl;
#include <utility>
    using std::pair;

void f( unsigned ndim, const double *x, void *fdata, unsigned fdim, double *fval)
{
    double sigma = *((double *) fdata); // we can pass s via fdata argument
    double sum = 0;
    unsigned i;
    for (i = 0; i < ndim; ++i)
    {
        sum += x[i] * x[i];
    }
    // compute the output value: note that fdim should == 1 from below
    fval[0] = exp(-sigma * sum);
}

int main()
{
    double xmin[3] = {-2,-2,-2};
    double xmax[3] = {2,2,2};
    double sigma = 0.5;
    double val;
    double err;

    // adapt_integrate( ndim,
    bool fail = adapt_integrate( 1, f, &sigma,  // fdim, integrand, fdata
                                 3, xmin, xmax, // dim, xbound, ybound
                                 0, 0, 1e-4,    // maxEval, absError, relError
                                 &val, &err);   // value, error

    if( !fail )
        cout << "Computed integral = " << val << " +/- " << err << endl;
    else
        cout << "Out of memory" << endl;


    pair<double,double> result = F2( .00001, 10 );

    cout << "Result is: " << setprecision(14)
            << result.first << " +/- " << result.second << endl;

}
