#include "Dynamic_Buffer.h"


int main(int argc, char* argv[]){

    dnb::dynamic_buffer d1,d2;
    d1.size = 10;

    dnb::alloc(&d1, 10);
    dnb::init(&d1);
    dnb::insert(&d1, 2, 25);
    dnb::insert(&d1, 3, 26);
    dnb::insert(&d1, 4, 27);

    dnb::stampa(d1);

    init(&d2);
    dnb::copy(d1, &d2);

    stampa(d2);

    dnb::dealloc(&d1);
    dnb::dealloc(&d2);
    return 0;
}