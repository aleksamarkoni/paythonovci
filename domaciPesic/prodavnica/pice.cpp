#include "pice.h"

using namespace std;

Pice::Pice(string a, string b, string c) {
  vrsta = a;
  ime = b;
  poreklo = c;
}

string Pice::getVrsta() {
  return vrsta;
}

string Pice::getIme() {
  return ime;
}

string Pice::getPoreklo() {
  return poreklo;
}
