#include "Vojnik.h"
#ifndef _Josiph_H
#define _Josiph_H

class Josiph {
private:
  int k;
  int k2;
  Vojnik *niz;
  Vojnik *niz2;
public:
  Josiph(int koliko);
	void ispis();
  void LastStand();
  void LastStand2();
};
#endif
