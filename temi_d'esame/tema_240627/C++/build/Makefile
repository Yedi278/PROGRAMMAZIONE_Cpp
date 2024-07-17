CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

SRC=../src/

main: main.o
	$(CXX) $(CXXFLAGS) main.o -o main

main.o: $(SRC)main.cpp $(SRC)Multiset.hpp $(SRC)test_lib.h
	$(CXX) $(CXXFLAGS) -c $(SRC)main.cpp -o main.o

.PHONY: clean
clean:
	rm -f $(SRC)*.o main

.PHONY: run
run:
	@echo
	@echo "Running main..."
	@echo
	./main

.PHONY: leak
leak:
	@echo
	@echo "Running valgrind..."
	@echo
	valgrind --leak-check=full ./main