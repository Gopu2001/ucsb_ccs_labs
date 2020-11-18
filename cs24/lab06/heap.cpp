// heap.cpp
// Anmol Kapoor

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  const int val = value;
  vdata.insert(vdata.begin(), val);
  // cout << "Added: " << value << std::endl;
  // cout << "Now h = [ ";
  // for(unsigned int i = 0; i < vdata.size(); i++) {
  //   cout << vdata[i] << " ";
  // }
  // cout << "]" << std::endl;
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  int min = top();
  for(unsigned int i = 0; i < vdata.size(); i++) {
    if(vdata[i] == min) {
      vdata.erase(vdata.begin()+i);
      break;
    }
  }
  // cout << "Removed min. Now h = [ ";
  // for(unsigned int i = 0; i < vdata.size(); i++) {
  //   cout << vdata[i] << " ";
  // }
  // cout << "]" << std::endl;
}

// Returns the minimum element in the heap
int Heap::top(){
  // cout << "---" << std::endl;
  int min = vdata[0];
  for(unsigned int i = 0; i < vdata.size(); i++) {
    if(vdata[i] < min) {
      // cout << "MIN Now = " << vdata[i] << std::endl;
      min = vdata[i];
    }
  }
  // cout << "---" << std::endl;
  return min;
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if(vdata.size() == 0) {
    return true;
  }
  return false;
}
