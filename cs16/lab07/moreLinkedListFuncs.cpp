#include <cassert>
#include "linkedList.h"
#include "linkedListFuncs.h"
#include <iostream>

using namespace std;

void addIntToEndOfList(LinkedList *list, int value) {
  assert(list!=NULL); // if list is NULL, we can do nothing.

  Node *p; // temporary pointer

  // TODO:
  // (1) Allocate a new node.  p will point to it.

  p = new Node; // THIS IS PLACE-HOLDER LINE OF CODE.  DELETE IT AND REPLACE IT.

  // (2) Set p's data field to the value passed in
  p->data = value;
  // (3) Set p's next field to NULL
  p->next = NULL;

  // if the linkedlist is empty... the first and last values should be
  // the same value 'p'
  if (list->head == NULL) {
    // (4) Make both head and tail of this list point to p
    list->head = p;
    list->tail = p;

  // otherwise keep moving down the list until the 'next' value is NULL
  } else {

    // Add p at the end of the list.
    Node * tmp = list->head;
    while (tmp->next != NULL) {
      // cout << tmp->data << endl;
      tmp = tmp->next;
    }
    // cout << tmp->data << "    " << p->data << endl;
    //tmp = new Node;
    tmp->next = p;
    //delete tmp;
    //p->data = value;
    p->next = NULL;
    // (5) The current node at the tail? Make it point to p instead of NULL
    //list->tail = p;
    // (6) Make the tail of the list be p now.
    //
  }

}

void addIntToStartOfList(LinkedList *list, int value) {
  assert(list!=NULL); // if list is NULL, we can do nothing.

  // Add code for this.
  // HINTS:
  //  You will need to allocate a new Node.
  //  You will need two cases just as in addIntToEndOfList,
  //  one for when list->head is NULL and another for when it is not.
  // You need to consider how to make sure that list->head changes to point to the new node
  // that you allocated.  And you will need to make sure that when you are done, 
  // that if the new node is now the ONLY thing on the list, that tail points to it also,
  // and that the new node is pointing to NULL.
  // Otherwise, you'll need to be sure that
  //   if it is the only node on the list, or to the "old" head if there
  Node * p = new Node;
  p->data = value;
  if (list->head == NULL) {
    // (4) Make both head and tail of this list point to p
    list->head = p;
    list->tail = p;
    p->next = NULL;
  } else {
    // Add p at the head of the list and set every value later one node
    Node * tmp = list->head;
    list->head = p;
    p->next = tmp;
    //while (tmp->next != NULL) {
    //  // cout << tmp->data << endl;
    //  cout << tmp->next->next->data << endl;
    //  tmp->next = tmp->next->next;
    //  tmp = tmp->next;
    //}
    // cout << tmp->data << "    " << p->data << endl;
    //tmp = new Node;
    //tmp->next = NULL;
    //delete tmp;
    //p->data = value;
    // p->next = NULL;
    // (5) The current node at the tail? Make it point to p instead of NULL
    //list->tail = p;
    // (6) Make the tail of the list be p now.
    //
  }
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the largest value.
// You may assume list has at least one element  
// If more than one element has largest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node * pointerToMax(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.
  assert(list!=NULL);
  assert(list->head != NULL);

  Node * tmp = list->head;
  Node * max = tmp;
  while(tmp != NULL) {
    if(tmp->data > max->data) {
      max = tmp;
    }
    tmp = tmp->next;
  }

  // TODO: Insert code here to calculate and return
  //   value of pointer to max element (first one if ties.)

  return max; // STUB!  Replace this line with correct code
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the smallest value.  
// You may assume list has at least one element
// If more than one element has smallest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head


Node * pointerToMin(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);

  Node * tmp = list->head;
  Node * min = tmp;
  while(tmp != NULL) {
    if(tmp->data < min->data) {
      min = tmp;
    }
    tmp = tmp->next;
  }

  // TODO: Insert code here to calculate and return
  //   value of pointer to min element 
  //   (first one such value that occurs if there are ties.)

  return min; // STUB!  Replace this line with correct code

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the largest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int largestValue(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);

  // TODO: Insert code here to calculate and return
  //   largest value in list (which may not be unique).

  return pointerToMax(list)->data; // STUB!  Replace this line with correct code

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the smallest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int smallestValue(LinkedList *list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);

  // TODO: Insert code here to calculate and return
  //   smallest value in list (which may not be unique).

  return pointerToMin(list)->data; // STUB!  Replace this line with correct code

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the sum of all values in the list.
// You may assume that list is not NULL
// However, the list may be empty (i.e. list->head may be NULL)
//  in which case your code should return 0.

int sum(LinkedList * list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);

  // TODO: Insert code here to calculate and return
  //   sum of all values in list (0 if there are none).
  int sum = 0;
  Node * tmp = list->head;
  while(tmp != NULL) {
    sum += tmp->data;
    tmp = tmp->next;
  }

  return sum; // STUB!  Replace this line with correct code

}

