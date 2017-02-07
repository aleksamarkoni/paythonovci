#ifndef VINO_H
#define VINO_H
#include <string>
#include "pice.h"

class Vino:protected Pice {
  private:
    std::string proizvodjac;
  public:
    Vino(std::string, std::string, std::string, std::string);
    std::string getVrstaVina();
    std::string getImeVina();
    std::string getPorekloVina();
    std::string getProizvodjac();
};
#endif
