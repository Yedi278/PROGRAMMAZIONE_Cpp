#include <iostream>

template <typename T>
class SparseMatrix
{
public:

    typedef unsigned long int size_type;
    typedef T   value_type;
    
    SparseMatrix() = delete;
    
    SparseMatrix(const size_type& n,const size_type& m, value_type D): head(nullptr), _n(n), _m(m), _D(D){};

    SparseMatrix(const SparseMatrix& mat){};

    void printInfo(){
        std::cout << "------------------" << std::endl;
        std::cout << "Size: " << _n << " x " << _m << std::endl;
        std::cout << "Default D: " << _D << std::endl;
        std::cout << "------------------" << std::endl;

    }

    void set(const value_type& value, const size_type& x,const size_type& y){
        node* tmp = head;

        while(tmp != nullptr){
            if( tmp->_x == x && tmp->_y == y){

                tmp->_value = value;             
            }
        }
    }

    ~SparseMatrix(){};

private:

    size_type _n;
    size_type _m;
    value_type _D;

    struct node{
        size_type _x;
        size_type _y;
        T _value;
    };

    node* head;
};