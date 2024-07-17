#include "myexception.h"

myexception1::myexception1(const std::string &message) 
	: std::runtime_error(message) {
		// il messaggio è forwardato alla classe std::runtime_error 
		// che a sua volta lo passerà alla classe std::exception
	}


myexception2::myexception2(const std::string &message, int value) 
	: std::logic_error(message), _value(value) { }

int myexception2::get_value(void) const {
	return _value;
}