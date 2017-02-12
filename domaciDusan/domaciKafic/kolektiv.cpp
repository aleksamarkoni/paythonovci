#include "lokal.h"

using namespace std;
/*
ostream& operator<<(ostream &out, Kolektiv &kolektiv) {
  for(int k = 0; k < konobari.size(); k++) {
    out << konobari[k] << endl;
  }
}
*/
Lokal::Kolektiv::Kolektiv() {}

void Lokal::Kolektiv::generisiKonobare(Lokal &pivnica) {
  for(int k = 0; k < (pivnica.ukupanBrojGostiju(pivnica) / 30); k++) {
    konobari.push_back(Konobar());
  }
  if((pivnica.ukupanBrojGostiju(pivnica) % 30) > 10 ){
    konobari.push_back(Konobar());
  }
}

void Lokal::Kolektiv::ispisKonobara(Lokal &pivnica) {
  for(int k = 0; k < konobari.size(); k++) {
    cout << k+1 << "." << " konobar je zaradio " << konobari[k] << endl;
  }
}
