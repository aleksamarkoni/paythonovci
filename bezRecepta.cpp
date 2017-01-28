#ifndef _PEDERI_CPP_

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "bezRecepta.h"

using namespace std;

bool sortirajBezRecepte(const BezRecepta & s1, const BezRecepta & s2) {
   if (s1.getRecepti() != s2.getRecepti())
   return s1.getRecepti() > s2.getRecepti();
}

void upisPederaSaVezom(int *i, vector <BezRecepta>& bezRecepta) {
  for (int k = 0; k < *i; k++) {
    bezRecepta.push_back(BezRecepta());
    //cout << Veza[k].getEvrici() << endl;
  }

}

void printNizova(int *i, vector <BezRecepta> &bezRecepta) {
  for (int k; k < *i; k++){
    cout << "Ovaj slepac ima: " << bezRecepta[k].getRecepti() << " pogresnih recepta." << endl;
  }
}
#endif
