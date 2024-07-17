/**
 * @file albero.h
 * @author Yehan Sanjula Edirisinghe Mudiyanselage (y.edirisinghemudi@campus.unimib.it)
 * @brief file for binary three ```albero``` class
 * @version 0.1
 * @date 17-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef ALB_LIB_H
#define ALB_LIB_H

#ifndef NDEBUG
#define LOG(X) std::cout << X << std::endl
#elif
#define LOG(X)
#endif

#include <iostream>
#include <cassert>
#include <iterator>
#include <cstddef>

/**
 * @brief Class for rappresenting a binary three
 * @tparam T type of data to be stored
 * @tparam Comparator for <,>,= operations between two data members
 */
template <typename T, typename Comparator>
class albero
{
public:
    /// @brief type for values contained
    typedef T                 value_type;
    
    /// @brief type for three size
    typedef unsigned long int size_type;

private:
    /// @brief number of elements contained in the three
    size_type _size;

    /// @brief functor object for comparing values
    Comparator _comp_func;

    /**
     * @brief struct for single node in the three
     * 
     * @note It is not possible to create a node outside the class and it is not possible to create an empty node
     */
    struct node{

        value_type _value;
        node*      _left;
        node*      _right;
        
        /**
         * @brief Default empty constructor not permitted for safety reasons
         * 
         */
        node() = delete;

        /**
         * @brief Construct a new node object from one value
         * 
         * @param value data to sotore in one node
         */
        explicit node(const value_type& value) : _value(value){
            _left = nullptr;
            _right = nullptr;
            #ifndef NDEBUG
            std::cerr << "node(const value_type& value)" << std::endl;
            #endif
        }
        
        /**
         * @brief Destroy the node object
         * 
         * @note when this node is destroyed, all the nodes connected will be deleted with it
         * 
         */
        ~node(){
            
            if(_left != nullptr){
                delete _left;
                _left = nullptr;
            }
            if(_right != nullptr){
                delete _right;
                _right = nullptr;
            }
            _left = nullptr;
            _right = nullptr;

            #ifndef NDEBUG
            std::cerr << "~node()" << std::endl;
            #endif
        }
    };

    /// @brief first node of the three
    node* _root;

public:   
    /**
     * @brief ```default constructor not permitted```
     * @note To create a new object at least one data element must be given
     * @note to see permitted constructors see the documentation
     */
    albero() = delete;

    /**
     * @brief constructor given one data element
     * 
     * @param value data to be inserted as first node
     */
    explicit albero(const value_type& value) : _size(0), _root(nullptr) {
        #ifndef NDEBUG
        std::cerr << "albero(const value_type& value)" << std::endl;
        #endif

        try{
            _root = new node(value);
            ++_size;
        }catch(...){
            _root = nullptr;
            _size = 0;
            throw;
        }
    }

    /**
     * @brief Construct a new albero object by giving two sets of iterators
     * 
     * @tparam Iter Iterator type
     * @param begin starting iterator
     * @param end ending iterator
     * 
     * @note The responsibility of giving valid iterators is left to the user
     */
    template <typename Iter>
    albero(const Iter begin, const Iter end) : _size(0), _root(nullptr) {

        Iter tmp = begin;

        while(tmp != end){
            add(static_cast<value_type>(*tmp));
            tmp++;
        }
    }

    /**
     * @brief this function adds one data element to the structure
     * 
     * @param val reference to one data element
     */
    void add(const value_type& val) {

        node* tmp = _root;
        node* new_node = new node(static_cast<value_type>(val));
        
        //if allocation did not succeed an exception is thrown as bad_alloc
        if(new_node == nullptr){
            delete new_node;
            throw std::bad_alloc();
            return;
        }

        //if this is the first element:
        if(tmp == nullptr){
            _root = new_node;
            _size = 1;
            return;
        }


        while(true){

            if( _comp_func(val, tmp->_value) ){
                if(tmp->_left != nullptr){
                    tmp = tmp->_left;
                    continue;
                }else{
                    tmp->_left = new_node;
                    ++_size;
                    return;
                }
            }else{

                if(tmp->_right != nullptr){
                    tmp = tmp->_right;
                    continue;
                }else{
                    tmp->_right = new_node;
                    ++_size;
                    return;
                }
            }
        }
    };

private:

    /**
     * @brief recursive function for printing all the data elements in order
     * 
     * @note this function sends the stream to specific stream object NOT cout
     * 
     * @param os ostream object reference
     * @param n starting node for recursion
     */
    void print(std::ostream& os,const node* n) const{

        //exit condition for recursion
        if(n->_left != nullptr) print(os, n->_left);

        //_value is supposed to be allways accessible
        //if the first is not null 
        os << n->_value;
        os << " ";
        
        if(n->_right != nullptr) print(os, n->_right);
    }
    
    /**
     * @brief recursive function for finding one data element's existance in the structure
     * 
     * @param n starting node for recursion
     * @param value data that is to search
     * @return true the element is present
     * @return false the element is ```not``` present
     * 
     */
    bool find(node* n,const value_type& value) const{

        //exit conditions for recursion
        if(n == nullptr) return false;
        if(n->_value == value) return true;
        
        bool left = false, right = false;

        if(n->_left != nullptr) left = find(n->_left, value);
        if(n->_right != nullptr) right = find(n->_right, value);

        if(left == true || right == true) return true;
        return false;
    }

    /**
     * @brief recursive function for finding one data element's node pointer in the structure
     * 
     * @note this function works only if the element is actually present in the structure.
     * Thus the user must firt ensure that the element is present with find(value) method
     * 
     * @param n starting node for recursion
     * @param value data that is to search
     * @return node* pointer to the node that contains the data element
     */
    node* find_p(node* n, const value_type& value) const{

        if(n->_value == value) return n;

        node* left = nullptr;
        node* right = nullptr;

        if(n->_left != nullptr)  left = find_p(n->_left, value);
        if(left != nullptr) return left;
        if(n->_right != nullptr) right = find_p(n->_right, value);
        if(right != nullptr) return right;

        return nullptr;
    }

    /**
     * @brief this function adds one element to external albero object
     * 
     * @param a pointer to other albero object
     * @param start first node (_root) of the external object
     *
     * @note this function doesn't modify the current object if not passed as param
     */
    void add_to(albero* a, node* start){

        a->add(start->_value);

        if(start->_left != nullptr) add_to(a, start->_left);
        if(start->_right != nullptr) add_to(a, start->_right);
    }

public:
    /**
     * @brief print function for serializing the data in the structure
     * 
     * @note it is possible to stream the content to a ostream object with <<.
     * 
     */
    void print(void) const{
        std::cout << "Binary three of size: " << _size << std::endl;
        std::cout << "[ ";
        print(std::cout, _root);
        std::cout << "]" << std::endl;
    }

    /**
     * @brief this function gives the number of data elements contained in the structure
     * 
     * @return const size_type 
     */
    const size_type size(void)const {
        return _size;
    }

    /**
     * @brief this function find the existance of one data element in the structure
     * 
     * @param value value to be searched
     * @return ```true``` the value is present 
     * @return ```false``` the value is not present
     */
    bool find(const value_type& value) const{
        return find(_root, value);
    }

    /**
     * @brief this function creates a new albero instance from one data element
     * 
     * @attention The ownership of the new object pointer is given to the user
     * 
     * @param value starting value for branching
     * 
     * @return albero* pointer to the new object
     */
    albero* subthree(const value_type& value){
        assert(find(value) == true);

        node* n_value = find_p(_root, value);

        albero* new_albero =  new albero(value);
        
        if(n_value->_left != nullptr)   add_to(new_albero, n_value->_left);
        if(n_value->_right != nullptr)  add_to(new_albero, n_value->_right);

        return new_albero;
    }

    /**
     * @brief serialization of the data in the order defined by input comparator
     * @param os stream object to receive the stream
     * @param alb binary three object to serialize
     * @return returns the stream object
     * 
     * @example
     * std::cout << my_albero << std::endl;
     */
    friend std::ostream& operator<<(std::ostream& os, const albero& alb){
        os << "[ ";
        if(alb._root != nullptr) alb.print(os, alb._root);
        return os << "]";
    }

    /**
     * @brief Destroy the albero object
     * 
     * @attention if subthree() methos was used this is not automatically called!
     * The user must manually delete.
     * 
     */
    ~albero() {
        #ifndef DEBUG
        std::cerr << "~albero()" << std::endl;
        #endif

        if(_root != nullptr){
            delete _root;
            _root = nullptr;
        }
    };

    /**
     * @brief Read only iterator for the albero object
     * 
     */
    class const_iterator {

	public:

		typedef std::forward_iterator_tag iterator_category;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer;
		typedef const T&                  reference;

        /**
         * @brief Construct a new const NULL iterator object
         * 
         * @note this element does not contain any data
         * 
         */
		const_iterator() : ptr(nullptr){}
		
		const_iterator(const const_iterator &other) : ptr(other.ptr){}

		const_iterator& operator=(const const_iterator &other) {
			ptr = other.ptr;
            return *this;
		}

		~const_iterator() {
            LOG("~const_iterator()");
        }

		value_type operator*() const {
			return ptr->_value;
		}

		value_type* operator->() const {
			return &(ptr->_value);
		}
		
		const_iterator& operator++(int) {
			ptr = ptr->_right;
            return *this;
		}

		const_iterator& operator++() {
			ptr = ptr->_left;
            return *this;
		}

		bool operator==(const const_iterator &other) const {
			return (ptr == other.ptr);
		}
		
		bool operator!=(const const_iterator &other) const {
            return !(ptr == other.ptr);
		}

	private:

		friend class albero;

        /// @brief pointer to the data node in the class structure
        node* ptr;
        
		const_iterator(node* p) : ptr(p) { }

	};

    /**
     * @brief this function returns the iterator for the first element of the binary three
     * 
     * @return const_iterator 
     */
	const_iterator begin() const {
		return const_iterator(_root);
	}

    /**
     * @brief this function returns an end iterator for the binary three
     * 
     * @note the binary three does not have only one end
     * 
     * @return const_iterator 
     */
	const_iterator end() const {
		return const_iterator(nullptr);
	}
};


/**
 * @brief this function prints only the data elements that satisty the P functor
 * 
 * @note see documentation for functor description
 * 
 * @tparam T type of data
 * @tparam Comp comparator
 * @tparam P condition for printing
 * @param a albero obj to scan for printing
 */
template <typename T, typename Comp, typename P>
void printIF(albero<T,Comp>& a){
    P pred;
    typename albero<T,Comp>::const_iterator b(a.begin()),e(a.end()), tmp1(a.begin()), tmp2(a.begin());

    if(pred(static_cast<T>(*b))){
        std::cout << *b << " ";
    }

    if(tmp1++ != e){
        albero<T,Comp>* tmp = a.subthree(*tmp1);
        printIF<T,Comp,P>(*tmp);
        delete tmp;
    }

    if(++tmp2 != e){
        albero<T,Comp>* tmp = a.subthree(*tmp2);
        printIF<T,Comp,P>(*tmp);
        delete tmp;
    }
}

#endif