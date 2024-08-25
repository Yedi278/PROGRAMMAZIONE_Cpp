#include "SparseMatrix.hpp"

int main(int argv, char** argc){
    
    SparseMatrix<int> mat(10,10, -1);

    mat.printInfo();

    mat.set(25,5,4);
    mat.set(12,2,4);
    mat.set(10,2,4);
    mat.set(5,9,5);

    mat.set(-1, 6,2);


    mat.printData();

    std::cout << mat(11,5) << std::endl;

    SparseMatrix<int> mat2(mat);
    mat2.printData();

    return 0;
}