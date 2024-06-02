CXX=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=-lm

all: main.o Dynamic_Buffer.o
	$(CXX) main.o Dynamic_Buffer.o -o Main $(LDFLAGS)

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp -o main.o

Dynamic_Buffer.o: Dynamic_Buffer.cpp
	$(CXX) $(CFLAGS) Dynamic_Buffer.cpp -o Dynamic_Buffer.o

run:
	./Main

clean:
	del *.o Main