#ifndef STRUCTUREFUNCTIONPLOTS_H
#define STRUCTUREFUNCTIONPLOTS_H

// BachProef includes
#include "StructureFunction.h"

// C++ includes
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

const size_t nPoints = 100;

void calcOutput()
{
    std::ofstream file;

    std::vector<double> x(nPoints);

/*
 * FL(x) for different values of Q²
 */
    // x = logspace( 1e-4, 1e-1, 100 )
    double current = 1e-4 * 1.07;
    for( size_t i=0; i<nPoints ; ++i )
    {
        current *= 1.07;
        x[i] = current;
    }
    // Q² values
    std::vector<double> Q2 = { 24, 32, 45, 60, 80, 110 };

    // FL
    file.open( "FL.txt" );
    std::cout << "Calculating FL" << std::endl;
    for( size_t i=0; i<nPoints; ++i )
    {
        file << x.at(i) << "\t";
        for( size_t j=0; j<6; ++j )
        {
            file << FL( x.at(i), Q2.at(j) ) << "\t";
        }
        file << "\n";
    }
    file.close();

/*
 * F2(x) for same values Q²
 */
    // x = logspace( 1e-5, 1e-2, 100 )
    current = 1e-5 * 1.07;
    for( size_t i=0; i<nPoints ; ++i )
    {
        current *= 1.07;
        x[i] = current;
    }
    // Q² values
    Q2 = { 1.5, 2, 2.5, 3.5, 4.5, 5 };
    // F2
    file.open( "F2.txt" );
    std::cout << "Calculating F2" << std::endl;
    for( size_t i=0; i<nPoints; ++i )
    {
        file << x.at(i) << "\t";
        for( size_t j=0; j<6; ++j )
        {
            file << F2( x.at(i), Q2.at(j) ) << "\t";
        }
        file << "\n";
    }
    file.close();
}

#endif // STRUCTUREFUNCTIONPLOTS_H
