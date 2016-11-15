#ifndef _PRAVOUGAONIK_H
#define _PRAVOUGAONIK_H
#include "Tacka.h"

class Pravougaonik {
private:
    int x;
    int y;
    int duzina;
    int sirina;
public:
        Pravougaonik();
        Pravougaonik(int x1, int y1, int duzina1, int sirina1);

  int getX();
  int getY();
  int getSirina();
  int getDuzina();
	int setX(int x1);
  int setY(int y1);
  int setDuzina(int duzina1);
  int setSirina(int sirina1);
  int getPovrsina();
  int getObim();
  bool TackaUPrav(Tacka a);
  bool TackaUPrav(int x, int y);
  class Pravougaonik presekDvaPravougaonika(Pravougaonik b);
  bool operator==(const Pravougaonik& d);
  bool operator!=(const Pravougaonik& d);
};
#endif
