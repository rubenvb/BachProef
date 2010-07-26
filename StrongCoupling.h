/**
  * CouplingConstant.h
  * Contains non-running alphaS definition.
  *  Will provide running alphaS calculation.
  *
  * author: Ruben Van Boxem
  *
  **/

#ifndef COUPLINGCONSTANT_H
#define COUPLINGCONSTANT_H

const double alphaS = .2; // QCD non-running coupling constant

// running coupling, defaults to nf=3 case.
double runningAlphaS( const double Q2, const int nf = 3,
                          const double lambdaQCD = .2 );

#endif // COUPLINGCONSTANT_H
