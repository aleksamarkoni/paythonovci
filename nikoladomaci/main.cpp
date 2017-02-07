#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ostream>
#include <fstream>
#include <istream>
#include "taksisti.h"

using namespace std;

void unesiteBrojVozaca(int *t) {
  cout << "Koliko vozaca postoji? " << endl;
  cin >> *t;
}

int main() {
  int t;
  Taksisti vozaci;
  unesiteBrojVozaca(&t);
  vozaci.setBrojVozaca(t);
  cout << "Ovoliko ima vozaca: " << vozaci.getBrojVozaca() << endl;
}
