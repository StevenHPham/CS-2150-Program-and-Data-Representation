#include "stack.h"


stack::stack(){
  top = -1;
}



void stack::push(int e){
  if (top == SIZE - 1){
    cout << "stack is full" << endl;
  } else{
    top++;
    arr[top] = e;
  }
}

int stack::topNum(){
  if (empty() == true){
    cout << "stack is empty" << endl;
    return -1;
  } else{
    int x = arr[top];
    return x;
  }
}

void stack::pop(){
  if (empty() == true){
    cout << "stack is empty" << endl;
  }else{
    top--;
  }
}
bool stack::empty(){
  if (top == -1){
    return true;
  } else{
    return false;
  }
}


