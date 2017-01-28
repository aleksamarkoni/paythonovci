#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "nizPedera.cpp"

using namespace std;

int main() {
  srand(time(NULL));
  int i;
  SaVezom a;
  konstruktorNizaRandom(&i);
  vector <SaVezom> Veza;
  Veza.reserve(i);
  upisPederaSaVezom(&i, Veza);
  sort(Veza.begin(), Veza.end(), sortiraj);
  printNizova(&i, Veza);

}
