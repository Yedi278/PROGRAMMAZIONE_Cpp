#ifndef RUBRICA_H
#define RUBRICA_H

#include "voce.h"
#include <cassert>
#include <fstream>

class Rubrica
{
public:
  typedef unsigned long int size_type;
private:
  size_type _size;
  voce* _voci;

public:

  Rubrica() : _size(0), _voci(nullptr) {}
  Rubrica(size_type size);
  
  const voce& operator[](size_type i) const;
  voce& operator[](size_type i);
  
  bool add(const voce& v);
  bool add(std::string nome, std::string cognome, std::string telefono){
    return add(voce(nome, cognome, telefono));
  }

  bool find_b(std::string telefono) const;
  voce* find(std::string telefono);

  size_type size() const{
    return _size;
  }

  size_type available() const{
    voce empty;
    size_type i,count=0;
    for(i=0; i < _size; ++i){
      if(_voci[i] == empty)
        ++count;
    }
    return count;
  }

  void set_capacity(size_type size, bool copy = false);
  
  void save() const;


  ~Rubrica() {
    delete[] _voci;
    _voci = nullptr;
    _size = 0;
  }


  friend std::ostream& operator<<(std::ostream& os, const Rubrica& r);
};

#endif // RUBRICA_H