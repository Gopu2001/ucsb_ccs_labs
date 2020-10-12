#include "arrayFuncs.h"
#include "tddFuncs.h"

int main() {
  int empty[] = {};
  // expect this function to result in message to cerr and exit(1);
  assertEquals(0,
               maxOfArray(empty,0),
               "maxOfArray(empty,0)" );
  // Fill this in with code that calls maxOfArray with a size of zero.
  // so that you can see if the error message prints correctly.
  return 0;

}
