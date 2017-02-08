#ifndef PUB_H
#define PUB_H
#include <string>
#include "lokal.h"

class Pub: protected Lokal {
  private:
    std::string bend;
    std::string promocija;
  public:
    Pub(std::string, std::string, std::string, std::string, std::string);
    std::string getVrstaPuba();
    std::string getImePuba();
    std::string getAdresaPuba();
    std::string getBend();
    std::string getPromocija();
};
#endif
