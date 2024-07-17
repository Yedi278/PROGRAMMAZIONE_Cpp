#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <stdexcept>
#include <string>

/**
	Classe eccezione custom che deriva da std::runtime_error
*/
class myexception1 : public std::runtime_error {
public:
	/**
		Costruttore che prende un messaggio d'errore
	*/
	myexception1(const std::string &message);
};


/**
	Classe eccezione custom che deriva da std::logic_error
*/
class myexception2 : public std::logic_error {
	int _value;
public:
	/**
		Costruttore che prende un messaggio d'errore
	*/
	myexception2(const std::string &message, int value);

	int get_value(void) const;
};

#endif