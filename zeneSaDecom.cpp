#ifndef _PEDERI_CPP_

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "zeneSaDecom.h"

using namespace std;

bool sortirajDecu(const ZeneSaDecom & s1, const ZeneSaDecom & s2) {
   if (s1.getDeca() != s2.getDeca())
   return s1.getDeca() > s2.getDeca();
}

void upisPederaSaVezom(int *i, vector <ZeneSaDecom>& brDece) {
  for (int k = 0; k < *i; k++) {
    brDece.push_back(ZeneSaDecom());
    //cout << Veza[k].getEvrici() << endl;
  }

}

void printNizova(int *i, vector <ZeneSaDecom> &brDece) {
  for (int k; k < *i; k++){
    cout << "Ova kurva ima: " << brDece[k].getDeca() << " Jugovica." << endl;
  }
}
#endif
