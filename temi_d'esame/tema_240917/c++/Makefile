CXX = g++
CXXFLAGS_debug = -Wall -g -std=c++11
CXXFLAGS_release = -O2 -s -DNDEBUG -std=c++11

CXXFLAGS = $(CXXFLAGS_debug)
# CXXFLAGS = $(CXXFLAGS_release)

default: main

main: main.o
	$(CXX) $(CXXFLAGS) -o build/main build/main.o

main.o: main.cpp SparseMatrix.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

clean:
	rm -f build/*.o build/main

run: main
	./build/main