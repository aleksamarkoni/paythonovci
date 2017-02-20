#include "Vojnik.h"
#include "VojnikGS.h"
#include "Sreckovic.h"
#include "Glavonja.h"
#ifndef _Josiphklasa_H
#define _Josiphklasa_H
using namespace std;
class Josiph {
private:
  int u;
  int z;
  Vojnik *krug;
  void killThemAll(int m);
  void removeDeadSoldiers();
  void removeDeadSoldersInPlace();
  void removeDeadSoldersInPlace2();
  void ispis();
  Vojnik dodajVojnika(int *vrsta);
public:
  friend ostream &operator<<( ostream &output, const Josiph &a );
  Josiph();
  Josiph(int koliko);
  Vojnik LastStand(int m);
};
#endif
