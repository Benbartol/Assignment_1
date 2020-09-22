#include "Assignment1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

ProcessDNA::ProcessDNA(){ //constructpr
  string dnaLines;
  int numLines;
  double nucleoCount = 0.0;
  double sum = 0.0;
  double mean = 0.0;
  double variance = 0.0;
  double stdDev = 0.0;
  double nucleoTotal = 0.0;
  double probA = 0.0;
  double probC = 0.0;
  double probG = 0.0;
  double probT = 0.0;

}

ProcessDNA::~ProcessDNA(){ //destructor
}


//reading in from the file
void ProcessDNA::setDNAstring(ifstream& inStream){
  numLines = 0;
  char c;
  while(!inStream.eof()){
    if(c == '\n'){
      numLines++;
    }
    inStream.get(c);
    dnaLines += c;
  }
}

void ProcessDNA::computeFile(ofstream& outStream){
  int count = 0;
  double nucleoCount = 0.0;

  for(int i = 0; i < dnaLines.size(); ++i){
    if(dnaLines[i] != '\n'){
      nucleoTotal += 1;
    }else{
      variance += pow((nucleoCount - mean), 2);
      nucleoCount = 0;
      count += 1;
      if(count == numLines){
        variance = variance/nucleoTotal;
        stdDev = sqrt(variance);
        break;
      }
     }
    }
  outStream << "\nVariance: " << variance;
  outStream << "\nStandard Deviation: " << stdDev;

}


void ProcessDNA::nucleoProb(ofstream& outStream){
  double probAA = 0;
  double probAC = 0;
  double probAG = 0;
  double probAT = 0;
  double probCA = 0;
  double probCC = 0;
  double probCG = 0;
  double probCT = 0;
  double probGA = 0;
  double probGC = 0;
  double probGG = 0;
  double probGT = 0;
  double probTA = 0;
  double probTC = 0;
  double probTG = 0;
  double probTT = 0;

  //Calculates probabilityof each nucleo type
  for(int i = 0; i < dnaLines.size(); ++i){

    if((dnaLines[i] == 'a')||(dnaLines[i] == 'A')){
      probA++;

      if(dnaLines[i+1] != '\n'){
        nucleoCount++;
        if((dnaLines[i+1] == 'a')||(dnaLines[i+1] == 'A')){
          probAA++;
        }else if((dnaLines[i+1] == 'c')||(dnaLines[i+1] == 'C')){
          probAC++;
        }else if((dnaLines[i+1] == 'g')||(dnaLines[i+1] == 'G')){
          probAG++;
        }else if((dnaLines[i+1] == 't')||(dnaLines[i+1] == 'T')){
          probAT++;
        }
      }
    }

    else if((dnaLines[i] == 'c')||(dnaLines[i] == 'C')){
      probC++;
      if(dnaLines[i+1] != '\n'){
        nucleoCount++;
      if((dnaLines[i+1] == 'a')||(dnaLines[i+1] == 'A')){
        probCA++;
      }else if((dnaLines[i+1] == 'c')||(dnaLines[i+1] == 'C')){
        probCC++;
      }else if((dnaLines[i+1] == 'g')||(dnaLines[i+1] == 'G')){
        probCG++;
      }else if((dnaLines[i+1] == 't')||(dnaLines[i+1] == 'T')){
        probCT++;
      }
    }
  }

   else if((dnaLines[i] == 'g')||(dnaLines[i] == 'G')){
     probG++;
     if(dnaLines[i+1] != '\n'){
       nucleoCount++;
       if((dnaLines[i+1] == 'a')||(dnaLines[i+1] == 'A')){
         probGA++;
       }else if((dnaLines[i+1] == 'c')||(dnaLines[i+1] == 'C')){
         probGC++;
       }else if((dnaLines[i+1] == 'g')||(dnaLines[i+1] == 'G')){
         probGG++;
       }else if((dnaLines[i+1] == 't')||(dnaLines[i+1] == 'T')){
         probGT++;
       }
     }
   }
     else if((dnaLines[i] == 't')||(dnaLines[i] == 'T')){
       probT++;
     if(dnaLines[i+1] != '\n'){
       nucleoCount++;
       if((dnaLines[i+1] == 'a')||(dnaLines[i+1] == 'A')){
         probTA++;
       }else if((dnaLines[i+1] == 'c')||(dnaLines[i+1] == 'C')){
        probTC++;
       }else if((dnaLines[i+1] == 'g')||(dnaLines[i+1] == 'G')){
         probTG++;
       }else if((dnaLines[i+1] == 't')||(dnaLines[i+1] == 'T')){
         probTT++;
       }
     }
   }
 }

  probA = (probA/nucleoCount)*100;
  probC = (probC/nucleoCount)*100;
  probG = (probG/nucleoCount)*100;
  probT = (probT/nucleoCount)*100;

  probAA = (probAA/nucleoCount)*100;
  probAC = (probAC/nucleoCount)*100;
  probAG = (probAG/nucleoCount)*100;
  probAT = (probAT/nucleoCount)*100;

  probCA = (probCA/nucleoCount)*100;
  probCC = (probCC/nucleoCount)*100;
  probCG = (probCG/nucleoCount)*100;
  probCT = (probCT/nucleoCount)*100;

  probGA = (probGA/nucleoCount)*100;
  probGC = (probGC/nucleoCount)*100;
  probGG = (probGG/nucleoCount)*100;
  probGT = (probGT/nucleoCount)*100;

  probTA = (probTA/nucleoCount)*100;
  probTC = (probTC/nucleoCount)*100;
  probTG = (probTG/nucleoCount)*100;
  probTT = (probTT/nucleoCount)*100;

  outStream << "\nSingular Nucleotides\n" << "\nA: " << probA << "%\nC: " << probC << "%\nG: " << probG << "%\nT: " << probT << "%\n";
  outStream << "\nNucleotidePairs\n" << "\nAA: " << probAA << "%\nAC: " << probAC << "%\nAG: " << probAG << "%\nAT: " << probAT;
  outStream << "\nCA: " << probCA << "%\nCC: " << probCC << "%\nCG: " << probCG << "%\nCT: " << probCT;
  outStream << "\nGA: " << probGA << "%\nGC: " << probGC << "%\nGG: " << probGG << "%\nGT: " << probGT;
  outStream << "\nGA: " << probTA << "%\nTC: " << probTC << "%\nTG: " << probTG << "%\nTT: " << probTT;

}



void ProcessDNA::gausDist(ofstream& outStream){
  double randA = ((double)rand() / (RAND_MAX));
  double randB = ((double)rand() / (RAND_MAX));
  double C = (sqrt(-2*log(randA)))*(cos(2*(M_PI)*randB));
  double D = (stdDev * C) + mean;

  for(int i = 0; i < 1000; ++i){
    for(int j = 0; j < D; ++j){
      double range = rand() % 100;
      if(range <= probA){
        outStream << "A";
      }else if(range <= (probA + probC)){
        outStream << "C";
      }else if(range <= (probA + probC + probG)){
        outStream << "G";
      }else if(range <= 100){
        outStream << "T";
      }
    }
    outStream << "\n";
  }
  //resetting probabilities in case the user decides to process another file
  probA = 0;
  probC = 0;
  probG = 0;
  probT = 0;
  stdDev = 0;


}
