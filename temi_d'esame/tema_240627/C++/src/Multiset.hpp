#ifndef MULTISET_LIB_HPP
#define MULTISET_LIB_HPP

#include <iostream>
#include <cassert>

// comment to remove verbose
// #define N_VERBOSE

#ifndef N_VERBOSE
#define LOG(X) std::cout << X << std::endl
#else
#define LOG(X)
#endif


template <typename T, typename C, typename E>
class Multiset {

public:
    typedef T value_type;
    typedef unsigned long int  size_type;

private:
    struct node {
        
        value_type _value;
        size_type _count;
        node* _next;

        node() = delete;

        node(const value_type& value) : _value(value), _count(1), _next(nullptr){
            LOG("node created with value: " << value);
        }
        node(const value_type& value, size_type count) : _value(value), _count(count), _next(nullptr) {
            LOG("node created with value: " << value << " and count: " << count);
        }
        
        ~node(){
            LOG("node destroyed with value: " << _value);
            _next = nullptr;
        }
    };

    node* _head;
    size_type _size;
    C _comparator;
    E _eq_comparator;

public:

    Multiset(void) : _head(nullptr), _size(0) {
        LOG("Multiset created");
    }

    size_type size(void) const {
        return _size;
    }

    void add(const value_type& value){

        // if the list is empty
        if(_head == nullptr){

            _head = new node(value);
            if(_head == nullptr) {
                throw std::bad_alloc(); 
                _head=nullptr;
            }

            _size = 1;
            return;
        }
        
        node* prev = nullptr;
        node* current = _head;

        while(current != nullptr){

            if(_eq_comparator(current->_value, value)){
                current->_count++;
                ++_size;
                return;
            }

            if(_comparator(current->_value, value)){ // value < current->_value

                if(prev == nullptr){
                    node* new_node = new node(value);
                    if(new_node == nullptr) throw std::bad_alloc();
                    new_node->_next = current;
                    _head = new_node;
                    ++_size;
                    return;

                }else{
                    node* new_node = new node(value);
                    if(new_node == nullptr) throw std::bad_alloc();
                    new_node->_next = current;
                    prev->_next = new_node;
                    ++_size;
                    return;
                }

            }else{  // value > current->_value
            
                if(current->_next == nullptr){
                    current->_next = new node(value);
                    if(current->_next == nullptr) throw std::bad_alloc();
                    ++_size;
                    return;
                }
                prev = current;
                current = current->_next;
            }

        }

        LOG("add called with value: " << value);
    }

    void print(void) const{
        node* tmp = _head;
        std::cout << "Multiset size: " << _size << std::endl;
        while(tmp != nullptr){
            std::cout << '<' << tmp->_value << ',' << tmp->_count << '>' << std::endl;
            tmp = tmp->_next;
        }
    }



    ~Multiset(){
        node* tmp = _head;
        while(tmp != nullptr){
            node* next = tmp->_next;
            delete tmp;
            tmp = next;
        }
        LOG("Multiset destroyed");
    }
};

#endif