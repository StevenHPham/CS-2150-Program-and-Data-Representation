#include <iostream>
#include "timer.h"

using namespace std;

extern "C" int threexplusone(int n);

int main(){
  int n;
  cout << "Enter a number: ";
  cin >> n;

  int iter;
  cout << "Enter iterations of subroutine: ";
  cin >> iter;

  

  timer time;
  time.start();
  
  for(int i = 0 ; i < iter ; i++){
    threexplusone(n);
  }
  
  time.stop();


  
  double sec = time.getTime();
  // cout << "Average ms per function: " << ((sec*1000)/iter) << endl;

  int result = threexplusone(n);
  cout << "Steps: " << result << endl;

  return 0;
}

