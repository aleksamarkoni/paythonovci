#ifndef KAFIC_H
#define KAFIC_H
#include <string>
#include "lokal.h"

using namespace std;

class Kafic: protected Lokal {
  public:
    Kafic(string, string, string);
    string getVrstaKafica();
    string getImeKafica();
    string getAdresaKafica();
    //void akcija(string a);
};
#endif
