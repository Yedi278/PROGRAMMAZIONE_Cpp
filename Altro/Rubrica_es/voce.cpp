#include "voce.h"


std::ostream& operator<<(std::ostream&os, const voce& v){
  os << "<" << v._nome << " " << v._cognome << " " << v._telefono << ">";
  return os;
}