#ifndef _Glavonja_H
#define _Glavonja_H
#include "Vojnik.h"
class Glavonja : public Vojnik {
private:
  int brojZivota;
public:
	Glavonja();
	void ubijVojnika();
  };
#endif
