#include "rubrica.h"


Rubrica::Rubrica(size_type size) : _size(size), _voci(nullptr) {
  assert(size > 0);
  _voci = new voce[_size];

  if(_voci == nullptr){
    _size = 0;
    _voci = nullptr;

    throw std::bad_alloc();
    return;
  }
}

const voce& Rubrica::operator[](size_type i) const{
  assert(_size > 0); //not correctly initialized
  assert(i < _size); //out of bounds

  return _voci[i];
}

voce& Rubrica::operator[](size_type i){
  assert(_size > 0); //not correctly initialized
  assert(i < _size); //out of bounds

  return _voci[i];
}

void Rubrica::set_capacity(size_type size, bool copy){
  if(size == _size)
    return;

  voce* new_voci = new voce[size];
  if(new_voci == nullptr){
    throw std::bad_alloc();
    return;
  }

  if(_size < size && !copy){
    for(size_type i = 0; i < std::min(size,_size); ++i){
      new_voci[i] = _voci[i];
    }
  }

  delete[] _voci;
  _size = size;
  _voci = new_voci;
}

bool Rubrica::add(const voce& v){
  size_type i;
  voce empty;
  for(i=0; i < _size; ++i){
    if(_voci[i] == empty){
      _voci[i] = v;
      return true;
    }
  }
  return false;
}

bool Rubrica::find_b(std::string telefono) const{
  assert(_size > 0); //not correctly initialized
  
  for(size_type i = 0; i < _size; ++i){
    if(_voci[i]._telefono == telefono)
      return true;
  }
  return false;
}

voce* Rubrica::find(std::string telefono){
  assert(_size > 0); //not correctly initialized
  
  if(!find_b(telefono)){
    return nullptr;
  }
  for(size_type i = 0; i < _size; ++i){
    if(_voci[i]._telefono == telefono)
      return &_voci[i];
  }
}

void Rubrica::save() const{
  std::ofstream file("build/rubrica.txt", std::ofstream::out);
  if(file.is_open()){
    for(size_type i=0; i<_size; ++i){
      file << _voci[i] << std::endl;
    }
    file.close();
    return;
  }else{
    throw std::runtime_error("Unable to open file");
    return;
  }
}

std::ostream& operator<<(std::ostream& os, const Rubrica& r){

  voce empty;
  for(Rubrica::size_type i = 0; i < r._size; ++i){
    if(r[i] != empty)
      os << "index: " << i << " " << r._voci[i] << std::endl;
  }

  return os;
}