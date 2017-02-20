#ifndef KONACNAZARADA_H
#define KONACNAZARADA_H
#include <vector>
//#include "lokal.h"
#include "konobari.h"
//#include "pice.h"
//#include "hrana.h"
//#include "muzika.h"

using namespace std;

class Kolektiv {
private:
  vector <Konobar> Konobari;
  //vector <Pice> Pice;
  //vector <Hrana> Hrana;
  //vector <Muzika> Muzika;
public:
  Kolektiv();
  //void generisiKonobare(Lokal &pivnica);
  friend ostream& operator<<(ostream &out, Kolektiv &kolektiv);
};

#endif
