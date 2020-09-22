#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ProcessDNA{

private:
  string dnaLines;
  int numLines;
  double bigramCount;
  double nucleoCount;
  double sum;
  double mean;
  double variance;
  double stdDev;
  double nucleoTotal;
  double probA;
  double probC;
  double probG;
  double probT;

public:
  ProcessDNA(); //constructor
  ~ProcessDNA(); //destructor

  void setDNAstring(ifstream& inStream); //taking input from the file
  void computeFile(ofstream& outStream); //comuting data from the file
  void nucleoProb(ofstream& outStream); //calculating nucleotide probability
  void gausDist(ofstream& outStream); //generating string based on Gaussian distrobution


};
