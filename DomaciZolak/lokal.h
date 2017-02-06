#ifndef LOKAL_H
#define LOKAL_H
#include <string>

class Lokal {
  protected:
    std::string vrsta;
    std::string ime;
    std::string adresa;
  public:
    Lokal(std::string, std::string, std::string);
    std::string getVrsta();
    std::string getIme();
    std::string getAdresa();
};
#endif
