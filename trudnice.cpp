#ifndef _TRUDNICE_CPP_

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "trudnice.h"

using namespace std;

bool sortirajBebe(const Trudnice & s1, const Trudnice & s2) {
   if (s1.getBeba() != s2.getBeba())
   return s1.getBeba() > s2.getBeba();
}

void upisTrudnica(int *i, vector <Trudnice>& brBeba) {
  for (int k = 0; k < *i; k++) {
    brBeba.push_back(Trudnice());
    //cout << Veza[k].getEvrici() << endl;
  }

}

void printNizova(int *i, vector <Trudnice> &brBeba) {
  cout << "TRUDNICE:" << endl;
  for (int k; k < *i; k++){
    cout << "Ova kurva nosi: " << brBeba[k].getBeba() << " beba." << endl;
  }
}
#endif
