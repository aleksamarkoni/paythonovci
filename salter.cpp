#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "nizPedera.cpp"
#include "trudnice.cpp"

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
}
