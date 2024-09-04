CXX = g++

CXXFLAGS_debug = -Wall -g -std=c++11
CXXFLAGS_release = -O2 -s -DNDEBUG -std=c++11 

#select one of the following:
CXXFLAGS = $(CXXFLAGS_debug)	#with debug info
# CXXFLAGS = $(CXXFLAGS_release)	#witout debug info and optimised

default: main

main: main.o
	$(CXX) $(CXXFLAGS) -o build/main build/main.o

main.o: main.cpp SparseMatrix.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

#only linux
clean:
	rm -f build/*.o build/main

run: main
	./build/main