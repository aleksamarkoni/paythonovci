#ifndef _PEDERI_CPP_

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "saReceptom.h"

using namespace std;

bool sortirajRecepte(const SaReceptom & s1, const SaReceptom & s2) {
   if (s1.getRecept() != s2.getRecept())
   return s1.getRecept() > s2.getRecept();
}

void upisSaReceptom(int *i, vector <SaReceptom>& Recept) {
  for (int k = 0; k < *i; k++) {
    Recept.push_back(SaReceptom());
    //cout << Veza[k].getEvrici() << endl;
  }

}

void printNizova(int *i, vector <SaReceptom> &Recept) {
  cout << "SA RECEPTOM:" << endl;
  for (int k; k < *i; k++){
    cout << "Ovaj bolesnik ima: " << Recept[k].getRecept() << " recepata." << endl;
  }
}
#endif
