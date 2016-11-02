#include <iostream>

using namespace std;
/*
typedef struct Pravougaonik {
   int x;
   int y;
   int sirina;
   int duzina;
} Prav;

int povrisina(Prav a) {
   return a.sirina * a.duzina;
}

*/

class Pravougaonik {
private:
    int x;
    int y;
    int duzina;
    int sirina;
public:
    Pravougaonik() {
		x = 0;
		y = 0;
		sirina = 0;
		duzina = 0;
	}
	Pravougaonik(int x1, int y1, int duzina1, int sirina1) {
		x = x1;
		y = y1;
		if (duzina1 > 0) {
			duzina = duzina1;
		} else {
			cerr << "Ne moze duzina koja je negativna" << endl;
		}
		if (sirina1 > 0) {
			sirina = sirina1;
		} else {
			cerr << "Ne moze sirina koja je negativna" << endl;
		}	
	}
    int povrsina() {
       return sirina * duzina;
    }
	int getSirina() {
	   return sirina;
	}
	void setSirina(int sirina1) {
		if (sirina1 > 0) {
			sirina = sirina1;
		} else {
			cerr << "sirina mora biti pozitivna" << endl;
		}
	}
	
	int getDuzina() {
	   return duzina;
	}
	void setDuzina(int duzina) {
		if (duzina > 0) {
			this.duzina = duzina;
		} else {
			cerr << "duzina mora biti pozitivna" << endl;
		}
	}
};

class Player {
	// ime igraca
	// clasa {druid, hunter, mage, wrarior}
	// rasa {human, undead, }
	// Lista itema koje nosi {hands, head, weapon}
	// Profesije
	// inventar
}

int main() {
   Pravougaonik a;
   Pravougaonik b(5,6, 10, 12);
   Pravougaonik c(0,0, 4, 4);
   cout << "Povrsina za b je: " << b.povrsina() << endl;
   cout << b.getX() << endl;
   //cout << "a: " << a.getX() << " " << a.y << " " << a.sirina << " " << a.duzina << endl;
   //cout << "b: " << b.getX() << " " << b.y << " " << b.sirina << " " << b.duzina << endl;
   //cout << "c: " << c.getX() << " " << c.y << " " << c.sirina << " " << c.duzina << endl;
   return 0;
}
