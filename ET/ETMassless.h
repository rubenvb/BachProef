/**
  * TransverseEnergyFlow.h
  * Formulae to calculate ET from main Kwiecinski paper.
  *
  * author: Ruben Van Boxem
  *
  **/

#ifndef ETMASSLESS_H
#define ETMASSLESS_H

namespace ET
{
    namespace massless
    {
        double ET( const double xj, const double Q2 );
        double phiIntegral( const double kp, const double kgamma );
    }
}

#endif // ETMASSLESS_H
