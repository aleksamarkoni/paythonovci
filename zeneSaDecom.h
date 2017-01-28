#ifndef _PEDERI_H_

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class ZeneSaDecom {
private:
  int deca;
public:
  ZeneSaDecom() {
    deca = (rand() % 9) + 1;
  }
  ~ZeneSaDecom() {}

  int getDeca() const {
    return this->deca;
  }

  bool sortiraj(const ZeneSaDecom & s1, const ZeneSaDecom & s2);

  ostream& operator<<(ostream& out) {
    vector <ZeneSaDecom> brDece;
    int i,k;
    for (k = 0; k < i; k++) {
      out << brDece[k].getDeca() << endl;
      return out;
    }
  }
};


#endif
