#include "sto.h"
using namespace std;

ostream& operator<<(ostream& out, Sto &sto) {
  out << sto.brojGostiju;
  return out;
}

Sto::Sto() {
  brojGostiju = rand() % 8 + 2;
}

Sto::~Sto() {}
