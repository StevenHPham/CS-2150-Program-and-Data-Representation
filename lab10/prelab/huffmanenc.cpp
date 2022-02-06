#include "heap.h"
#include "huffmanTree.h"
#include "huffmanNode.h"

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }
    

    // read in characters one by one, until reading fails (we hit the end of the file)

    huffmanTree* tree;
    heap h;
    int symbols = 0;
    int distinct = 0;
    int ascii;

    int freq[128];
    for (int i = 0 ; i < 128 ; i++){
      freq[i] = 0;
    }

  
    char g;


    
    while (file.get(g)) {
      ascii = (int) g;
      if (ascii < 128 && ascii > 31){
	freq[ascii]++;
	symbols++;
      }
	
    }

    for (int i = 1; i < 128 ; i++){
      if (freq[i] > 0){
	huffmanNode* ptr = new huffmanNode(freq[i] , (char) i);
	h.insert(ptr);
	distinct++;
      }

    }


      
    tree = new huffmanTree();
    heap lastHeap = tree->createTree(h);
    tree->printPrefix(lastHeap.findMin(), "");

    tree->setPrefix(lastHeap.findMin(), "");
    rewind


    // a nice pretty separator
    cout << "----------------------------------------" << endl;

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    // Read the file again, and print to the screen
    while (file.get(g)) {
        cout << g;
	
    }
    cout << "----------------------------------------" << endl;

    cout << "There are a total of " << symbols << " symbols that are encoded." << endl;
    cout << "There are " << distinct << " symbols used." << endl;
    cout << "There were " << "n" << " bits in the original file." << endl;
    cout << "There were " << "n" << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << "n" << endl;
    cout << "This cost of the Huffman tree is " << "n" << " bits per character." << endl;

    

    // close the file
    file.close();
}


