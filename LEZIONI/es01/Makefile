CXX=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=

all: main.o stringhec.o
	$(CXX) main.o stringhec.o -o Main.exe

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp -o main.o

stringhec.o: stringhec.cpp
	$(CXX) $(CFLAGS) stringhec.cpp -o stringhec.o

clean:
	@del *.o
	@del *.exe

run:
	@./Main.exe pupu caca