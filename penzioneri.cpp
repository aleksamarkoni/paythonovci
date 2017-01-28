#ifndef _PEDERI_CPP_

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "penzioneri.h"


using namespace std;

bool sortirajPenziju(const Penzioneri & s1, const Penzioneri & s2) {
   if (s1.getPenzija() != s2.getPenzija())
   return s1.getPenzija() > s2.getPenzija();
}

void upisPederaSaVezom(int *i, vector <Penzioneri>& Penzija) {
  for (int k = 0; k < *i; k++) {
    Penzija.push_back(Penzioneri());
    //cout << Veza[k].getEvrici() << endl;
  }

}

void printNizova(int *i, vector <Penzioneri> &Penzija) {
  for (int k; k < *i; k++){
    cout << "Ovaj matori/a ima: " << Penzija[k].getPenzija() << " novaca." << endl;
  }
}
#endif
