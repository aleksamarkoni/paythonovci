#ifndef LOKAL_H
#define LOKAL_H
#include <string>

using namespace std;

class Lokal {
  protected:
    string vrsta;
    string ime;
    string adresa;
  public:
    Lokal(string, string, string);
    string getVrsta();
    string getIme();
    string getAdresa();
    //void cenovnik();
};
#endif
