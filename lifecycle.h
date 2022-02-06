#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include <string>
#include <iostream>
using namespace std;

// Declare the MyObject class
//** Added to lifecycle.h
//**** Class declaration belongs in header file
class MyObject {
public:
   static int numObjs;

 MyObject();                    // default constructor
 MyObject(string n);            // constructor with name parameter
 MyObject(const MyObject& rhs); // copy constructor
 ~MyObject();                   // destructor

 string getName() const;
 void setName(const string& newName);

 friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

// Let cout know how to print MyObjects
//** Function prototypes belong in header file

ostream& operator<<(ostream& output, const MyObject& obj);

int cmpMyObj(const MyObject o1, const MyObject o2);

MyObject getMaxMyObj(const MyObject o1, const MyObject);

void swapMyObj(MyObject& o1, MyObject& o2);


#endif
