#ifndef _VojnikGS_H
#define _VojnikGS_H
#include "Vojnik.h"
class VojnikGS : public Vojnik {
private:
   int brojZivota;
public:
	Glavonja();
	void ubijVojnika();
  friend class Vojnik;
  friend class Josiph;
};
#endif
