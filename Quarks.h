/**
  * Quarks.h
  * Definitions of some recurring quark properties:
  *  - mass
  *  - charge
  *
  * author: Ruben Van Boxem
  *
  **/

#ifndef QUARKS_H
#define QUARKS_H

namespace quarks
{
    const double charge2[] = { 4./9, 1./9, 4./9, 1./9 }; // { u, d, c, s }
    const double mass2[] = { .14*.14, .14*.14, 1.5*1.5, .14*.14 }; // { u, d, c, s }
}

#endif // QUARKS_H
