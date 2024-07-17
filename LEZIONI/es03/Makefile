CXX=g++
CFLAGS= -Wall -std=c++11
LDFLAGS=

main: main.o Dbuffer.o Dbuffer.h
	$(CXX) main.o Dbuffer.o -o main

main.o: main.cpp Dbuffer.h
	$(CXX) $(CFLAGS) -c main.cpp -o main.o

Dbuffer.o: Dbuffer.cpp Dbuffer.h
	$(CXX) $(CFLAGS) -c Dbuffer.cpp -o Dbuffer.o

run: main
	./main

clean:
	del *.o main.exe

clean_Linux:
	rm -f *.o main.exe main