#include "sto.h"
using namespace std;

ostream& operator<<(ostream& out, Sto &sto) {
  int i,k;
  i = getBrojStolova();
  for (k = 0; k < i; k++) {
    out << pivnica.stolovi[k] << endl;
  }
  return out;
}

Sto::Sto() {
  brojGostiju = rand() % 8 + 2;
}

Sto::~Sto() {}
