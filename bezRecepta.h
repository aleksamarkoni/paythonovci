#ifndef _PEDERI_H_

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class BezRecepta {
private:
  int recept;
public:
  BezRecepta() {
    recept = (rand() % 5) + 1;
  }
  ~BezRecepta() {}

  int getRecepti() const {
    return this->recept;
  }

  bool sortiraj(const BezRecepta & s1, const BezRecepta & s2);

  ostream& operator<<(ostream& out) {
    vector <BezRecepta> bezRecepta;
    int i,k;
    for (k = 0; k < i; k++) {
      out << bezRecepta[k].getRecepti() << endl;
      return out;
    }
  }
};


#endif
