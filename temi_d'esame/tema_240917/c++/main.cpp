#include "SparseMatrix.hpp"

int main(int argv, char** argc){
    
    SparseMatrix<int> mat(10,10, -1);

    mat.printInfo();

    return 0;
}