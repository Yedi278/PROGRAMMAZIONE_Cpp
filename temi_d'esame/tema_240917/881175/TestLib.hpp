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
        assert(mat(5,4) == 25);
        mat.set(6,9,5);
        assert(mat(9,5) == 6);

        //cambio valore
        mat.set(12,2,4);
        assert(mat(2,4) == 12);
        mat.set(10,2,4);
        assert(mat(2,4) == 10);
        
        //set valore di default
        mat.set(-1, 6,2);
        assert(mat(6,2) == -1);

        //rimozione valore
        mat.set(-1,5,4);
        assert(mat(5,4) == -1);

        mat.printData();

        LOGGREEN("Fine Primo Test");

    }catch(...){

        LOGRED("Test SparseMatrix fallito");
    }
}

void test_copyConstructor(){
    
    try{
        //creazione matrice 10x10 con valore di default -1
        SparseMatrix<int> mat(10,10, -1);

        mat.set(25,5,4);
        assert(mat(5,4) == 25);
        mat.set(12,2,4);
        assert(mat(2,4) == 12);
        mat.set(10,2,4);
        assert(mat(2,4) == 10);
        mat.set(6,9,5);
        assert(mat(9,5) == 6);

        mat.set(-1, 6,2);
        assert(mat(6,2) == -1);

        assert(mat.get_D() == -1);
        mat.printData();

        //copia matrice
        SparseMatrix<int> mat2(mat);

        assert(mat2(5,4) == 25);
        assert(mat2(2,4) == 10);
        assert(mat2(9,5) == 6);
        assert(mat2(6,2) == -1);
        assert(mat2.get_D() == -1);
        mat2.printData();

        LOGGREEN("Fine Copyconstructor Test");
    
    }catch (...){
        LOGRED("Test CopyConstructor fallito");
    }
}

void test_iterator(){

    try{
        //creazione matrice 10x10 con valore di default -1
        SparseMatrix<int> mat(10,10, -1);

        mat.set(25,5,4);
        assert(mat(5,4) == 25);
        mat.set(12,2,4);
        assert(mat(2,4) == 12);
        mat.set(10,2,4);
        assert(mat(2,4) == 10);
        mat.set(6,9,5);
        assert(mat(9,5) == 6);

        mat.set(-1, 6,2);
        assert(mat(6,2) == -1);

        mat.printData();

        //test iteratori
        LOGBLUE("controllare che i seguenti valori combacino con quelli precendenti: ");
        for(SparseMatrix<int>::const_iterator i = mat.begin(); i != mat.end(); i++){
            std::cout << (*i)._value << ", ";
        }

        std::cout << std::endl;

        LOGGREEN("Fine Iterator Test");

    }catch(...){
        LOGRED("Test Iterator fallito");
    }
}

struct P_even{
    bool operator()(const int& value){
        if((value%2) == 0) return true;
        return false;
    }
};

struct P_odd{
    bool operator()(const int& value){
        if((value%2) != 0) return true;
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
        
        SparseMatrix<int>::size_type count = 0;

        count  = evaluate<int,P_even>(mat);
        std::cout << "counter valori pari: " << count << std::endl;
        assert(count == 2);

        ////////////////////////////////////////////////////////////////////

        LOG("Evaluate con D=-1 - odd");

        count  = evaluate<int,P_odd>(mat);
        std::cout << "counter valori dispari: " << count << std::endl;
        assert(count == (10*10 - 2));

        ////////////////////////////////////////////////////////////////////

        LOG("Evaluate con D=0 - even");

        SparseMatrix<int> mat2(10,10, 0);

        mat2.set(25,5,4);
        mat2.set(12,2,4);
        mat2.set(10,2,4);
        mat2.set(6,9,5);

        mat2.printData();

        count = evaluate<int,P_even>(mat2);
        std::cout << "counter valori pari: " << evaluate<int,P_even>(mat2) << std::endl;
        assert(count == 99);

        //////////////////////////////////////////////////////////////////

        LOG("Evaluate con D=0 - odd");

        count = evaluate<int,P_odd>(mat2);
        std::cout << "counter valori dispari: " << evaluate<int,P_odd>(mat2) << std::endl;
        assert(count == 1);

        ////////////////////////////////////////////////////////////////////

        LOG("Evaluate con D=0 - size");

        SparseMatrix<int> mat3(10,10, 0);

        mat3.set(25,5,4);
        mat3.set(12,2,4);
        mat3.set(10,2,4);
        mat3.set(6,9,5);

        mat3.printData();

        count = evaluate<int,P_size>(mat3);
        std::cout << "counter valori maggiori e uguali a 10 : " << count << std::endl;
        assert(count == 2);

        LOGGREEN("Fine Evaluate Test");
    }catch(...){
        std::cerr << "Test Evaluate fallito" << std::endl;
    }
}

void test_get_funcs(){
    
    try{
        SparseMatrix<int> mat(10,6, -1);

        assert(mat.get_row() == 10);
        assert(mat.get_col() == 6);
        assert(mat.get_D() == -1);

        LOGGREEN("Fine Test Get Funcs");

    }catch(...){
        LOGRED("Test Get Funcs fallito");
    }
}

#endif