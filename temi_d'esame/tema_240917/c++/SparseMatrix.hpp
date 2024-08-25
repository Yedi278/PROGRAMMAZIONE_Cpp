#include <iostream>
#include <cassert>

template <typename T>
class SparseMatrix
{
public:

    typedef unsigned long int size_type;
    typedef T                 value_type;

private:

    size_type _n;   //row size
    size_type _m;   //column size
    value_type _D;  //Default value

    struct node{
        size_type _x;
        size_type _y;
        T _value;
        node* _next;

        explicit node(size_type x, size_type y, T value): _x(x), _y(y), _value(value), _next(nullptr){};
        ~node(){/*empty by design*/};
    };

    node* _head;

public:
    
    SparseMatrix() = delete;
    
    SparseMatrix(const size_type& n,const size_type& m, value_type D): _head(nullptr), _n(n), _m(m), _D(D){};

    SparseMatrix(const SparseMatrix& mat): _n(mat._n), _m(mat._m), _D(mat._D), _head(nullptr){
        assert(&mat != this);

        node* tmp = mat._head;
        while (tmp != nullptr){
            this->set(tmp->_value, tmp->_x, tmp->_y);
            tmp = tmp->_next;
        }
    }

    void printInfo() const{
        std::cout << "------------------" << std::endl;
        std::cout << "Size: " << _n << " x " << _m << std::endl;
        std::cout << "Default value D: " << _D << std::endl;
        std::cout << "------------------" << std::endl;
    }

    void printData() const{
        node* tmp = _head;
        std::cout << "Matrix Values: " << std::endl;
        while (tmp != nullptr){
            std::cout << tmp->_value << " : " << tmp->_x << ", " << tmp->_y << std::endl;
            tmp = tmp->_next;
        }
        std::cout << std::endl;
    }

    void set(const value_type& value, const size_type& x,const size_type& y){

        assert(x < _n);
        assert(y < _m);

        if(_head == nullptr){
            if(value == _D) return;

            _head = new node(x,y,value);
            return;
        }

        node* tmp = _head;
        node* prev = _head;

        while(tmp != nullptr){
            
            if( tmp->_x == x && tmp->_y == y){
                
                if(value == _D){
                    node* next = tmp->_next;

                    if(tmp == _head) {
                        delete _head;
                        _head = nullptr;
                        _head = next;
                        return;
                    }
                    delete tmp;
                    prev->_next = next;
                    return;
                }

                tmp->_value = value;
                return;           
            }
            prev = tmp;
            tmp = tmp->_next;
        }
        if( value == _D) return;
        
        node* new_node = new node(x,y,value);
        prev->_next = new_node;
    }

    value_type operator()(const size_type& x, const size_type& y){
        node* tmp = _head;

        while(tmp != nullptr){

            if( tmp->_x == x && tmp->_y == y){
                return tmp->_value;
            }
            tmp = tmp->_next;
        }

        return _D;
    }

    ~SparseMatrix(){
        node* tmp = _head;
        node* prev = _head;
        while(tmp!= nullptr){
            prev = tmp;
            tmp = tmp->_next;
            delete prev;
        }
    }


    
};