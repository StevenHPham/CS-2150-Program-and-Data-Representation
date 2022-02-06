// Steven Pham
// shp4df
// 8/28
// Prelab 1: Recursive function

#include <iostream>
using namespace std;

int xToN(int x, int n){
  if (n != 0)
    return x * xToN(x,n-1);
  else
    return 1;
}

int main() {
  int x , n, ans;
  cin >> x;
  cin >> n;
  ans = xToN(x,n);
  cout << ans << endl;
  return 0;
}
