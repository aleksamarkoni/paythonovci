#include <iostream>
#include <math.h>
#include <stdlib.h>  

using namespace std;

class Tacka {
public:
   int x;
   int y;
   Tacka();
   Tacka(int,int);
   float udaljenost();
   float udaljenost(int x, int y);
   float udaljenost(Tacka t);
};

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

int main() {
	Tacka t(4,4);
	Tacka t1(6, 6);
	cout << t.udaljenost() << endl;
	cout << t.udaljenost(5,5) << endl;
	cout << t.udaljenost(t1) << endl;
	cout << t.udaljenost(t) << endl;
	cout << t.udaljenost(t1.x, t1.y) << endl;
}