// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
  stack<TreeNode*> expressionStack;
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  expressionStack.empty();
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  if(tree){
    cleanTree(tree->left);
    cleanTree(tree->right);
    delete tree;
  }

}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
   TreeNode *node = new TreeNode(val);
  // auto node = make_unique<TreeNode>(val);
 
  if (isdigit(val[0]) || (val[0] == '-' && isdigit(val[1]))){ //if the input is a number or negative number, push it onto the stack
    expressionStack.push(node);
  } else if (val[0] == '+' || val[0] == '-' || val[0] == '*' || val[0] == '/' ){
    TreeNode *right = expressionStack.top();
    expressionStack.pop();
    node->right = right;
    TreeNode *left = expressionStack.top();
    expressionStack.pop();
    node->left = left;
    expressionStack.push(node);
    
  }
  
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
  if (tree == NULL){
    return ;
  }
  cout << tree->value << " " ;
  if (tree->left != NULL){
    printPrefix(tree->left);
  }
  if (tree->right != NULL){
    printPrefix(tree->right);
  }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
  if (tree == NULL){
    return ;
  }
  if (tree->left != NULL){
    cout << "(" ;
    printInfix(tree->left);
  }
  string val = tree->value;
  if (isdigit(val[0]) || (val[0] == '-' && isdigit(val[1]))){
    cout << tree->value;
  }else{
    cout << " " << tree->value << " " ;
  }
  if (tree->right != NULL){
    printInfix(tree->right);
    cout << ")";
  }
  
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
  if (tree == NULL){
    return ;
  }
  if (tree->left != NULL){
    printPostfix(tree->left);
  }
  if (tree->right != NULL){
    printPostfix(tree->right);
  }
  cout << tree->value << " ";
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
  string key = tree->value;
  if (key[0] == '+'){
    return (calculate(tree->left) + calculate(tree->right));
  }
  else if(key[0] == '-' && !isdigit(key[1])){
    return (calculate(tree->left) - calculate(tree->right));
  }
  else if(key[0] == '*'){
    return (calculate(tree->left) * calculate(tree->right));
  } else if (key[0] == '/'){
    return (calculate(tree->left) / calculate(tree->right));
  } else{
    return atoi(key.c_str());
  }

}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
  int answer = 0;
  answer = calculate(expressionStack.top());
  return answer;
}
