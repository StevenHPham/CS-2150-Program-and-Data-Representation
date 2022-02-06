#include <iostream>
#include <string>

using namespace std;



int floor(int n){
  if (n == 0){
    return 0;
  } else if (n == 1){
    return 1;
  } else if (n % 2 == 1){
    return floor(n/2) + 1;
  } else{
    return floor(n/2);
  }
}







string baseConverter( string s, int start ,int end){

  int basePower = 1;
  int resultBaseTen = 0;
  int str = s.size() - 1;
  string value = "" ;

    //conversion from given base to base 10
  while (str >= 0){
    //loop through each value of the given string starting at the last index and end at the first index
    int decimal = s[str] - '0';
    
     if ( s[str] >= 'A' && s[str] <= 'Z'){      //check the value is A-Z to base 36
      decimal = s[str] + 10 - 'A';             //replace hexademical with decimal
      resultBaseTen += basePower * decimal;
      basePower = basePower * start;
      str--;
     } else{
       
       resultBaseTen += basePower * decimal;
       basePower = basePower * start;
       str--;
     }
  }

    //conversion from base 10 to end base. At this point we have our results in resultBaseTen. 
  while (resultBaseTen){ 
    char p;
    int remainder = resultBaseTen % end;
    value = " " + value;
    if (remainder < 10){
      p = remainder + '0';
    }else{
      p = remainder - 10 + 'A';
    }
    value[0] = p;
    resultBaseTen /= end;
  }
  return value;
}






int main( int argc, char **argv){

  if (argc < 5){
    cout << "invalid numbers of parameter" << endl;
 
  } else{
    
  int input = atoi(argv[1]);
  int fl = floor(input);
  printf("%d has %d bit(s) \n", input, fl);

  string s = argv[2];
  int start = atoi(argv[3]);
  int end = atoi(argv[4]);
  string result = baseConverter(s,start,end);
  printf( "%s (base %d) = %s (base %d) \n", s.c_str(), start, result.c_str() ,end);


  
  }
  return 0;
}
