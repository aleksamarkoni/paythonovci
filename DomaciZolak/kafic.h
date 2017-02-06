#ifndef KAFIC_H
#define KAFIC_H
#include <string>
#include "lokal.h"

class Kafic: protected Lokal {
  private:
    std::string akcija;
  public:
    Kafic(std::string, std::string, std::string, std::string);
    std::string getVrstaKafica();
    std::string getImeKafica();
    std::string getAdresaKafica();
    std::string getAkcija();
};
#endif
