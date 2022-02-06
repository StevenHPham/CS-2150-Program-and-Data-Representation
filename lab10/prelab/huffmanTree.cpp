#include "huffmanTree.h"

using namespace std;

huffmanTree::huffmanTree(){
  root = NULL;
}

huffmanTree::~huffmanTree(){
  delete root;
}



heap huffmanTree::createTree(heap h){

  while(h.size() > 1){
    
    huffmanNode* firstNode = h.findMin();
    h.deleteMin();

    huffmanNode* secondNode = h.findMin();
    h.deleteMin();

    huffmanNode* percolate = merge(firstNode , secondNode);
    h.insert(percolate);
  }

  return h;
}


huffmanNode* huffmanTree::merge(huffmanNode* firstNode , huffmanNode* secondNode){
  int firstNodeFreq = firstNode->getFreq();
  int secondNodeFreq = secondNode->getFreq();

  int totalFreq = firstNodeFreq + secondNodeFreq;

  huffmanNode* mergedNode = new huffmanNode( '0' , totalFreq);

  mergedNode->left = firstNode;
  mergedNode->right = secondNode;

  return mergedNode;
}

void huffmanTree::setPrefix(huffmanNode *root , string bin){
  if (root->left == NULL && root->right == NULL){
    cout << root->c << " " << bin << endl;
  }

  else if (root->left){
    setPrefix(root->left , bin + "0");
  } else if (root->right){
    setPrefix(root->right , bin + "1");
  }
  
}

void huffmanTree::printPrefix(huffmanNode *root , string bin){
  if (root->left == NULL && root->right == NULL){
    cout << root->c << " " << bin << endl;
  } else if (root->left){
    printPrefix(root->left , bin + "0");
  } else if (root->right){
    printPrefix(root->right , bin + "1");
  }
  
}
