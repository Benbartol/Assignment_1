#include "Assignment1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv){

  ifstream inFS;
  ofstream outFS;

  outFS.open("BenBartol.out");
  if(outFS.is_open()){
    outFS << "Ben Bartol\n";
    outFS << "Student ID: 2315721\n";
    outFS << "Student Email: bartol@chapman.edu\n";
    outFS << "CPSC 350\n";
    outFS << "Assignment 1\n";
  }
  else{
    cout << "Unable to open file" << endl;
  }

  while(true){
    string filename;
    cout << "What is the name of the file you'd like to use?\n";
    cin >> filename;

    inFS.open(filename);

    ProcessDNA a;
    a.setDNAstring(inFS);
    a.computeFile(outFS);
    a.nucleoProb(outFS);
    a.gausDist(outFS);
    inFS.close();

    bool another = true;
    while(another){
      cout << "Would you like to process another file? (y/n)" << endl;
      string input;
      cin >> input;
      if((input == "n")||(input == "N")){
        outFS.close();
        return 0;
      }
      else if((input == "y")||(input == "Y")){
        break;
      }else{
        cout << "Please respond with a 'y' or an 'n'\n";
        continue;
      }
    }
  }
  return 0;
}
