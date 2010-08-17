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
#include "TransverseEnergyFlow.h"
#include "StructureFunction.h"
#include "UnintegratedGluonDensity.h"

// C++ includes
#include <algorithm>
#include <iostream>
    using std::cout;
    using std::endl;
#include <fstream>
    using std::ofstream;
#include <numeric>
    using std::accumulate;
#include <stdexcept>
    using std::runtime_error;
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
 * FL(x) for different values of Q�
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
 * F2(x) for same values Q�
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
 * FL(x) for different values of Q�
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
 * F2(x) for same values Q�
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
    using UGD::massless::F0Evol;

    ofstream file( "UGDMassless.txt" );

    const size_t nPoints = 20;
    vector<double> x(nPoints);
    const double Q2 = 10;
    vector<double> k2( { 1., 10. ,50. } );
    // x
    double current = 1e-5 / 1.6;
    for( size_t i=0; i<nPoints ; ++i )
    {
        current *= 1.6;
        x.at(i) = current;
    }

    double xi;
    for( size_t i = 0; i<nPoints; ++i )
    {
        xi = x.at(i);
        file << xi;
        for( size_t j = 0; j<k2.size(); ++j)
        {
             file << "\t" << F0Evol(xi, k2.at(j), Q2);
        }
        file << "\n";
    }
    file.close();
}

void outputET()
{
    using namespace ET::MonteCarlo;

    ofstream file( "ET.txt" );
    if( !file )
        throw runtime_error( "Unable to open file: ET.txt" );

    const int nPoints = 30;
    vector<double> x = {1e-8, 1e-7, 1e-6, 1e-5, 1e-4};
    vector<double> xj(nPoints);
    double current = 1e-10 / 1.833;
    for( size_t i=0; i<nPoints ; ++i )
    {
        current *= 1.833;
        xj.at(i) = current;
    }
    init();
    for( size_t i=0; i<xj.size(); ++i )
    {
        file << xj.at(i);
        for( size_t j=0; j<x.size(); ++j )
        {
            cout << "x = " << x.at(j) << "\t" << "xj = " << xj.at(i) << endl;
            double val = ETFlow( x.at(j), 10., xj.at(i) );
            cout << "\t" << val << endl;
            file << "\t" << val;
        }
        file << endl;
    }
    deinit();
    file.close();
    file.open( "ETRunningAlpha.txt" );
    if( !file )
        throw runtime_error( "unable to open file: ETRunningAlpha.txt" );
    init();
    for( size_t i=0; i<xj.size(); ++i )
    {
        file << xj.at(i);
        for( size_t j=0; j<x.size(); ++j )
        {
            cout << "x = " << x.at(j) << "\t" << "xj = " << xj.at(i) << endl;
            double val = ETFlowRunningAlpha( x.at(j), 10., xj.at(i) );
            cout << "\t" << val << endl;
            file << "\t" << val;
        }
        file << endl;
    }
    deinit();
    file.close();

}
void outputETEvol()
{   }

