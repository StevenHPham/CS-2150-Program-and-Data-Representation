#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>
#include <iostream>

using namespace std;

class huffmanNode{
 public:
  huffmanNode(char c , int freq);
  ~huffmanNode();
  
  huffmanNode *left;
  huffmanNode *right;
  
  char c;
  int freq;
  string prefix;

  int getFreq();
  char getChar();
  string getPrefix();
 
  
};

#endif
