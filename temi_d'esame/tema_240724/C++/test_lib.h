/**
 * @file test_lib.h
 * @author Yehan Sanjula Edirisinghe Mudiyanselage (y.edirisinghemudi@campus.unimib.it)
 * @brief file for Testing functions of albero class
 * @version 0.1
 * @date 17-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef TEST_LIB_H
#define TEST_LIB_H

#include "albero.h"
#include <cassert>

struct comp_int_cresc{
    bool operator()(int a, int b){
        return a<b;
    }
};

struct comp_int_decr{
    bool operator()(int a, int b){
        return a>b;
    }
};

struct comp_double_cresc{
    bool operator()(double a, double b){
        return a<b;
    }
};

struct comp_double_decr{
    bool operator()(double a, double b){
        return a>b;
    }
};

void test_const1(){
    try{
        albero<int, comp_int_cresc> a(23);
        std::cout << a << std::endl;
    }catch(...){
        throw;
    }
    LOG("test_const1 succeded!");
}

void test_const2(){
    try{
        int data[10] = {1,2,3,4,5,6,7,8,9,10};
        albero<int, comp_int_cresc> a(data, (data+10));
        std::cout << "input: [1,2,3,4,5,6,7,8,9,10] " << std::endl;
        std::cout << a << std::endl;
    }catch(...){
        throw;
    }
    LOG("test_const2 succeded!");
}

void test_find(){
    try{
        albero<int,comp_int_cresc> a(10);
        assert(a.find(10) == true);
        assert(a.find(5) == false);
    }catch(...){
        throw;
    }
    LOG("test_find succeded!");
}

void test_add(){
    try{
        albero<int, comp_int_cresc> a(1);
        a.add(10);
        a.add(20);
        a.add(0);
        a.add(1);
        std::cout << a << std::endl;
    }catch(...){
        throw;
    }

}

void test_subthree(){
    try{
        
        int data[10] = {1,2,3,4,5,6,7,8,9,10};
        albero<int, comp_int_cresc> a(data, (data+10));

        albero<int, comp_int_cresc>* b = a.subthree(6);
        
        std::cout << a << std::endl;
        std::cout << *b << std::endl;

        delete b;
    }catch(...){
        throw;
    }
}

void test_iter(){
    try{
        int data[10] = {1,2,3,4,5,6,7,8,9,10};
        albero<int, comp_int_cresc> a(data, (data+10));

        std::cout << a << std::endl;
        std::cout << *(a.begin()) <<std::endl;
        
    }catch(...){
        throw;
    }
}

void test_printIF(){

    struct crit_P{
        bool operator()(const int& value){
            if((value%2) == 0) return true;
            return false;
        }
    };

    int data[10] = {1,2,3,4,5,6,7,8,9,10};
    albero<int, comp_int_cresc> a(data, (data+10));

    std::cout << a << std::endl;
    printIF<int, comp_int_cresc, crit_P> (a);

}

#endif