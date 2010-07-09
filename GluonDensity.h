#ifndef GLUONDENSITY_H
#define GLUONDENSITY_H

// C++ includes
#include <cmath> // exp()

inline const double R_0Squared( const double x )
{
    // Q_0² := 1
    const double lambda = .277;
    const double x_0 = .000041;
    return pow( x/x_0, lambda );
}
inline const double gluonDensity( const double x, const double kSquared )
{
    // Source: GBW: Saturation Effects in DIS... p10
    const double sigma_0 = 74.78; // 1/GeV, ~ 29,12 mb

    double ans = 3 * sigma_0 * R_0Squared(x) * kSquared * kSquared
                 * exp( -R_0Squared(x) * kSquared )
                 / (4 * M_PI * M_PI);
    return ans;
}

#endif // GLUONDENSITY_H
