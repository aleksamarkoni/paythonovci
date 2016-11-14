#include <math.h>
#include <stdlib.h>
#include "Tacka.h"

int Tacka::getX() {
      return x;
   }
   
int Tacka::getY() {
      return y;
   }
   
Tacka::Tacka() {
	this->x = 0;
	this->y = 0;
}

Tacka::Tacka(int x1, int y1): x(x1), y(y1) {}

float Tacka::udaljenost() {
	return udaljenost(0,0);
}

float Tacka::udaljenost(int x, int y) {
	int xa = abs(this->x - x);
	int ya = abs(this->y - y);
	return sqrt(xa*xa+ya*ya);
}

float Tacka::udaljenost(Tacka t) {
	return udaljenost(t.x, t.y);
}