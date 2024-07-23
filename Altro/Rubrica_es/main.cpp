#include <iostream>
#include <string>
#include "rubrica.h"
#include "voce.h"

#define LOG(X) std::cout << X << std::endl

int main(){

  Rubrica r(3);

  r[1] = voce("Mario", "Rossi", "1234567890");
  r[0] = voce("Luca", "Bianchi", "0987654321");
  r[2] = voce("Giovanni", "Verdi", "6789012345");

  LOG(r);

  std::cout << "Size: " << r.size() << std::endl;
  std::cout << "Available: " << r.available() << std::endl;

  r.set_capacity(5);

  r[4] = voce("Paolo", "Neri", "5432167890");

  LOG(r);
  
  LOG("Found 5432167890 at voce: \n" << *r.find("5432167890"));

  r.save();
  
  return 0;
}