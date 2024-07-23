CXX=g++
CFLAGS=-Wall -g -std=c++11
LDFLAGS=
BLDDIR=build

main: main.o rubrica.o voce.o
	$(CXX) $(LDFLAGS) $(BLDDIR)/main.o $(BLDDIR)/rubrica.o $(BLDDIR)/voce.o -o $(BLDDIR)/main

main.o: main.cpp rubrica.o voce.o
	$(CXX) $(CFLAGS) -c main.cpp -o $(BLDDIR)/main.o

rubrica.o: rubrica.cpp voce.o
	$(CXX) $(CFLAGS) -c rubrica.cpp -o $(BLDDIR)/rubrica.o

voce.o: voce.cpp
	$(CXX) $(CFLAGS) -c voce.cpp -o $(BLDDIR)/voce.o

.PHONY: run
run:
	./$(BLDDIR)/main

.PHONY: clean
clean:
	rm -f $(BLDDIR)/*.o $(BLDDIR)/main

.PHONY: leak
leak: main
	valgrind --leak-check=full ./$(BLDDIR)/main