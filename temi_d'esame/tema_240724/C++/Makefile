CXX = g++
CFLAGS = -Wall -g -std=c++11
INCLUDES = -Ibuild

main: main.o
	$(CXX) $(CFLAGS) build/main.o -o build/main

main.o: main.cpp albero.h test_lib.h
	$(CXX) $(CFLAGS) -c main.cpp -o build/main.o

.PHONY: run leak clean
run:
	@echo
	@echo Running the code...
	./build/main
	@echo

leak:
	valgrind --leak-check=yes -s ./build/main

clean:
	@echo Cleaning the build directory...
	rm -rf build/*.o build/*.exe build/main
	@echo directory cleaned!