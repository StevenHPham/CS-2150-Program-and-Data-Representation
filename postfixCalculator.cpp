#include "postfixCalculator.h"
#include "stack.h"


bool isOperator(const string&  signage){
  string sign[] = {"+" , "-" , "*" , "/" , "~"};
  for (int i = 0; i < 5; i++){
    if (signage == sign[i]){
      return true;
    }
  }
  return false;
}

void rpn(const string& signage, stack& rpnStack){
  int rightVal;
  int leftVal;
  int result;

  if (signage == "~"){
    rightVal = rpnStack.topNum();
    rpnStack.pop();
    result  = rightVal *  -1  ;
  } else{
    
  rightVal = rpnStack.topNum();
  rpnStack.pop();
  leftVal  = rpnStack.topNum();
  rpnStack.pop();
  } 

  
  if (signage == "+"){
    result = rightVal + leftVal;
  } else if (signage == "-"){
    result = leftVal - rightVal;
  } else if (signage == "*"){
    result = leftVal * rightVal;
  } else if  (signage == "/") {
    result = leftVal / rightVal;
  } 
  rpnStack.push(result);
  
}
