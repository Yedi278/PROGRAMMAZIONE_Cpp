namespace dnb{

    struct dynamic_buffer{
        unsigned int size = 0;
        int* buffer = 0;
    };

    /**
     * @brief Stampa tutti gli elementi dell'array
     * 
     * @param d 
     */
    void stampa(dynamic_buffer d);

    /**
     * @brief Pone tutti gli elementi del buffer dinamico a 0
     * 
     * @param d indirizzo di memoria del buffer dinamico
     */
    void init(dynamic_buffer* d);

    /**
     * @brief alloca gli elementi del buffer dinamico
     * 
     * @param d 
     * @return true 
     * @return false 
     */
    bool alloc(dynamic_buffer* d, int size=10);

    void dealloc(dynamic_buffer* d);

    void insert(dynamic_buffer* d,unsigned int index, int data);

    void copy(dynamic_buffer d, dynamic_buffer* d2);
    
}

