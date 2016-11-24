#ifndef _Vojnik_H
#define _Vojnik_H
#include <iostream>

using namespace std;

class Vojnik {
private:
	int poz;
	bool ziv;
public:
	Vojnik();
  friend class Josiph;
};
#endif
