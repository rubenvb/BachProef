/**
  * Plots.h
  * Function declaration(s) for generating plot(ting data).
  *
  * author: Ruben Van Boxem
  *
  **/

#ifndef STRUCTUREFUNCTIONPLOTS_H
#define STRUCTUREFUNCTIONPLOTS_H

#include <string>

void outputSFMassless();
void outputSFMassive();
void outputUGDMassless();
void outputET( const std::string &ETFile, const std::string &ETRunningAlphaFile );
void outputETAlternate( const std::string &ETFile, const std::string &ETRunningAlphaFile );
void outputETEvol( const std::string &ETEvolFile, const std::string &ETEvolRunningAlphaFile );

#endif // STRUCTUREFUNCTIONPLOTS_H
