#include "Dbuffer.h"
#include <iostream>
#include <cassert>

int main(int argc,char *argv[]){

    dbuffer d1(10,1);
    
    d1[3] = 4;
    std::cout << d1.get_size() << std::endl;
    
    std::cout << d1;

    
    std::cout << ++d1;

    return 0;
}