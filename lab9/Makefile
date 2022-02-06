#Steven Pham Lab 8am

CXX=clang $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g

Makefile: linkedlist.o
	$(CXX) $(DEBUG) linkedlist.o

linkedlist.o: linkedlist.c

.PHONY: clean
clean:
	-rm -f *.o a.out