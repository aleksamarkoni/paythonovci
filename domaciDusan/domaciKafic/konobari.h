#ifndef Konobar_H
#define Konobar_H
#include <iostream>
#include <stdlib.h>

using namespace std;

class Konobar {
private:
  int baksis;
  int dnevnica;
public:
  Konobar();
  int getBaksis();
  int getDnevnica();
  friend ostream& operator<<(ostream &out, Konobar &konobar);
};

#endif
