#include "pub.h"

using namespace std;


Pub::Pub(string a1, string b1, string c1, string d1, string e1) : Lokal(a1, b1, c1) {
  vrsta = a1;
  ime = b1;
  adresa = c1;
  bend = d1;
  promocija = e1;
}

string Pub::getVrstaPuba() {
  return vrsta;
}

string Pub::getImePuba() {
  return ime;
}

string Pub::getAdresaPuba() {
  return adresa;
}

string Pub::getBend() {
  return bend;
}

string Pub::getPromocija() {
  return promocija;
}
