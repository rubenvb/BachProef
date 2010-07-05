/**
  * Main.cpp
  * Test program for the cubature functions
  *
  * Author: Ruben Van Boxem
  *
  **/

// Cubature include
#include "Cubature/Cubature.h"

// C++ includes
#include <cmath>
#include <iostream>
    using std::cout;
    using std::endl;

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



int main(int argc, char **argv)
{
    double xmin[3] = {-2,-2,-2};
    double xmax[3] = {2,2,2};
    double sigma = 0.5;
    double val;
    double err;

    // adapt_integrate( ndim,
    adapt_integrate( 1, f, &sigma,
                     3, xmin, xmax,
                     0, 0, 1e-4,
                     &val, &err);

    cout << "Computed integral = " << val << " +/- " << err << endl;

    return 0;
}
