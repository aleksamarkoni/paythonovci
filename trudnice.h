#ifndef _TRUDNICE_H_

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Trudnice {
private:
  int brojBeba;
public:
  Trudnice() {
    brojBeba = (rand() % 5) + 1;
  }
  ~Trudnice() {}

  int getBeba() const {
    return this->brojBeba;
  }

  bool sortiraj(const Trudnice & s1, const Trudnice & s2);
  ostream& operator<<(ostream& out) {
    vector <Trudnice> brBeba;
    int i,k;
    for (k = 0; k < i; k++) {
      out << brBeba[k].getBeba() << endl;
      return out;
    }
  }
};


#endif
