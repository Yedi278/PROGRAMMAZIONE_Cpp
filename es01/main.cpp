#include "stringhec.h"
#include <iostream>


/**
 * @brief funzione main del codice
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[])
{

    stampa(argv[1]);
    stampa(argv[2]);

    std::cout << trova("penediocane","dioaaaaaaa") << std::endl;

    return 0;
}