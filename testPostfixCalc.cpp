#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include  "postfixCalculator.h"
#include  "stack.h"

int main(){
  stack rpnStack;
  string token;

  while (cin >> token){
    int number;
    if(istringstream(token) >> number){
      rpnStack.push(number);
    } else if (isOperator(token) == true){
      rpn(token, rpnStack);
    }
    
  }
  cout << rpnStack.topNum() << endl;
  return 0;
}
