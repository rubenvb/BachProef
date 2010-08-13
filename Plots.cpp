/**
  * Plots.cpp
  * Function implementation
  *
  * author: Ruben Van Boxem
  *
  **/

// Function includes
#include "Plots.h"

// BachProef includes
#include "StructureFunction.h"
#include "UnintegratedGluonDensity.h"

// C++ includes
#include <iostream>
    using std::cout;
    using std::endl;
#include <fstream>
    using std::ofstream;
#include <vector>
    using std::vector;

void outputSFMassless()
{
    using SF::massless::F2;
    using SF::massless::FL;

    const size_t nPoints = 20;
    ofstream file;
    vector<double> x;
    vector<double> Q2 = { 12., 15., 24., 60., 80., 110. };
/*
 * FL(x) for different values of Q²
 */
    // x = logspace( 1e-4, 1e-1, 100 )
    double current = 1e-4 / 1.44;
    for( size_t i=0; i<nPoints ; ++i )
    {
        current *= 1.44;
        x.push_back( current );
    }
    // FL
    file.open( "FLMassless.txt" );
    cout << "Calculating Massless FL plot data." << endl;
    for( size_t i=0; i<nPoints; ++i )
    {
        file << x.at(i) << "\t";
        for( size_t j=0; j<Q2.size(); ++j )
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
    current = 1e-5 / 1.44;
    for( size_t i=0; i<nPoints ; ++i )
    {
        current *= 1.44;
        x.at(i) = current;
    }
    // F2
    file.open( "F2Massless.txt" );
    cout << "Calculating Massless F2 plot data." << endl;
    for( size_t i=0; i<nPoints; ++i )
    {
        file << x.at(i) << "\t";
        for( size_t j=0; j<Q2.size(); ++j )
        {
            file << F2( x.at(i), Q2.at(j) ) << "\t";
        }
        file << "\n";
    }
    file.close();
}

void outputSFMassive()
{
    using SF::massive::F2;
    using SF::massive::FL;

    const size_t nPoints = 20;
    ofstream file;
    vector<double> x(nPoints);
    vector<double> Q2 = { 12., 15., 24., 60., 80., 110. };

/*
 * FL(x) for different values of Q²
 */
    // x = logspace( 1e-4, 1e-1, 100 )
    double current = 1e-4 / 1.44;
    for( size_t i=0; i<nPoints ; ++i )
    {
        current *= 1.44;
        x.at(i) = current;
    }
    // FL
    file.open( "FLMassive.txt" );
    cout << "Calculating Massive FL plot data." << endl;
    for( size_t i=0; i<nPoints; ++i )
    {
        file << x.at(i) << "\t";
        for( size_t j=0; j<Q2.size(); ++j )
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
    current = 1e-5 / 1.44;
    for( size_t i=0; i<nPoints ; ++i )
    {
        current *= 1.44;
        x.at(i) = current;
    }
    // F2
    file.open( "F2Massive.txt" );
    cout << "Calculating Massive F2 plot data." << endl;
    for( size_t i=0; i<nPoints; ++i )
    {
        file << x.at(i) << "\t";
        for( size_t j=0; j<Q2.size(); ++j )
        {
            file << F2( x.at(i), Q2.at(j) ) << "\t";
        }
        file << "\n";
    }
    file.close();
}

void outputUGDMassless()
{
    using namespace UGD::massless;

    ofstream file;

}
