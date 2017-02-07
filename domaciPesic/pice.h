#ifndef PICE_H
#define PICE_H
#include <string>

class Pice {
  protected:
    std::string vrsta;
    std::string ime;
    std::string poreklo;
  public:
    Pice(std::string, std::string, std::string);
    std::string getVrsta();
    std::string getIme();
    std::string getPoreklo();
};
#endif
