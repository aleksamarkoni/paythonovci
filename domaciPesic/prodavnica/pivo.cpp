#include "pivo.h"

using namespace std;

Pivo::Pivo(string a1, string b1, string c1, string d1) : Pice(a1, b1, c1) {
  vrsta = a1;
  ime = b1;
  poreklo = c1;
  tip = d1;
}

string Pivo::getVrstaPiva() {
  return vrsta;
}

string Pivo::getImePiva() {
  return ime;
}

string Pivo::getPorekloPiva() {
  return poreklo;
}

string Pivo::getTip() {
  return tip;
}
