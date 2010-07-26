/**
  * CouplingConstant.cpp
  * Function implementation.
  *
  * author: Ruben Van Boxem
  *
  **/

// Function include
#include "StrongCoupling.h"

// C++ includes
#include <cmath> // log

double runningAlphaS( const double Q2, const int nf,
               const double lambdaQCD )
{
    return 12.*M_PI / ( (33-2.*nf)*log(Q2/lambdaQCD) );
}



// TODO: running alphaS
