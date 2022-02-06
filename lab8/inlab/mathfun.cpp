#include <iostream>

using namespace std;

extern "C" int product(int, int);
extern "C" int power(int, int);

int main(){

  int x , y , mult , exp;

  cout << "Enter interger 1: " << endl;
  cin >> x;
  cout << "Enter integer 2: " << endl;
  cin >> y;

  mult = product(x,y);
  exp = power(x,y);
  cout << "Product: " << mult << endl;
  cout << "Power: "  << exp << endl;

  return 0;
}
