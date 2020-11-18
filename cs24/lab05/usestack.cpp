// usestack.cpp - for CS 24 lab practice using stacks
// Anmol Kapoor

#include "intstack.h"
#include <cstdlib>   // for atof function
#include <cstdio>    // for sscanf
#include <cstring>   // for strcmp and strtok
#include <iostream>
#include <stack>     // STL stack class
#include <string>    // for throwing string exceptions
using namespace std;

#define MAXLEN 100

// constants used to identify a token - DO NOT CHANGE
enum TokenType {LEFT, RIGHT, ADD, SUBTRACT, MULTIPLY,
                DIVIDE, NUMBER, OTHER};

TokenType identify(char *t) {
  if (strcmp(t, "+") == 0)
    return ADD;
  if (strcmp(t, "-") == 0)
    return SUBTRACT;
  if (strcmp(t, "*") == 0)
    return MULTIPLY;
  if (strcmp(t, "/") == 0)
    return DIVIDE;
  float value;
  if (sscanf(t, "%g", &value) == 1)
    return NUMBER;
  return OTHER;
}

double postFix(char *expression[], int numTokens) {
  stack<double> numbers;
  double rightValue, leftValue;
  TokenType type;

  for (int i=0; i<numTokens; i++) {
    type = identify(expression[i]);
    switch(type) {
      case NUMBER:
        numbers.push( atof(expression[i]) );
        break;
      case ADD:
        rightValue = numbers.top();
        numbers.pop();
        leftValue = numbers.top();
        numbers.pop();
        // result = rightValue + leftValue;
        numbers.push(leftValue + rightValue);
        break;
      case SUBTRACT:
        rightValue = numbers.top();
        numbers.pop();
        leftValue = numbers.top();
        numbers.pop();
        // result = numbers.pop() - numbers.pop();
        numbers.push(leftValue - rightValue);
        break;
      case MULTIPLY:
        rightValue = numbers.top();
        numbers.pop();
        leftValue = numbers.top();
        numbers.pop();
        // result = numbers.pop() * numbers.pop();
        numbers.push(leftValue * rightValue);
        break;
      case DIVIDE:
        rightValue = numbers.top();
        numbers.pop();
        leftValue = numbers.top();
        numbers.pop();
        // result = numbers.pop() / numbers.pop();
        numbers.push(leftValue / rightValue);
        break;
      default:
        throw string("unknown token: ")
                      + string(expression[i]);
    }
  }
  return numbers.top();
}

int main() {
  // Stack s;
  //
  // s.push(10);
  // s.push(20);
  //
  // while (!s.empty()) {
  //   cout << s.top() << endl;
  //   s.pop();
  // }
  // input = "1 2 +";

  char input[MAXLEN], *tokens[MAXLEN/2];

  cout << "enter expression: ";
  cin.getline(input, MAXLEN);

  char *ptr = strtok(input, " ");
  int count = 0;
  while (ptr != 0) {
    tokens[count] = ptr;
    ++count;
    ptr = strtok(0, " ");
  }

  try {
    double result = postFix(tokens, count);
    cout << "result: " << result << endl;
  }
  catch(string error) {
    cerr << "bad expression: " << error << endl;
    return 1;
  }
  return 0;
}
