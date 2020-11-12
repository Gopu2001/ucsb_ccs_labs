// intbst.cpp
// Implements class IntBST
// Anmol Kapoor

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() : root(0) { }

// destructor deletes all nodes
IntBST::~IntBST() {
  clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
  if (n) {
    clear(n->left);
    clear(n->right);
    delete n;
  }
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
  // handle special case of empty tree first
  if (!root) {
    root = new Node(value);
    return true;
  }
  // otherwise use recursive helper
  return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
  if (value == n->info)
    return false;
  if (value < n->info) {
	   if (n->left) {
       return insert(value, n->left);
     } else {
       n->left = new Node(value);
       n->left->parent = n;
       return true;
     }
  } else {
    if (n->right) {
	    return insert(value, n->right);
    } else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	  }
  }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
  printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
  if (n) {
    cout << n->info << " ";
    printPreOrder(n->left);
    printPreOrder(n->right);
  }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
  printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
  if(n) {
    if(!n->left) {
      cout << n->info << " ";
    }
    if(n->left) {
      printInOrder(n->left);
      cout << n->info << " ";
    }
    if(n->right) {
      printInOrder(n->right);
    }
  }
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
  printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
  if(n) {
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << " ";
  }
}

// return sum of values in tree
int IntBST::sum() const {
  return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
  if(!n) {
    return 0;
  }
  return n->info + sum(n->right) + sum(n->left); // REPLACE THIS NON-SOLUTION
}

// return count of values
int IntBST::count() const {
  return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
  if(!n) {
    return 0;
  }
  return 1+count(n->right)+count(n->left); // REPLACE THIS NON-SOLUTION
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const {
  // cout << "Get Node for " << value << endl;
  if(n) {
    if(n->info == value) {
      // cout << ".......91" << endl;
      // cout << "..." << n->info << endl;
      return n;
    }
    Node * tmp = NULL;
    if(n->left) {
      tmp = getNodeFor(value, n->left);
    }
    if(!tmp && n->right) {
      tmp = getNodeFor(value, n->right);
    }
    // cout << ".......92" << endl;
    if(tmp)
      // cout << "..." << tmp->info << endl;
    return tmp;
  }
  // cout << ".......93" << endl;
  return NULL;
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
  // cout << "contains: " << value << endl;
  return contains(value, root); // REPLACE THIS NON-SOLUTION
}

bool IntBST::contains(int value, Node * n) const {
  if(!n) {
    return false;
  }
  if(n->info == value) {
    return true;
  }
  return contains(value, n->right) || contains(value, n->left); // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
  Node * tmp = getNodeFor(value, root);
  Node * focus = NULL;
  if(tmp) {
    if(tmp->left) {
      focus = tmp->left;
      if(focus->right) {
        focus = focus->right;
      }
    } else if(tmp->parent && tmp->parent->info < value) {
      focus = tmp->parent;
    }
  }
  return focus; // REPLACE THIS NON-SOLUTION
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
  Node * tmp = getPredecessorNode(value);
  if(tmp) {
    return tmp->info;
  }
  return 0; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
  // cout << "Get Successor" << endl;
  Node * tmp = getNodeFor(value, root);
  Node * focus = NULL;
  if(tmp) {
    if(tmp->right) {
      focus = tmp->right;
      if(focus->left) {
        focus = focus->left;
      }
    } else if(tmp->parent && tmp->parent->info > value) {
      focus = tmp->parent;
    } else if(tmp->parent && tmp->parent->parent && tmp->parent->parent->info > value) {
      focus = tmp->parent->parent;
    }
  }
  return focus; // REPLACE THIS NON-SOLUTION
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
  Node * tmp = getSuccessorNode(value);
  if(tmp) {
    return tmp->info;
  }
  return 0; // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value) {
  // cout << endl << "Attempting to remove: " << value << " from " << endl;
  // printPreOrder();
  // cout << endl;
  Node * tmp = getNodeFor(value, root);
  // if tmp exists then do everything, otherwise return false
  if(tmp) {
    // if not left nor right, but still has a parent
    if(!tmp->left && !tmp->right && tmp->parent) {
      // cout << "p" << endl;
      if(tmp->parent->info > value) {
        tmp->parent->left = NULL;
      } else {
        tmp->parent->right = NULL;
      }
    // if not right, but has a left and a parent
    } else if(tmp->left && !tmp->right && tmp->parent) {
      // cout << "l" << endl;
      if(tmp->parent->info > value) {
        tmp->parent->left = tmp->left;
        tmp->left->parent = tmp->parent;
      } else {
        tmp->parent->right = tmp->left;
        tmp->left->parent = tmp->parent;
      }
    // if not left, but has a right and a parent
    } else if(!tmp->left && tmp->right && tmp->parent) {
      // cout << "r" << endl;
      if(tmp->parent->info > value) {
        tmp->parent->left = tmp->right;
        tmp->right->parent = tmp->parent;
      } else {
        tmp->parent->right = tmp->right;
        tmp->right->parent = tmp->parent;
      }
    // has left and right and (parent or no parent)
    } else if(!tmp->left && !tmp->right && !tmp->parent) {
      root = NULL;
    } else {
      // cout << "l&r" << endl;
      if(tmp->parent) {
        // cout << "&p" << endl;
      }
      Node * focus = getSuccessorNode(value);
      // focus->left = tmp->left;
      // if(focus->info != tmp->right->info) {
        // if(focus->parent->info > focus->info) {
        //   // focus->parent->left = NULL;
        //   // remove(focus->info);
        // }
      int focus_info = focus->info;
      remove(focus->info);
      tmp->info = focus_info;
        // focus->right = tmp->right;
      // }

      // if(tmp->parent) {
      //   focus->parent = tmp->parent;
      //   if(focus->parent->info > focus->info) {
      //     focus->parent->left = focus;
      //   } else {
      //     focus->parent->right = focus;
      //   }
      //   tmp->parent = NULL;
      // }
      // focus->left->parent = focus;
      // if(focus->right) {
      //   focus->right->parent = focus;
      // }
      // if(root->info == tmp->info) {
      //   focus->parent = NULL;
      //   root = focus;
      // }
      // tmp->left = NULL;
      // tmp->right = NULL;
      // tmp = NULL;
    }
    // cout << "The is the resulting list: " << endl;
    // printPreOrder();
    return true;
  }
  return false; // REPLACE THIS NON-SOLUTION
}
