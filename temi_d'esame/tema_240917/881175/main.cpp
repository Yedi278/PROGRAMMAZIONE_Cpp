#include "SparseMatrix.hpp"
#include "TestLib.hpp"


int main(int argv, char** argc){
    
    test_SparseMatrix();

    test_copyConstructor();

    test_iterator();

    test_evaluate_int();

    LOGGREEN("Tutti i test sono stati eseguiti con successo");

    return 0;
}