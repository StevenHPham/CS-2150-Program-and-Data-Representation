#Steven Pham Lab 8am
#clang++ -MM *.cpp

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g

Makefile: wordPuzzle.o hashTable.o timer.o
	$(CXX) $(DEBUG) wordPuzzle.o hashTable.o timer.o

wordPuzzle.o: wordPuzzle.cpp hashTable.h

hashTable.o: hashTable.cpp hashTable.h

timer.o: timer.cpp timer.h


.PHONY: clean
clean:
	-rm -f *.o a.out