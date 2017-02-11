#ifndef LOKAL_H
#define LOKAL_H
#include <iostream>
#include <vector>
#include "sto.h"

using namespace std;

class Lokal {
private:
  int brojStolova;
  vector <Sto> stolovi;
public:
  Lokal();
  ~Lokal();
  int getBrojStolova();
  void generisiStolove();
  void ispis(Lokal &pivnica);
  //int& operator()(vector <Sto> stolovi, const int index);
  friend ostream& operator<<(ostream& out, Lokal &pivnica);
};

#endif
