#include "SparseMatrix.hpp"
#include "TestLib.hpp"
#include <iostream>


int main(int argv, char** argc){
    
    test_SparseMatrix();

    test_copyConstructor();

    test_iterator();

    test_evaluate_int();

    return 0;
}