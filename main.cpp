#include <iostream>

#include "item.h"

using namespace std;

int main() {
  cout << "Hello world" << endl;
  Item i;
  i.setID(1234);
  cout << "ID: " << i.getID() << endl;
  return 0;
}
