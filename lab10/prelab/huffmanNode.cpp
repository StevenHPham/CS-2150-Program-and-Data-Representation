#include "huffmanNode.h"

using namespace std;

huffmanNode::huffmanNode(char c , int freq){
  freq = freq;
  c = c;
  left = NULL;
  right = NULL;
  prefix = "";
}

huffmanNode::~huffmanNode(){
  delete left;
  delete right;
}

int huffmanNode::getFreq() {
  return freq;
}

char huffmanNode::getChar(){
  return c;
}

string huffmanNode::getPrefix(){
  return prefix;
}


