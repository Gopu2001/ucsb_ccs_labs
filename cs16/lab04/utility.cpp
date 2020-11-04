// Anmol Kapoor
// utility.cpp

// IN THIS FILE, define any of your OWN functions you may need to
// solve the problems.

// For example, if you need an isPrime function, you can put the function
// definition in this file.  Similarly, isOdd or isEven might be useful.

// You will need to include the function prototype in "utility.h" and
// then be sure to  #include "utility.h" in the file where you use
// these functions

#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int x);

bool isOdd(int x) {
  if (x % 2 == 1 || x % 2 == -1) { return true; }
  return false;  // REPLACE THIS STUB WITH REAL CODE
}
bool isEven(int x) {
  if (x % 2 == 0) { return true; }
  return false;  // REPLACE THIS STUB WITH REAL CODE
}
bool isPrime(int x) {
  //cout << sqrt(x) << endl << roundf(sqrt(x)) << endl << endl;
  if (x <= 1) { return false; }
  for(int i = 2; i <= roundf(sqrt(x)); i++)
  {
    //cout << i << "\t" << x * 1.0 / i << endl;
    if(x * 1.0 / i == roundf(x / i)) { return false; }
  }
  return true;  // REPLACE THIS STUB WITH REAL CODE
}
