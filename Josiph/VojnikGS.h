#ifndef _VojnikGS_H
#define _VojnikGS_H
#include "Vojnik.h"
class VojnikGS : public Vojnik {
private:
   int brojZivota;
public:
  VojnikGS();
	void ubijVojnika();
};
#endif
