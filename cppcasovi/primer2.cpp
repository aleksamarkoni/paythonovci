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
        duzina = duzina1;
        sirina = sirina1;
        setX(x1);
        if (y1 >= 0) {
            this->y = y1;
        } else {
            cerr << "Ne moze y koji je negativan" << endl;
        }
        if (duzina1 > 0) {
            this->duzina = duzina1;
        } else {
            cerr << "Ne moze duzina koja je negativna" << endl;
        }
        if (sirina1 > 0) {
            this->sirina = sirina1;
        } else {
            cerr << "Ne moze sirina koja je negativna" << endl;
        }
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
  int getPovrsina() {
     return sirina * duzina;
  }
  int getObim() {
     return sirina*2 + duzina*2;
  }
class Pravougaonik presekDvaPravougaonika(Pravougaonik b) {
class Pravougaonik pp;
   if ( x > b.x && x + duzina > b.x + b.duzina ) { //gornji leviX i donji leviX i levi SrednjiX
     pp.duzina = b.x - x + b.duzina;
   }
   if ( y > b.y && y + sirina > b.y + b.sirina ) { //gornji leviY i gornji desniY
     pp.sirina = b.y - y + b.sirina;
   }
   if ( x < b.x && x + duzina > b.x + b.duzina ) { //gornji srednjiX
     pp.duzina = b.duzina;
   }
   if ( y < b.y && y + sirina > b.y + b.sirina ) { //gornji srednjiY i levi srednjiY
     if ( b.x < x ) {
     pp.sirina = b.sirina; }
     else {
     pp.sirina = b.sirina - y;
   }}
   if ( y < b.y && y + sirina > b.y + b.sirina && b.x > x ) { //desni srednjiY
     pp.sirina = b.sirina;
   }
   if ( x < b.x && x + duzina < b.x + b.duzina ) { //gornji desniX i desni srednjiX i donji desniX
       pp.duzina = duzina - b.x + x;
   }
   if ( y < b.y && y + sirina < b.y + b.sirina ) { //donji leviY
     pp.sirina = sirina - b.y + y;
   }
   if ( x < b.x && x + duzina > b.x + b.duzina && b.y > y && //srednji srednjiXY
      y + sirina > b.y + b.sirina ) {
        pp.duzina = b.duzina;
        pp.sirina = b.sirina;
   }
   if ( x + duzina < b.x ) { //Van desno
        pp.duzina = -1;
        pp.sirina = 1;
   }
    if ( y + sirina < b.y ) { //Van dole
        pp.duzina = -1;
        pp.sirina = 1;
    }
    if ( y > b.y + b.sirina ) { //Van gore
        pp.duzina = -1;
        pp.sirina = 1;
    }
    if ( x > b.x + b.duzina ) { //Van levo
        pp.duzina = -1;
        pp.sirina = 1;
    }
    return pp;
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



int main() {
   Pravougaonik a(3,3,10,6);
   Pravougaonik b(6,6,5,4);
   Pravougaonik c = a.presekDvaPravougaonika(b);
   Pravougaonik d = b.presekDvaPravougaonika(a);
   cout << c.getX() << " " << c.getY() << " " << c.getDuzina() << " " << c.getSirina() << endl;
   cout << "Povrsina za c je: " << c.getPovrsina() << endl;
   cout << "Obim a: " << a.getObim() << endl;
   cout << "Obim b: " << b.getObim() << endl;
   cout << "Povrsina a: " << a.getDuzina() << " " << a.getSirina() << " = " << a.getPovrsina() << endl;
   cout << "Povrsina b: " << b.getDuzina() << " " << b.getSirina() << " = " << b.getPovrsina() << endl;
   cout << "Povrsina c: " << c.getDuzina() << " " << c.getSirina() << " = " << c.getPovrsina() << endl;
   cout << "Obim c: " << c.getObim() << endl;
   cout << true << " " << false << endl;
   cout << "Da li su c i d isti: " << (d == c) << endl; 
   return 0;
}
