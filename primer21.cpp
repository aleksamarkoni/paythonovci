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
    int povrsina() {
       return sirina * duzina;
    }
    int obim() {
       return sirina*2 + duzina*2;
    }
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
		duzina = duzina1;
		sirina = sirina1;
		if (x1 >= 0) {
			x = x1;
		} else {
			cerr << "Ne moze x koji je negativan" << endl;
		}
		if (y1 >= 0) {
			y = y1;
		} else {
			cerr << "Ne moze y koji je negativan" << endl;
		}
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

	int getX() {
	   return x;
	}

	void setX(int x1) {
		if (x1 > 0) {
			this->x = x1;
		} else {
			cerr << "x mora biti pozitivan" << endl;
		}
	}

	int getY() {
	   return y;
	}
	void setY(int y1) {
		if (y1 > 0) {
			this->y = y1;
		} else {
			cerr << "y mora biti pozitivan" << endl;
		}
	}

	int getSirina() {
	   return sirina;
	}
	void setSirina(int sirina1) {
		if (sirina1 > 0) {
			this->sirina = sirina1;
		} else {
			cerr << "sirina mora biti pozitivna" << endl;
		}
	}

	int getDuzina() {
	   return duzina;
	}
	void setDuzina(int duzina) {
		if (duzina > 0) {
			this->duzina = duzina;
		} else {
			cerr << "duzina mora biti pozitivna" << endl;
		}
	}

  int getPovrsina() {
     return povrsina();
  }

  int getObim() {
     return obim();
  }

int presekDvaPravougaonika(Pravougaonik a, Pravougaonik b) {
int povrsina_preseka;
int dx = 0;
int dy = 0;
   if ( a.x > b.x && a.x + a.duzina > b.x + b.duzina ) { //gornji leviX i donji leviX i levi SrednjiX
     dx = b.x - a.x + b.duzina;
   }
   if ( a.y > b.y && a.y + a.sirina > b.y + b.sirina ) { //gornji leviY i gornji desniY
     dy = b.y - a.y + b.sirina;
   }
   if ( a.x < b.x && a.x + a.duzina > b.x + b.duzina ) { //gornji srednjiX
     dx = b.duzina;
   }
   if ( a.y < b.y && a.y + a.sirina > b.y + b.sirina ) { //gornji srednjiY i levi srednjiY
     if ( b.x < a.x ) {
     dy = b.sirina; }
     else {
     dy = b.sirina - a.y;
   }}
   if ( a.y < b.y && a.y + a.sirina > b.y + b.sirina && b.x > a.x ) { //desni srednjiY
     dy = b.sirina;
   }
   if ( a.x < b.x && a.x + a.duzina < b.x + b.duzina ) { //gornji desniX i desni srednjiX i donji desniX
       dx = a.duzina - b.x + a.x;
   }
   if ( a.y < b.y && a.y + a.sirina < b.y + b.sirina ) { //donji leviY
     dy = a.sirina - b.y + a.y;
   }
   if ( a.x < b.x && a.x + a.duzina > b.x + b.duzina && b.y > a.y && //srednji srednjiXY
      a.y + a.sirina > b.y + b.sirina ) {
        dx = b.duzina;
        dy = b.sirina;
   }
   if ( a.x + a.duzina < b.x ) { //dole desno vanXY
        dx = -1;
        dy = 1;
   }

   povrsina_preseka = dx * dy;
   return povrsina_preseka;
   }
};





int main() {
   Pravougaonik a(3,3,10,6);
   Pravougaonik b(14,7,3,3);
   Pravougaonik c;
   cout << "Povrsina za c je: " << c.presekDvaPravougaonika(a,b) << endl;
   cout << "Obim a: " << a.getObim() << endl;
   cout << "Obim b: " << b.getObim() << endl;
   cout << "Povrsina a: " << a.getPovrsina() << endl;
   cout << "Povrsina b: " << b.getPovrsina() << endl;
   //cout << "c: " << c.getX() << " " << c.y << " " << c.sirina << " " << c.duzina << endl;
   return 0;
}
