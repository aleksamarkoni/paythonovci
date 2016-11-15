#include "Pravougaonik.h"
#include <iostream>
#include <climits>

using namespace std;

Pravougaonik::Pravougaonik() {
this->x = 0;
this->y = 0;
this->sirina = 0;
this->duzina = 0;
}
Pravougaonik::Pravougaonik(int x1, int y1, int duzina1, int sirina1) {
setX(x1);
setY(y1);
setDuzina(duzina1);
setSirina(sirina1);
}

int Pravougaonik::getX() {
return x;
}
int Pravougaonik::getY() {
return y;
}
int Pravougaonik::getSirina() {
return sirina;
}
int Pravougaonik::getDuzina() {
return duzina;
}

int Pravougaonik::setX(int x1) {
if (x1 >= 0) {
    this->x = x1;
} else {
    cerr << "Ne moze x koji je negativan" << endl;
}
}

int Pravougaonik::setY(int y1) {
if (y1 >= 0) {
    this->y = y1;
} else {
    cerr << "Ne moze y koji je negativan" << endl;
}
}

int Pravougaonik::setDuzina(int duzina1) {
if (duzina1 >= 0) {
    this->duzina = duzina1;
} else {
    cerr << "Ne moze duzina koja je negativna" << endl;
}
}

int Pravougaonik::setSirina(int sirina1) {
if (sirina1 >= 0) {
    this->sirina = sirina1;
} else {
    cerr << "Ne moze sirina koja je negativna" << endl;
}
}

int Pravougaonik::getPovrsina() {
return sirina * duzina;
}
int Pravougaonik::getObim() {
return sirina*2 + duzina*2;
}

bool Pravougaonik::TackaUPrav(Tacka a) {
return TackaUPrav (a.getX(), a.getY());
}

bool Pravougaonik::TackaUPrav(int x, int y) {
int tx1 = this->x;
int ty1 = this->y;
if (tx1 < x && ty1 < y && tx1 + duzina > x && ty1 + sirina > y) {
return true;
}
else {
return false;
}
}

class Pravougaonik Pravougaonik::presekDvaPravougaonika(Pravougaonik b) {
int tx1 = this->x;
int ty1 = this->y;
int rx1 = b.x;
int ry1 = b.y;
long tx2 = tx1; tx2 += this->duzina;
long ty2 = ty1; ty2 += this->sirina;
long rx2 = rx1; rx2 += b.duzina;
long ry2 = ry1; ry2 += b.sirina;
if (tx1 < rx1) tx1 = rx1;
if (ty1 < ry1) ty1 = ry1;
if (tx2 > rx2) tx2 = rx2;
if (ty2 > ry2) ty2 = ry2;
tx2 -= tx1;
ty2 -= ty1;
if (tx2 <= 0) ty2 = ty1 = tx2 = tx1 = 0;
if (ty2 <= 0) tx2 = tx1 = ty2 = ty1 = 0;

if (tx2 < LONG_MIN) tx2 = LONG_MIN;
if (ty2 < LONG_MIN) ty2 = LONG_MIN;
return Pravougaonik(tx1, ty1, tx2, ty2);
}

bool Pravougaonik::operator==(const Pravougaonik& d) {
if (x != d.x)
return false;
if (y != d.y)
return false;
if (sirina != d.sirina)
return false;
if (duzina != d.duzina)
return false;
return true;
}

bool Pravougaonik::operator!=(const Pravougaonik& d) {
return !(*this == d);
}
