#include <iostream>
#include <climits>
#include <math.h>
#include <stdlib.h>
#include "Pravougaonik.h"
#include "Tacka.h"


using namespace std;

class Pravougaonik {
private:
    int x;
    int y;
    int duzina;
    int sirina;
public:
        Pravougaonik() {
        this->x = 0;
        this->y = 0;
        this->sirina = 0;
        this->duzina = 0;
    }
        Pravougaonik(int x1, int y1, int duzina1, int sirina1) {
        setX(x1);
        setY(y1);
        setDuzina(duzina1);
        setSirina(sirina1);
    }

    int getX() {
       return x;
    }
    int getY() {
       return y;
    }
    int getSirina() {
       return sirina;
    }
    int getDuzina() {
       return duzina;
    }

	int setX(int x1) {
		if (x1 >= 0) {
            this->x = x1;
        } else {
            cerr << "Ne moze x koji je negativan" << endl;
        }
	}

  int setY(int y1) {
		if (y1 >= 0) {
            this->y = y1;
        } else {
            cerr << "Ne moze y koji je negativan" << endl;
        }
	}

  int setDuzina(int duzina1) {
		if (duzina1 >= 0) {
            this->duzina = duzina1;
        } else {
            cerr << "Ne moze duzina koja je negativna" << endl;
        }
	}

  int setSirina(int sirina1) {
		if (sirina1 >= 0) {
            this->sirina = sirina1;
        } else {
            cerr << "Ne moze sirina koja je negativna" << endl;
        }
	}

  int getPovrsina() {
     return sirina * duzina;
  }
  int getObim() {
     return sirina*2 + duzina*2;
  }

bool TackaUPrav(Tacka a) {
  return TackaUPrav (a.getX(), a.getY());
}

bool TackaUPrav(int x, int y) {
  int tx1 = this->x;
  int ty1 = this->y;
  if (tx1 < x && ty1 < y && tx1 + duzina > x && ty1 + sirina > y) {
    return true;
  }
  else {
  return false;
  }
}

class Pravougaonik presekDvaPravougaonika(Pravougaonik b) {
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

if (tx2 < LONG_MIN) tx2 = LONG_MIN;
if (ty2 < LONG_MIN) ty2 = LONG_MIN;
return Pravougaonik(tx1, ty1, tx2, ty2);
}

bool operator==(const Pravougaonik& d) {
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

bool operator!=(const Pravougaonik& d) {
   return !(*this == d);
}

};

void test(Pravougaonik a, Pravougaonik b, Pravougaonik c);

int main() {
   Tacka t(4,4);
   Tacka t1(6, 6);
   Pravougaonik a(6,6,5,4);
   Pravougaonik b(3,3,10,6);
   Pravougaonik c = a.presekDvaPravougaonika(b);
   Pravougaonik d = b.presekDvaPravougaonika(a);
   cout << c.getX() << " " << c.getY() << " " << c.getDuzina() << " " << c.getSirina() << endl;
   cout << "Obim a: " << a.getObim() << endl;
   cout << "Obim b: " << b.getObim() << endl;
   cout << "Obim c: " << c.getObim() << endl;
   cout << "Povrsina a: " << a.getDuzina() << " " << a.getSirina() << " = " << a.getPovrsina() << endl;
   cout << "Povrsina b: " << b.getDuzina() << " " << b.getSirina() << " = " << b.getPovrsina() << endl;
   cout << "Povrsina c: " << c.getDuzina() << " " << c.getSirina() << " = " << c.getPovrsina() << endl;
   cout << "Da li su c i d isti: " << (d == c) << endl;
   cout << "Udaljenost izmedju dve tacke je: " << " " << t.udaljenost(c.getX(),c.getY()) << endl;
   cout << "Da li se tacka nalazi unutar pravougaonika: " << " " << a.TackaUPrav(4,4) << endl;
   cout << "Da li se tacka nalazi unutar pravougaonika: " << " " << b.TackaUPrav(t) << endl;

   Pravougaonik a1(1,1,5,5);
   Pravougaonik b1(3,3,5,5);
   Pravougaonik c1(3,3,2,2);
   test(a1, b1, c1);
   
   Pravougaonik a2(1,1,1,1);
   Pravougaonik b2(10,10,1,1);
   Pravougaonik c2(0,0,0,0);
   test(a2,b2,c2);
   
   return 0;
}

void test(Pravougaonik a, Pravougaonik b, Pravougaonik c) {
	Pravougaonik pp = a.presekDvaPravougaonika(b);
	if (pp == c) {
		cout << "Test je prosao." << endl;
	} else {
		cout << "Test je pao." << endl;
	}
}
