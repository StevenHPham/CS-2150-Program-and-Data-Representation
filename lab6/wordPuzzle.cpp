#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <unordered_set>

#include "hashTable.h"
#include "timer.h"


using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];


// Forward declarations
//unordered_set<string> table;
int stringCount;
//hashTable table(stringCount);
//vector<list<string>> table;


void readIn(string filename);
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);


/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columns as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}

/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static string variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A STATIC string containing the letters in the provided direction.
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}




int main(int argc, char *argv[]){
  
 
  string filename = argv[1];
  string gridname = argv[2];
  
  ifstream in(filename);
  int stringCount = 0; //this is used to declare the size of the hashTable
  char str[255]; //this is to get each word from each line

 
  
 

  if(!in) { // if file does not exist, report an error
    cout << "Cannot open input file. Check file name spelling.\n";
    return 0;
  }

  while(in) { //this while loop finds the size of the word doc with variable string
    in.getline(str, 255);  
    if(in){
      stringCount++;
    }
  }
  in.clear();
  in.seekg(0);


  hashTable *table = new hashTable(stringCount);

  while(in) { //this while loop finds the size of the word doc with variable string
    in.getline(str, 255);  
    if(in){
      table->insert(str); //insert each string into the hash table
      // cout << "[main] word is inserted " << endl;
   }
 }
  in.close();


  //At this point, we have a table (dictionary) and we are ready to take in the grid.
  int rows, cols;
  //attempt to read in gridfile
  bool result = readInGrid(gridname, rows, cols);
  if(!result){
    cout << "error reading in file!" << endl;
    return 0;
  }

  //now we want to traverse the grid using a quad nested for loop, rows, columns, direction, and word length
  // start with traversing every row

  vector<string> outputVector;
  int wordsFound = 0;
  string dir;
  timer time;
  time.start();
  
  for (int row = 0 ; row < rows; row++){
    for (int col = 0; col < cols; col++){
      for(int d = 0; d < 8; d++){
	for(int len = 3; len < 23; len++){ //this makes it so we only look for words with 3 or more characters 
	  string word(getWordInGrid( row , col , d , len , rows , cols ));
	  
	    if(len > word.length()){
	      break;
	    }
	    if(table->count(word)){
	      
	      wordsFound++;
	      //cout << word << endl;
	      if (d == 0){
		dir = "N  (";
	      } else if (d == 1){
		dir = "NE (";
	      }else if (d == 2){
		dir = "E  (";
	      }else if (d == 3){
		dir = "SE (";
	      }else if (d == 4){
		dir = "S  (";
	      }else if (d == 5){
		dir = "SW (";
	      }else if (d == 6){
		dir = "W  (";
	      }else if (d == 7){
		dir = "NW (";
	      }
	      //cout << dir << row << "," << col << "):\t" << word << endl;
	      string ans;
	      ans += (dir + to_string(row) + "," + to_string(col) + "):\t" + word);
	      outputVector.push_back(ans);	      
    
	    }
	}
      }
    }
  }
  

  time.stop();
  int sec = time.getTime();
  
  
  for(auto i = outputVector.begin(); i != outputVector.end(); ++i){
    cout << *i << endl;
  }
  
  cout << wordsFound << " words found" << endl;
  // cout << sec << endl;
  return 0;
  
}

