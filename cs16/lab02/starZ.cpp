// Anmol Kapoor
// starZ.cpp   A demonstration of ASCII Art printing C characters

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starZ(int width);
void runTests(void);

// Write starZ per specifictions at
// https://foo.cs.ucsb.edu/16wiki/index.php/F14:Labs:lab04
// and so that internal tests pass, and submit.cs system tests pass


string starZ(int width)
{
  string result="";
  if (width < 3) { return result; }
  for(int i = 0; i < width; i++)
  {
    for(int j = 0; j < width; j++)
    {
      //if (i != 0 && i != width - 1) { cout << width - 1 - j << endl; }
      if (i == 0 || i == width - 1) { result += '*'; }
      else if (j == width - 1 - i) { result += '*'; }
      else if (j != width - 1 - i) { result += ' '; }
    }
    result += '\n';
  }
  return result;
}

// Test-Driven Development; check expected results against actual

void runTests(void) {

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they 
  // automatically get concatenated into a single string literal

  string starZ3Expected = 
    "***\n"
    " * \n"
    "***\n";
  
  assertEquals(starZ3Expected,starZ(3),"starZ(3)");

  string starZ4Expected = 
    "****\n"
    "  * \n"
    " *  \n"
    "****\n";
  
  assertEquals(starZ4Expected,starZ(4),"starZ(4)");

  assertEquals("",starZ(0),"starZ(0)");
  assertEquals("",starZ(2),"starZ(2)");
}

// Test harness

void assertEquals(string expected, string actual, string message="") {
  if (expected==actual) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl << "   Expected:[\n" << expected << "] actual = [\n" << actual << "]\n" << endl;
  }
}


// Main function

int main(int argc, char *argv[])
{
  if (argc!=2) {
    cerr << "Usage: " << argv[0] << " width" << endl;
    exit(1);
  }

  int width = stoi(argv[1]);
  // If the program is executed with parameters -1 -1 unit test
  // the starL() function using our automated test framework
  if (width==-1) {
    runTests();
    exit(0);
  }

  cout << starZ(width);
  return 0;
}
