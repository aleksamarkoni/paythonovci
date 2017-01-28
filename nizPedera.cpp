#ifndef _PEDERI_CPP_

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "nizPedera.h"

using namespace std;

int konstruktorNizaRandom(int *i) {
  *i = (rand() % 20) + 0;
  return *i;
}

bool sortiraj(const SaVezom & s1, const SaVezom & s2) {
   if (s1.getEvrici() != s2.getEvrici())
   return s1.getEvrici() > s2.getEvrici();
}

void upisPederaSaVezom(int *i, vector <SaVezom>& Veza) {
  for (int k = 0; k < *i; k++) {
    Veza.push_back(SaVezom());
    //cout << Veza[k].getEvrici() << endl;
  }

}

void printNizova(int *i, vector <SaVezom> &Veza) {
  for (int k; k < *i; k++){
    cout << Veza[k].getEvrici() << endl;
  }
}
#endif
