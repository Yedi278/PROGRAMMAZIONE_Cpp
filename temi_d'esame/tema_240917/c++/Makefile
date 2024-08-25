CXX = g++
CXXFLAGS = -Wall -g -std=c++11

all: main

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o

main.o: main.cpp SparseMatrix.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	del main main.o