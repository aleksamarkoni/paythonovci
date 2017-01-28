#ifndef _PEDERI_H_

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Penzioneri {
private:
  int penzija;
public:
  Penzioneri() {
    penzija = (rand() % 30000) + 0;
  }
  ~Penzioneri() {}

  int getPenzija() const {
    return this->penzija;
  }

  bool sortirajPenziju(const Penzioneri & s1, const Penzioneri & s2);

  ostream& operator<<(ostream& out) {
    vector <Penzioneri> Penzija;
    int i,k;
    for (k = 0; k < i; k++) {
      out << Penzija[k].getPenzija() << endl;
      return out;
    }
  }
};


#endif
