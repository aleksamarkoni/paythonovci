#ifndef _PEDERI_H_

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class SaReceptom {
private:
  int recept;
public:
  SaReceptom() {
    recept = (rand() % 5) + 1;
  }
  ~SaReceptom() {}

  int getRecept() const {
    return this->recept;
  }

  bool sortirajRecepte(const SaReceptom & s1, const SaReceptom & s2);

  ostream& operator<<(ostream& out) {
    vector <SaReceptom> Recept;
    int i,k;
    for (k = 0; k < i; k++) {
      out << Recept[k].getRecept() << endl;
      return out;
    }
  }
};


#endif
