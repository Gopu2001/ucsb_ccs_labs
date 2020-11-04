#include "linkedList.h"
#include "linkedListFuncs.h"
#include <iostream>

using namespace std;

//head: ptr to a Node * which is the head of a linked list
//return sum of all values in linked list using a recursive approach
//if head is null return 0
int recursiveSum(Node* head) {
  if(head == NULL) // this is specifically for the first element only
    return 0;
  int sum = head->data; // store the current data
  if(head->next != NULL) // basically a while "there is next element" loop
    sum += recursiveSum(head->next);
  return sum; // final sum is returned
}

//head: ptr to a Node* which is the head of a linked list
//return the largest value in the linked list using a recursive approach
//you may assume the list has at least one element
int recursiveLargestValue(Node* head) {
  int current = head->data;
  int next;
  if(head->next == NULL) {
    return current;
  }
  next = recursiveLargestValue(head->next);
  if(current > next) {
    return current;
  }
  return next;
}

//int main() {
//  int x[10] = {1, 2, 3, 4, 5, 6, -1000, 23, 235, 64};
//  LinkedList *y = arrayToLinkedList(x, 10);
//  cout << "6 == " << recursiveLargestValue(y->head) << endl;
//  return 0;
//}
