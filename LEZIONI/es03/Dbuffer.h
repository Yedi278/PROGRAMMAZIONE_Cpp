#ifndef DBUFFER_H
#define DBUFFER_H

#include <ostream>

class dbuffer{

private:
    unsigned int _size;
    int* _buffer;

public:

    dbuffer();
    dbuffer(unsigned int size);
    dbuffer(unsigned int size, int value);

    ~dbuffer();

    dbuffer(const dbuffer &buffer);
    dbuffer& operator=(const dbuffer &other);

    int& value(unsigned int index);

    int& operator[](unsigned int index);
    const int& operator[](unsigned int index) const;
    
    dbuffer& operator++();      // ++c
    dbuffer operator++(int);    // c++

    unsigned int get_size() const;

    void print()const;

    friend std::ostream &operator<<(std::ostream &os, const dbuffer &db);

protected:
    //accessibile alle classe figlie
};

std::ostream &operator<<(std::ostream &os, const dbuffer &db);

#endif