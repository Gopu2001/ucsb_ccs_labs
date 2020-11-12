#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <deque>
#include <array>

using namespace std;

// template<typename T>
// T timesTen(T number) {
//   return number * 10;
// }
//
// template<typename NUM>
// NUM max(NUM * array, int size) {
//   NUM max = array[0];
//   for(int i = 0; i < size; i++) {
//     if(max < array[i]) {
//       max = array[i];
//     }
//   }
//   return max;
// }

// template<class T>
// class Person {
// public:
//   Person(string name, T id) {
//     this->name = name;
//     this->id = id;
//   }
//   T id;
//   string name;
// };
//
//
// class Fighter : Person<double> {
// public:
//   Fighter(string name, double id, int wins) : Person<double>(name, id) {
//     this->wins = wins;
//   }
//   int wins;
//   int getWins() {
//     return wins;
//   }
// }

template<template<class, class> class V = deque, typename T = float, typename A>
T getLastElement(V<T, A> &vect) {
  cout << typeid(vect).name() << endl;
  return vect.back();
}

int main() {
  const int r;
  cin >> r;
  array<int> x = new array<int, r>;
  // x.push_back(2);
  // x.push_back(5);
  // x.push_back(10);
  // cout << getLastElement(x) << endl;
  deque<float> y;
  y.push_back(3.5f);
  y.push_back(2.5f);
  y.push_back(2.9f);
  cout << getLastElement(y) << endl;
  // Person<string> Gerardo ("Gerardo", "5392AJ");
  // cout << Gerardo.id << endl;
  // Person Alfredo ("Alf", 3456765);
  // cout << Alfredo.id << endl;
  // cout << timesTen(5) << endl;
  // cout << timesTen(5.2f) << endl;
  // cout << timesTen(5.5) << endl;
  // int foo[] = {1, 2, 3, 4, 5};
  // double foo2[] = {1.4, 2.7, 3.5};
  // cout << "Max of Foo: " << max(foo, 5) << endl;
  // cout << "Max of Foo2: " << max(foo2, 3) << endl;
  return 0;
}
