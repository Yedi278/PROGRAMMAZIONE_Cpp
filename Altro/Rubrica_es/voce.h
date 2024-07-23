#ifndef VOCE_H
#define VOCE_H

#include <string>
#include <iostream>

struct voce{
  std::string _nome;
  std::string _cognome;
  std::string _telefono;

  voce(std::string nome, std::string cognome, std::string telefono) : _nome(nome), _cognome(cognome), _telefono(telefono) {}
  voce() : _nome(" "), _cognome(" "), _telefono(" ") {}
  voce(const voce& v) : _nome(v._nome), _cognome(v._cognome), _telefono(v._telefono) {}

  bool operator==(const voce& v) const{
    return _nome == v._nome && _cognome == v._cognome && _telefono == v._telefono;
  }

  bool operator!=(const voce& v) const{
    return _nome != v._nome || _cognome != v._cognome || _telefono != v._telefono;
  }

  voce& operator=(const voce& v){
    if(this != &v){
      _nome = v._nome;
      _cognome = v._cognome;
      _telefono = v._telefono;
    }
    return *this;
  }

  friend std::ostream& operator<<(std::ostream&os, const voce& v);

  ~voce() {}
};



#endif // VOCE_H