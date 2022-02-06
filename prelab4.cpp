#include <iostream>

using namespace std;

void sizeOfTest(){
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow(){
  unsigned int x = 4294967295;
  unsigned int result = x + 1;
  cout << x <<  " + 1 = " << result << endl;
}


void outputBinary(unsigned int x){
  
  unsigned int index = 0;

  for (int l = 31; l >= 0; l--){
    bool bina = (x & (1 << l));
    if (bina){
      index++;
      cout << "1";
      if (index == 4){
	cout << " ";
        index = 0;
      }
    }else{
      index++;
      cout << "0";
      if (index == 4){
	cout << " ";
        index = 0;
      }
    }
  }
}

   

int main(){
  unsigned int x;
  cin >> x;
  sizeOfTest();
  overflow();
  outputBinary(x);
  cout << endl;
  
  return 0;
}
