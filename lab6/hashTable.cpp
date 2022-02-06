#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <list>

#include "hashTable.h"
using namespace std;


hashTable::hashTable(int size){// create a table with size of the dictionary,
  //static vector<list<string>> table;
  table = new vector<list<string>>;
  //cout << "before resize expected: 0" << endl;
  //cout  << table->size() << endl;
  table->resize(size) ;
  //cout << "past first resize expected 30" << endl;
  //cout  << table->size() << endl;
  
  if( checkprime( size ) ){
    table_size = 2 * size;
  }else{
    table_size *= 2;
    table_size = getNextPrime( size );
  }
 
  table->resize( table_size  );
  //cout << "last resize to next prime number" << endl;
  //cout  << table->size() << endl;

  for(int i = 0; i < table_size; i++) {
  list<string> temp;
  table->push_back(temp);
  //cout << temp << endl;
  
  }
} 

hashTable::~hashTable(){
   delete table;
}

int hashTable::size(){
  return table_size;
}


unsigned int hashTable::hashFunction(string value){

  unsigned int hash = 0;
  for (char i = 0; i < value.length(); i++){
    hash += ( 37 + value[i] )%table_size;
  }
  return hash;
}

void hashTable::insert(string value){
  table->at(hashFunction(value)).push_back(value);
  // cout << "[inside function] word is inserted" << endl;
}

bool hashTable::count(string value){

  list<string> &list = table->at(hashFunction(value));
  for(::list<string>::iterator i = list.begin(); i != list.end(); i++){
    
    if (value == *i){
      //cout << list.front() << endl;
      return true;
    }
  }
  return false;
}

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
