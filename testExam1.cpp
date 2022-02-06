#include <iostream>
using namespace std;

int main(){
  int *s;
  *s = 7;
  delete s;
  cout << s << endl;
  return 0;
  


}
