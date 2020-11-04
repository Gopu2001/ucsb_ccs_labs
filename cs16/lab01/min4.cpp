/*
Code originally by P. Conrad, 2016
Code modified   by Z. Matni, Oct. 2016
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int smallest_of_four(int args[]); // returns smallest number 

int main(int argc, char *argv[])  {
  if (argc != 5) {
    cerr << "Usage: " << argv[0] << " num1 num2 num3 num4" << endl;
    cerr << " Prints smallest of the four numbers" << endl;
    exit(1);
  }
  int args [4];
  args[0] = atoi(argv[1]);
  args[1] = atoi(argv[2]);
  args[2] = atoi(argv[3]);
  args[3] = atoi(argv[4]);

  cout << smallest_of_four(args) << endl;
  
  return 0;
}

int smallest_of_four(int args[]) {
  int smallest = args[0];
  for(int i = 0; i < 3; i++) {
    if (args[i+1] < args[i]) {
      smallest = args[i+1];
    }
  }
  return smallest;
}
