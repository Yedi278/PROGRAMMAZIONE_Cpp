#ifndef TEST_LIB_HPP
#define TEST_LIB_HPP

#include "SparseMatrix.hpp"

void test_SparseMatrix(){
    SparseMatrix<int> mat(10,10, -1);

    mat.printInfo();

    mat.set(25,5,4);
    mat.set(12,2,4);
    mat.set(10,2,4);
    mat.set(6,9,5);

    mat.set(-1, 6,2);

    mat.printData();

    LOG("Fine Primo Test");
}

void test_copyConstructor(){
    SparseMatrix<int> mat(10,10, -1);

    mat.set(25,5,4);
    mat.set(12,2,4);
    mat.set(10,2,4);
    mat.set(6,9,5);

    mat.set(-1, 6,2);

    mat.printData();

    SparseMatrix<int> mat2(mat);

    mat2.printData();

    LOG("Fine Copyconstructor Test");
}

void test_iterator(){
    SparseMatrix<int> mat(10,10, -1);

    mat.set(25,5,4);
    mat.set(12,2,4);
    mat.set(10,2,4);
    mat.set(6,9,5);

    mat.set(-1, 6,2);

    mat.printData();

    for(SparseMatrix<int>::const_iterator i = mat.begin(); i != mat.end(); i++){
        std::cout << (*i)._value << ", ";
    }

    std::cout << std::endl;

    LOG("Fine Iterator Test");
}

struct P_even{
    bool operator()(const int& value){
        if((value%2) == 0) return true;
        return false;
    }
};

void test_evaluate_int(){

    LOG("Evaluate con D=-1");
    SparseMatrix<int> mat(10,10, -1);

    mat.set(25,5,4);
    mat.set(12,2,4);
    mat.set(10,2,4);
    mat.set(6,9,5);

    mat.set(-1, 6,2);

    mat.printData();

    std::cout << "counter : " << evaluate<int,P_even>(mat) << std::endl;

    LOG("Evaluate con D=0");

    SparseMatrix<int> mat2(10,10, 0);

    mat2.set(25,5,4);
    mat2.set(12,2,4);
    mat2.set(10,2,4);
    mat2.set(6,9,5);

    mat2.printData();

    std::cout << "counter : " << evaluate<int,P_even>(mat2) << std::endl;

    LOG("Fine Evaluate Test");
}


#endif