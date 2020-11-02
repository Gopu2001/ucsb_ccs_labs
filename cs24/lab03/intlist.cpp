// intlist.cpp
// Implements class IntList
// Anmol Kapoor

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    Node *tmp = first;
    int sum = 0;
    while(tmp != NULL) {
      sum += tmp->info;
      tmp = tmp->next;
    }
    //cout << "sum\n";
    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    //cout << "beg of contains\n";
    Node *tmp = first;
    if(tmp == NULL) {
      cout << "contains cleared early" << std::endl;
      return false;
    }
    while(tmp != NULL) {
      if(tmp->info == value) {
        return true;
      }
      tmp = tmp->next;
    }
    //cout << "contains\n";
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    cout << "max() entered" << std::endl;
    Node *tmp = first;
    if(tmp == NULL) {
      cout << "max cleared early" << std::endl;
      return 0;
    }
    int value = first->info;
    while(tmp != NULL) {
      if(tmp->info > value) {
        value = tmp->info;
      }
      tmp = tmp->next;
    }
    //cout << "max\n";
    return value; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    return 1.0 * this->sum() / this->count(); // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node *befFirst;
    befFirst->info = value;
    //befFirst->head = NULL;
    befFirst->next = first;
    first = befFirst;
    // IMPLEMENT
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n != NULL) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n != NULL) {
        ++result;
        n = n->next;
    }
    return result;
}
