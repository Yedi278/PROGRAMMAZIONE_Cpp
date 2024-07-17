CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

SRC=../src/

main: $(SRC)main.o
	$(CXX) $(CXXFLAGS) $(SRC)main.o -o main

main.o: $(SRC)main.cpp	$(SRC)MultiSet.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC)main.cpp -o $(SRC)main.o

.PHONY: clean
clean:
	rm -f $(SRC)*.o main

.PHONY: run
run:
	./main