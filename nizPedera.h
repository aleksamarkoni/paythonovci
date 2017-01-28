#ifndef _PEDERI_H_

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class SaVezom {
private:
  int evrici;
public:
  SaVezom() {
    evrici = (rand() % 10000) + 0;
  }
  ~SaVezom() {}

  int getEvrici() const {
    return this->evrici;
  }

  bool sortiraj(const SaVezom & s1, const SaVezom & s2);

  ostream& operator<<(ostream& out) {
    vector <SaVezom> Veza;
    int i,k;
    for (k = 0; k < i; k++) {
      out << Veza[k].getEvrici() << endl;
      return out;
    }
  }
};


#endif
