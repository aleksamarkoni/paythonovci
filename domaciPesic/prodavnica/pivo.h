#ifndef PIVO_H
#define PIVO_H
#include <string>
#include "pice.h"

class Pivo: protected Pice {
  private:
    std::string tip;
  public:
    Pivo(std::string, std::string, std::string, std::string);
    std::string getVrstaPiva();
    std::string getImePiva();
    std::string getPorekloPiva();
    std::string getTip();
};
#endif
