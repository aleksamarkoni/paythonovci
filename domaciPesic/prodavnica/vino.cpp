#include "vino.h"

using namespace std;


Vino::Vino(string a1, string b1, string c1, string d1) : Pice(a1, b1, c1) {
  vrsta = a1;
  ime = b1;
  poreklo = c1;
  proizvodjac = d1;
}

string Vino::getVrstaVina() {
  return vrsta;
}

string Vino::getImeVina() {
  return ime;
}

string Vino::getPorekloVina() {
  return poreklo;
}

string Vino::getProizvodjac() {
  return proizvodjac;
}
