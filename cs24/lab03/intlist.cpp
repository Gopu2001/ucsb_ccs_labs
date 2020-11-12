// intlist.cpp
// Implements class IntList
// Anmol Kapoor

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
  Node *tmp = source.first;
  while(tmp != NULL) {
    this->append(tmp->info);
    tmp = tmp->next;
  }
  //IMPLEMENT THIS
}

// destructor deletes all nodes
IntList::~IntList() {
  if(first != NULL) {
    emptyNodes(first);
  }
  first = NULL;
  free(first);
  // cout << first->info << std::endl;
  //IMPLEMENT THIS
}

// helper method for intlist destructor
void IntList::emptyNodes(Node* fpos_t) {
  if(fpos_t != NULL) {
    emptyNodes(fpos_t->next);
    // free(fpos_t->next);
    // delete fpos_t->next;
    // free((void*)fpos_t->next);
    // cout << fpos_t->info << std::endl;
  }
  // if (fpos_t->next)
  //   fpos_t->next = NULL;
  // fpos_t = NULL; // This gives memory leaks
  delete fpos_t;
  // cout << fpos_t->info << std::endl;
  // delete first;


  // Node* next;
  // while(fpos_t != NULL) {
  //   next = fpos_t->next;
  //   // free(fpos_t);
  //   // fpos_t->next = NULL;
  //   // fpos_t->next = NULL;
  //   // free(fpos_t->next);
  //   delete fpos_t;
  //   // delete fpos_t;
  //   delete fpos_t->next;
  //   fpos_t = next;
  //   cout << "-";
  // }
  // fpos_t->next = NULL;
  // fpos_t = NULL;
  // free(fpos_t);
  // free(fpos_t);
  // delete fpos_t;
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
      //cout << "contains cleared early" << std::endl;
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
    //cout << "max() entered" << std::endl;
    Node *tmp = first;
    if(tmp == NULL) {
      //cout << "max cleared early" << std::endl;
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
  int count = this->count();
  int sum = this->sum();
  if(count > 0)
    return 1.0 * this->sum() / this->count(); // REPLACE THIS NON-SOLUTION
  else
    return 0;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
  Node *befFirst = (Node*) new Node;
  befFirst->info = value;
  //befFirst->head = NULL;
  befFirst->next = first;
  first = befFirst;
  //delete before;
  // IMPLEMENT
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    Node *tmp = source.first;
    emptyNodes(this->first);
    first = NULL;
    while(tmp != NULL) {
      append(tmp->info);
      tmp = tmp->next;
    }
    delete tmp;
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
