#include "arrayFuncs.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int maxOfArray(int a[], int size) {
  if (size < 1) {
    cerr << "ERROR: maxOfArray called with size < 1" << endl;
    exit(1);
  }
  int result=a[0];
  for (int i=1; i<size; i++) {
    if (a[i] > result)
      result = a[i];
  }
  return result;
}
