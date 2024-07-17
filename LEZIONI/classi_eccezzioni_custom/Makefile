CCFLAGS = -Wall -pedantic

main.exe:  main.o myexception.o
	g++ main.o myexception.o -o main.exe

main.o: main.cpp 
	g++ $(CCFLAGS) -c main.cpp -o main.o

myexception.o: myexception.cpp 
	g++ $(CCFLAGS) -c myexception.cpp -o myexception.o


clean:
	rm *.o *.exe