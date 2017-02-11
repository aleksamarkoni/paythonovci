#ifndef STO_H
#define STO_H
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

class Sto {
private:
  int brojGostiju;
public:
  Sto();
  ~Sto();
  friend ostream& operator<<(ostream& out, Sto &sto);
};

#endif
