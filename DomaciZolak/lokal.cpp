#include "lokal.h"

using namespace std;

Lokal::Lokal(string a, string b, string c) {
  vrsta = a;
  ime = b;
  adresa = c;
}

string Lokal::getVrsta() {
  return vrsta;
}

string Lokal::getIme() {
  return ime;
}

string Lokal::getAdresa() {
  return adresa;
}

//void Lokal::cenovnik() {

//}
