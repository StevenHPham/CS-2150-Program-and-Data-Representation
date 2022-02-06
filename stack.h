#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#define SIZE 10

class stack{
  
  int arr[SIZE];
  int top;
  
 public:
  stack();


  void push(int e);
  int  topNum();
  void pop();
  bool empty();
  
};

#endif
