#include "kafic.h"

using namespace std;


Kafic::Kafic(string a1, string b1, string c1) : Lokal(a1, b1, c1) {
  vrsta = a1;
  ime = b1;
  adresa = c1;
}

string Kafic::getVrstaKafica() {
  return vrsta;
}

string Kafic::getImeKafica() {
  return ime;
}

string Kafic::getAdresaKafica() {
  return adresa;
}

//void Kafic::akcija(string a) {
  //cout << "Trenutna promocija u kaficu: " << kafic1.getIme(); << "je : " << a << endl;
//}
