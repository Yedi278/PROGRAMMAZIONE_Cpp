#ifndef TEST_LIB_H
#define TEST_LIB_H

#include <iostream>
#include <cassert>
#include "Multiset.hpp"

#define RED "\e[38;5;196m"
#define GREEN "\e[38;5;46m"
#define RESET "\e[0m"


struct comp_int_eq {
    bool operator()(const int& a, const int& b) const {
        return a == b;
    }
};

struct comp_int {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

void test_constructor(void){
    try{
        Multiset<int, comp_int, comp_int_eq> m;
        assert(m.size() == 0);

        m.add(1);
        m.add(2);
        m.add(2);
        assert(m.size() == 3);
    }catch(...){
        std::cerr << "test_constructor " RED "failed" RESET << std::endl;
        throw;
    }

    std::cout << "test_constructor " GREEN "passed" RESET << std::endl;
}

void test_add(){
    try{
        Multiset<int, comp_int, comp_int_eq> m;
        m.add(1);
        m.add(2);
        m.add(2);
        assert(m.size() == 3);
    }catch(...){
        std::cerr << "test_add " RED "failed" RESET << std::endl;
        throw;
    }

    std::cout << "test_add " GREEN "passed" RESET << std::endl;
}

#endif