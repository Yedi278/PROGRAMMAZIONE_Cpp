#ifndef SPARSE_MAT_HPP
#define SPARSE_MAT_HPP

/// @brief macro for debug mode (print logs)
#ifndef NDEBUG
#define LOG(X) std::cout << X << std::endl
#define LOGRED(X) std::cout << "\033[1;31m" << X << "\033[0m" << std::endl
#define LOGGREEN(X) std::cout << "\033[1;32m" << X << "\033[0m" << std::endl
#define LOGBLUE(X) std::cout << "\033[1;34m" << X << "\033[0m" << std::endl
#else
#define LOG(X)
#define LOGRED(X)
#define LOGGREEN(X)
#define LOGBLUE(X)
#endif

#include <iostream>
#include <cassert>

#include <iterator> // std::forward_iterator_tag
#include <cstddef>  // std::ptrdiff_t

/**
 * @brief class for representing a sparse matrix
 * 
 * @tparam T type of data to be stored
 */
template <typename T>
class SparseMatrix
{
public:

    /// @brief type for values contained
    typedef unsigned long int size_type;
    /// @brief type for size of the matrix
    typedef T                 value_type;

private:

    /// @brief number of rows in the matrix
    size_type _n;
    /// @brief number of columns in the matrix
    size_type _m;
    /// @brief default value for the matrix
    value_type _D;

    /**
     * @brief single node for the sparse matrix' dynamic list
     * 
     */
    struct node{
        /// @brief x (or i) coordinate
        size_type _x;
        /// @brief y (or j) coordinate
        size_type _y;
        /// @brief value stored in the node
        T _value;
        /// @brief pointer to the next node
        node* _next;

        /**
         * @brief Construct a new node object
         * 
         * @param x x coordinate
         * @param y y coordinate
         * @param value value to store
         */
        explicit node(size_type x, size_type y, T value): _x(x), _y(y), _value(value), _next(nullptr){
            LOG("node(size_type x, size_type y, T value)");
        };

        /**
         * @brief Destroy the node object (empty by design)
         * 
         */
        ~node(){
            LOG("~node()");
        };
    };

    /// @brief pointer to the first node of the dynamic list
    node* _head;

public:
    
    /// @brief ```default constructor not permitted```
    SparseMatrix() = delete;
    
    /**
     * @brief Construct a new Sparse Matrix object
     * 
     * @param n number of rows
     * @param m number of columns
     * @param D default value for the matrix
     */
    SparseMatrix(const size_type& n,const size_type& m, value_type D): _head(nullptr),_D(D){
        assert(n>0);    //amtrix size must be positive;
        assert(m>0);
        _n = n;
        _m = m;
        LOG("SparseMatrix(const size_type& n,const size_type& m, value_type D)");
    };

    /**
     * @brief Construct a new Sparse Matrix object by copying another one
     * 
     * @param mat matrix to copy
     */
    SparseMatrix(const SparseMatrix& mat): _n(mat._n), _m(mat._m), _D(mat._D), _head(nullptr){
        assert(&mat != this);

        node* tmp = mat._head;
        while (tmp != nullptr){
            this->set(tmp->_value, tmp->_x, tmp->_y);
            tmp = tmp->_next;
        }

        LOG("SparseMatrix(const SparseMatrix& mat)");
    }

    /**
     * @brief Print the matrix info: size and default value
     * 
     */
    void printInfo() const{
        std::cout << "------------------" << std::endl;
        std::cout << "Size: " << _n << " x " << _m << std::endl;
        std::cout << "Default value D: " << _D << std::endl;
        std::cout << "------------------" << std::endl;
    }

    /**
     * @brief Print the matrix data (default value is not printed)
     * 
     */
    void printData() const{
        node* tmp = _head;
        std::cout << "Matrix Values: " << std::endl;
        while (tmp != nullptr){
            std::cout << tmp->_value << " : " << tmp->_x << ", " << tmp->_y << std::endl;
            tmp = tmp->_next;
        }
        std::cout << std::endl;
    }

    /**
     * @brief Get the row object
     * 
     * @return size_type number of rows
     */
    size_type get_row() const{ 
        return _n;
    }

    /**
     * @brief Get the col object
     * 
     * @return size_type number of columns
     */
    size_type get_col() const{
        return _m;
    }

    /**
     * @brief Get the D object
     * 
     * @return value_type default value
     */
    value_type get_D() const{
        return _D;
    }

    /**
     * @brief Set the value of the matrix at the given coordinates
     * 
     * @param value value to set
     * @param x x coordinate
     * @param y y coordinate
     * @return true if the value was set, false if an error occurred
     */
    bool set(const value_type& value, const size_type& x,const size_type& y){
        //check if coordinates are in the matrix
        assert(x < _n);
        assert(y < _m);

        if(_head == nullptr){
            if(value == _D) return true;
            try{
                _head = new node(x,y,value);
                return true;
            }catch(...){
                _head = nullptr;
                return false;
            }
        }

        node* tmp = _head;
        node* prev = _head;

        while(tmp != nullptr){
            
            if( tmp->_x == x && tmp->_y == y){
                if(value == _D){  // if value is default value remove old value from list
                    node* next = tmp->_next;

                    if(tmp == _head) {

                        try{ //check delete exceptions
                            delete _head;
                            _head = nullptr;
                            _head = next;
                            return true;

                        }catch(...){
                            return false;
                        }
                    }

                    try{ //check delete exceptions
                        delete tmp;
                        prev->_next = next;
                        return true;

                    }catch(...){
                        return false;
                    }
                }
                //otherwise change the value
                tmp->_value = value;
                return true;   
            }
            //go to next node
            prev = tmp;
            tmp = tmp->_next;
        }
        if( value == _D) return true;

        try{ // check new exceptions
            node* new_node = new node(x,y,value);
            prev->_next = new_node;
            return true;
        }catch(...){
            return false;
        }
    }

    /**
     * @brief Get the value of the matrix at the given coordinates
     * 
     * @param x x coordinate
     * @param y y coordinate
     * @return value_type value at the given coordinates
     */
    value_type operator()(const size_type& x, const size_type& y) const{
        node* tmp = _head;

        while(tmp != nullptr){

            if( tmp->_x == x && tmp->_y == y){
                return tmp->_value;
            }
            tmp = tmp->_next;
        }

        return _D;
    }

    /**
     * @brief Destroy the Sparse Matrix object
     * 
     */
    ~SparseMatrix(){
        node* tmp = _head;
        node* prev = _head;
        while(tmp!= nullptr){
            prev = tmp;
            tmp = tmp->_next;
            delete prev;
        }

        LOG("~SparseMatrix()");
    }

    /**
     * @brief element object for the iterator
     * 
     */
    struct element{
        size_type _i,_j;
        value_type _value;

        element(const size_type& i, const size_t& j, const value_type value) : _i(i), _j(j), _value(value) {}
        element(const element& e) : _i(e._i), _j(e._j), _value(e._value){}
    };
    
    /**
     * @brief const iterator for the sparse matrix (```only forward```)
     * 
     */
    class const_iterator {
	
	    public:
            typedef std::forward_iterator_tag iterator_category;
            typedef ptrdiff_t                 difference_type;
            typedef const T*                  pointer;
            typedef const T&                  reference;

        /**
         * @brief Construct a new const iterator object
         * 
         */
        const_iterator() : curr_ptr(nullptr){}

		/**
		 * @brief Copy constructor for iterator
		 * 
		 * @param other 
		 */
        const_iterator(const const_iterator &other) : curr_ptr(other.curr_ptr) {}
		
        /**
         * @brief Construct a new const iterator object from a sparse matrix
         * 
         * @param mat 
         */
        const_iterator(const SparseMatrix<T>& mat) : curr_ptr(mat._head) {}

        /**
         * @brief Assign iterator to another iterator
         * 
         * @param other 
         * @return const_iterator& 
         */
		const_iterator& operator=(const const_iterator &other) {
			curr_ptr = other.curr_ptr;
            return *this;
		}

        /**
         * @brief Destroy the const iterator object (empty by design)
         * 
         */
		~const_iterator() { }

        /**
         * @brief Get the element object
         * 
         * @return element (const object)
         */
		const element operator*() const {
            assert(curr_ptr != nullptr);

            element e(curr_ptr->_x, curr_ptr->_y, curr_ptr->_value);
			return e;
		}

        /**
         * @brief Get the pointer to value variable
         * 
         * @return const T* 
         */
		pointer operator->() const {
            assert(curr_ptr != nullptr);

            element e(curr_ptr->_x, curr_ptr->_y, curr_ptr->_value);
			return &curr_ptr->_value;
		}
		
        /**
         * @brief Post-increase
         * 
         * @param int 
         * @return const_iterator 
         */
		const_iterator operator++(int) {
			const_iterator tmp(*this);
            curr_ptr = curr_ptr->_next;
            return tmp;
		}

        /**
         * @brief Pre-increase
         * 
         * @return const_iterator& 
         */
		const_iterator& operator++() {
			curr_ptr = curr_ptr->_next;
            return *this;
		}

		/**
         * @brief Equal operator
         * 
         * @param other 
         * @return true 
         * @return false 
         */
		bool operator==(const const_iterator &other) const {
			return (curr_ptr == other.curr_ptr);
		}
		
        /**
         * @brief Not equal operator
         * 
         * @param other 
         * @return true 
         * @return false 
         */
		bool operator!=(const const_iterator &other) const {
			return ! (curr_ptr == other.curr_ptr);
		}

        private:
        /// @brief pointer to the current node
        node* curr_ptr;

		friend class SparseMatrix;

        /**
         * @brief Construct a new const iterator object from a node
         * 
         * @param n 
         */
		const_iterator(node* n) : curr_ptr(n){ }
        
	}; // class const_iterator
	
    /**
     * @brief Gives the first Iterator
     * 
     * @return const_iterator 
     */
	const_iterator begin() const {
		return const_iterator(_head);
	}
	
    /**
     * @brief Gives the end Iterator
     * 
     * @return const_iterator 
     */
	const_iterator end() const {
		return const_iterator(nullptr);
	}
};

/**
 * @brief function for evaluating the number of elements in the matrix that satisfy the predicate
 * 
 * @tparam T type of data
 * @tparam P predicate type
 * @param mat matrix to evaluate
 * @return typename SparseMatrix<T>::size_type number of elements that satisfy the predicate
 */
template <typename T, typename P>
typename SparseMatrix<T>::size_type evaluate(const SparseMatrix<T>& mat){
    P pred;
    typename SparseMatrix<T>::size_type counter = 0,n=0,m=0;
    typename SparseMatrix<T>::const_iterator it;

    if( !pred(mat.get_D()) ){
        for(it=mat.begin(); it!=mat.end(); it++){
            if(pred((*it)._value)){
                counter++;
            }
        }
    }else{
        n = mat.get_row();
        m = mat.get_col();
        for(typename SparseMatrix<T>::size_type i=0; i<n; i++){
            for(typename SparseMatrix<T>::size_type j=0; j<m; j++){
                if( pred(mat(i,j) )){
                    counter++;
                }
            }
        }
    }
    return counter;
}

#endif