#ifndef _TACKA_H
#define _TACKA_H
#include <iostream>

using namespace std;

class Tacka {
private:
    int x;
	int y;
public:
	Tacka();
	Tacka(int x1, int y1);
	int getX();
	int getY();
	float udaljenost();
	float udaljenost(int x, int y);
	float udaljenost(Tacka t);
	friend ostream &operator<<( ostream &output, const Tacka &a );
	friend istream &operator>>( istream  &input, Tacka &a );
};

#endif
