#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "heap.h"
#include "huffmanNode.h"

using namespace std;

class huffmanTree{
 public:
  huffmanTree();
  ~huffmanTree();

  huffmanNode *root;

  huffmanNode* merge(huffmanNode* firstNode, huffmanNode* secondNode);
  heap createTree(heap h);

  void setPrefix(huffmanNode* root , string bin);
  void printPrefix(huffmanNode* root , string bin);
};

#endif
