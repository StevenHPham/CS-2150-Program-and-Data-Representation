#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class hashTable{
  
 private:
  int table_size;
  vector<list<string>> *table;
  string word;
  
  
  
 public:
  hashTable(int size);
  ~hashTable();
  unsigned int hashFunction(string key);
  void insert(string value);
  bool count(string value);
  bool checkprime(unsigned int p);
  int getNextPrime (unsigned int n);
  int size();
};

#endif
