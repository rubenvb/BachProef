/**
  * TransverseEnergyFlow.h
  * Formulae to calculate ET from main Kwiecinski paper.
  *
  * author: Ruben Van Boxem
  *
  **/

#ifndef TRANSVERSEENERGYFLOW_H
#define TRANSVERSEENERGYFLOW_H

namespace ET
{
    namespace massless
    {
        double ET( const double xj, const double Q2 );
        double phiIntegral( const double kp, const double kgamma );
    }
}


#endif // TRANSVERSEENERGYFLOW_H
