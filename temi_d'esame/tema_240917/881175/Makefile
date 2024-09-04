CXX = g++

CXXFLAGS_debug = -Wall -g -std=c++11
CXXFLAGS_release = -O2 -s -DNDEBUG -std=c++11 

BLD_DIR = build

#select one of the following:
CXXFLAGS = $(CXXFLAGS_debug)	#with debug info
# CXXFLAGS = $(CXXFLAGS_release)	#witout debug info and optimised

default: main

main: main.o
	$(CXX) $(CXXFLAGS) -o $(BLD_DIR)/main $(BLD_DIR)/main.o

main.o: main.cpp SparseMatrix.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(BLD_DIR)/main.o

#only linux
clean:
	rm -f $(BLD_DIR)/*.o $(BLD_DIR)/main

run: main
	./$(BLD_DIR)/main