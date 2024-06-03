#include "Dbuffer.h"
#include <iostream>
#include <ostream>
#include <algorithm>
#include <cassert>

dbuffer::dbuffer() : _size(0), _buffer(0){
    
    #ifndef NDEBUG
    std::cout << "dbuffer() called!" << std::endl;
    #endif
}

dbuffer::dbuffer(unsigned int size) : _size(0), _buffer(0){

    _buffer = new int[size];
    _size=size;

    #ifndef NDEBUG
    std::cout << "dbuffer(unsigned int size) called!" << std::endl;
    #endif
}

dbuffer::dbuffer(unsigned int size, int value) : _size(0), _buffer(0){

    _buffer = new int[size];
    _size=size;

    for(unsigned int i=0; i<size; i++){
        _buffer[i] = value;
    }

    #ifndef NDEBUG
    std::cout << "dbuffer(unsigned int size, int value) called!" << std::endl;
    #endif
}

dbuffer::dbuffer(const dbuffer &other) : _size(0), _buffer(0){

    _buffer = new int[other._size];
    _size = other._size;

    for(unsigned int i=0; i<other._size; i++){
        _buffer[i] = other._buffer[i];
    }

    #ifndef NDEBUG
    std::cout << "dbuffer(const dbuffer &other)" << std::endl;
    #endif
}

dbuffer::~dbuffer(){
    
    if(_buffer != nullptr){
        delete[] _buffer; 
    }
    
    _buffer = nullptr;
    _size=0;
    
    #ifndef NDEBUG
    std::cout << "~dbuffer() called!" << std::endl;
    #endif
}

dbuffer& dbuffer::operator=(const dbuffer &other){

    if(this != &other){ // controllo autoassegnamento

        dbuffer tmp(other);

        std::swap(this->_size, tmp._size);
        std::swap(this->_buffer, tmp._buffer);

        /* unsigned int tmpsize=other._size;
        int* tmpbuff = new int[other._size];
        
        for(unsigned int i=0; i<other._size; i++){
            tmpbuff[i] = other._buffer[i];
        }

        if(this->_buffer != nullptr){ // controllo
            delete[] this->_buffer;
            this->_buffer = nullptr;
            this->_size=0;
        }

        this->_buffer = tmpbuff;
        this->_size = tmpsize; */
    }
    return *this;
}

int& dbuffer::value(unsigned int index){
    assert(index < _size);
    return _buffer[index];
}

int& dbuffer::operator[](unsigned int index){
    assert(index < _size);
    return _buffer[index];
}

const int& dbuffer::operator[](unsigned int index)const{
    assert(index < _size);
    return _buffer[index];
}

void dbuffer::print()const{

    std::cout << "------- [ init array ] -------" << std::endl;
    std::cout << "Size of array: " << _size << std::endl;

    for(unsigned int i=0; i<_size; i++)
        std::cout << _buffer[i] << " ";
    
    std::cout << "\n------- [ end array ] -------" << std::endl;
}

unsigned int dbuffer::get_size() const{
    return _size;
}

std::ostream &operator<<(std::ostream &os, const dbuffer &db){

    os << "------- [ init array ] -------" << std::endl;
    os << "Size of array: " << db._size << std::endl;
 
    for(unsigned int i=0; i<db._size; i++)
        os << db[i] << " ";
    
    os << "\n------- [ end array ] -------" << std::endl;

    return os;
}

dbuffer& dbuffer::operator++(){

    for(unsigned int i=0; i<_size; i++)
        _buffer[i]++;
    
    return *this;
}

dbuffer dbuffer::operator++(int){

    dbuffer tmp(*this);

    for(unsigned int i=0; i<_size; i++)
        _buffer[i]++;
    
    return tmp;
}