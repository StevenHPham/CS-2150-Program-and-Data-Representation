#include <iostream>

using namespace std;

void swap(int*& x , int*& y ){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void main() {
  int* a = new int(34);
  int* b = new int(81);
  swap(a,b);
  cout << a << endl;
  return 0;
}
