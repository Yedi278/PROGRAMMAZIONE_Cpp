#include <iostream>
#include "myexception.h"


void funct_with_error1(void) {
	// Lanciamo di proposito una eccezione
	throw myexception1("Errore nella funzione!");
}


void funct_with_error2(void) {
	// Lanciamo di proposito una eccezione
	throw myexception2("Valore non valido!", 999);
}

int main(void) {

	try {
		funct_with_error1();
	}
	catch(myexception1 &e) {
		std::cout << e.what() << std::endl;
		// what() è un metodo della classe base std::exception
		// da cui deriva std::runtime_error
	}

	try {
		funct_with_error2();
	}
	catch(myexception2 &e) {
		std::cout << e.what() << " Value: " << e.get_value() << std::endl;
	}

	return 0;
}