// Anmol Kapoor
// countDucks.cpp 
// P. Conrad for CS16, Winter 2015
// Example program to read from file and count occurences

#include <iostream> // for printf()
#include <cstdlib> // for exit(), perror()
#include <fstream> // for ifstream
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc!=2) {
    // if argc is not 2, print an error message and exit
    cerr << "Usage: "<< argv[0] << " inputFile" << endl;
    exit(1); // defined in cstdlib
  }
  int duckCount = 0;
  int totalCount = -1;
  string output;
  ifstream animals;
  animals.open(argv[1]);
  if(animals.is_open())
  {
    while (!animals.eof())
    {
      animals >> output;
      if(output == "duck") { duckCount += 1; }
      totalCount += 1;
    }
  }
  cout << "Report for " << argv[1] << ":\n";
  cout << "\tAnimal count:    " << totalCount << endl;
  cout << "\tDuck count:      " << duckCount << endl;
  cout << "\tNon duck count:  " << (totalCount - duckCount) << endl;
  animals.close();
  return 0;
}
