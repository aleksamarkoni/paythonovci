#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "nizPedera.cpp"
#include "trudnice.cpp"
#include "zeneSaDecom.cpp"
#include "Penzioneri.cpp"

using namespace std;

int konstruktorNizaRandom(int *i) {
  *i = (rand() % 20) + 0;
  return *i;
}

int main() {
  srand(time(NULL));
  int i;
  konstruktorNizaRandom(&i);
  vector <SaVezom> Veza;
  Veza.reserve(i);
  upisPederaSaVezom(&i, Veza);
  sort(Veza.begin(), Veza.end(), sortirajEvrice);
  printNizova(&i, Veza);


  vector <Trudnice> brBeba;
  brBeba.reserve(i);
  upisPederaSaVezom(&i, brBeba);
  sort(brBeba.begin(), brBeba.end(), sortirajBebe);
  printNizova(&i, brBeba);

  vector <ZeneSaDecom> brDece;
  brDece.reserve(i);
  upisPederaSaVezom(&i, brDece);
  sort(brDece.begin(), brDece.end(), sortirajDecu);
  printNizova(&i, brDece);

  vector <Penzioneri> Penzija;
  Penzija.reserve(i);
  upisPederaSaVezom(&i, Penzija);
  sort(Penzija.begin(), Penzija.end(), sortirajPenziju);
  printNizova(&i, Penzija);
}
