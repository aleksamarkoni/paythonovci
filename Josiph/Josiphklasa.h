#include "Vojnik.h"
#include "VojnikGS.h"
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
  void dodajVojnike();
public:
  friend ostream &operator<<( ostream &output, const Josiph &a );
  Josiph();
  Josiph(int koliko, int gp);
  Vojnik LastStand(int m);
};
#endif
