#include "Dynamic_Buffer.h"
#include <iostream>
#include <cassert>
#define LOG(x) std::cerr<< x << std::endl

namespace dnb{

    void stampa(dynamic_buffer d);
    void alloc(dynamic_buffer* d, int size);
    void init(dynamic_buffer* d);
    void dealloc(dynamic_buffer* d);
    void insert(dynamic_buffer* d,unsigned int index, int data);
    void copy(dynamic_buffer d1, dynamic_buffer* d2);
}

void dnb::stampa(dynamic_buffer d){
    
    assert(&d != NULL);
    
    std::cout << "Inizio Buffer!" << std::endl;
    for(unsigned int i=0; i<d.size; i++){
        std::cout << i << " : " << d.buffer[i] << std::endl;
    }
    std::cout << "Fine Buffer!" << std::endl;
}

void dnb::alloc(dynamic_buffer* d, int size){

    assert(d != NULL);

    d->size = size+1;

    if(d->buffer != NULL){
        dnb::dealloc(d);
    }

    try{
        d->buffer = new int[d->size];
    }
    catch(...){
        throw;
    }
}

void dnb::init(dynamic_buffer* d){

    assert(d != NULL);

    for(unsigned int i=0; i<d->size; i++){
        
        d->buffer[i] = 0;
        //     std::cerr << "init() : errore nella riscrittura dei valori, controllare grandezza dell'array!" << std::endl;
    }
}

void dnb::dealloc(dynamic_buffer* d){

    delete[] d->buffer;
    d->buffer = NULL;
}

void dnb::insert(dynamic_buffer* d,unsigned int index, int data){

    assert(d != NULL);
    if(index > d->size){
        std::cerr << "insert() : index must be smaller than buffer size!"<< std::endl;
        return;
    }
    d->buffer[index] = data;
}

void dnb::copy(dynamic_buffer d1, dynamic_buffer* d2){

    assert(d2 != NULL);

    dnb::dealloc(d2);
    try{
        dnb::alloc(d2, d1.size);
    }catch(...){
        throw;
    }

    for(unsigned int i=0; i<d1.size; i++){
        d2->buffer[i] = d1.buffer[i];
    }

}