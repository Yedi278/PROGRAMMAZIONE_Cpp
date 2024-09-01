#ifndef TEST_LIB_HPP
#define TEST_LIB_HPP

#include "SparseMatrix.hpp"

void test_SparseMatrix(){

    try{
        //creazione matrice 10x10 con valore di default -1
        SparseMatrix<int> mat(10,10, -1);

        mat.printInfo();

        //set valore normale
        mat.set(25,5,4);
        mat.set(6,9,5);

        //cambio valore
        mat.set(12,2,4);
        mat.set(10,2,4);
        
        //set valore di default
        mat.set(-1, 6,2);

        //rimozione valore
        mat.set(-1,5,4);

        mat.printData();

        LOG("Fine Primo Test");

    }catch(...){

        std::cerr << "Test SparseMatrix fallito" << std::endl;
    }
}

void test_copyConstructor(){
    
    try{
        //creazione matrice 10x10 con valore di default -1
        SparseMatrix<int> mat(10,10, -1);

        mat.set(25,5,4);
        mat.set(12,2,4);
        mat.set(10,2,4);
        mat.set(6,9,5);

        mat.set(-1, 6,2);

        mat.printData();

        //copia matrice
        SparseMatrix<int> mat2(mat);

        mat2.printData();

        LOG("Fine Copyconstructor Test");
    
    }catch (...){
        std::cerr << "Test CopyConstructor fallito" << std::endl;
    }
}

void test_iterator(){

    try{
        //creazione matrice 10x10 con valore di default -1
        SparseMatrix<int> mat(10,10, -1);

        mat.set(25,5,4);
        mat.set(12,2,4);
        mat.set(10,2,4);
        mat.set(6,9,5);

        mat.set(-1, 6,2);

        mat.printData();

        //test iteratori
        for(SparseMatrix<int>::const_iterator i = mat.begin(); i != mat.end(); i++){
            std::cout << (*i)._value << ", ";
        }

        std::cout << std::endl;

        LOG("Fine Iterator Test");

    }catch(...){

        std::cerr << "Test Iterator fallito" << std::endl;
    }
}

struct P_even{
    bool operator()(const int& value){
        if((value%2) == 0) return true;
        return false;
    }
};

struct P_size{
    bool operator()(const int& value){
        if(value >= 10) return true;
        return false;
    }
};

void test_evaluate_int(){

    try{

    LOG("Evaluate con D=-1 - even");
    SparseMatrix<int> mat(10,10, -1);

    mat.set(25,5,4);
    mat.set(12,2,4);
    mat.set(10,2,4);
    mat.set(6,9,5);

    mat.set(-1, 6,2);

    mat.printData();

    std::cout << "counter valori pari: " << evaluate<int,P_even>(mat) << std::endl;

    LOG("Evaluate con D=0 - even");

    SparseMatrix<int> mat2(10,10, 0);

    mat2.set(25,5,4);
    mat2.set(12,2,4);
    mat2.set(10,2,4);
    mat2.set(6,9,5);

    mat2.printData();

    std::cout << "counter valori pari: " << evaluate<int,P_even>(mat2) << std::endl;

    LOG("Evaluate con D=0 - size");

    SparseMatrix<int> mat3(10,10, 0);

    mat3.set(25,5,4);
    mat3.set(12,2,4);
    mat3.set(10,2,4);
    mat3.set(6,9,5);

    mat3.printData();

    std::cout << "counter valori maggiori e uguali a 10 : " << evaluate<int,P_size>(mat3) << std::endl;

    LOG("Fine Evaluate Test");
    }catch(...){
        std::cerr << "Test Evaluate fallito" << std::endl;
    }
}

#endif