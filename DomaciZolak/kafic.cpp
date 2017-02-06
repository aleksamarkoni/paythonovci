#include "kafic.h"
#include <iostream>
using namespace std;

Kafic::Kafic(string a, string b, string c) {
  vrsta = a;
  ime = b;
  adresa = c;
}

void Kafic::akcija(string a) {
  cout << "Trenutna promocija u kaficu: " << kafic1.getIme(); << "je : " << a << endl;
}
