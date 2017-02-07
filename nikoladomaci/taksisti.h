#ifndef TAKSISTI_H
#define TAKSISTI_H

#include <iostream>
#include <cstdlib>
#include <ostream>
#include <fstream>
#include <istream>
#include <time.h>

using namespace std;

class Taksisti {
private:
  int brojTaksista;
  int vozacevID;
public:
  Taksisti() {}
  Taksisti(int) {}
 // friend ostream &operator<<(ostream &out, Taksisti &vozaci);
  int getBrojVozaca();
  void setBrojVozaca(int);
  //Taksisti &operator=(Taksisti &vozaci);
};

#endif
