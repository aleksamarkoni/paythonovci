#include <iostream>
#include "Tacka.h"
using namespace std;

class IzlomljenaLinija {
	private:
	   Tacka niz[20];
	   int poz;
	public:
	   IzlomljenaLinija(){
		   poz = 0;
	   }
	   void dodajTacku(int x, int y) {
		   Tacka p(x,y);
		   dodajTacku(p);
	   }
	   void dodajTacku(Tacka a) {
		   if (poz < 20) {
		      niz[poz] = a;
		      poz++;
		   } else {
			  cout << "Ne moze vise da stane" << endl;
		   }
	   }
	   void ispis() {
		   if (poz == 0) {
			   cout << "()" << endl;
		   } else {
			   for (int i = 0; i < poz; i++) {
			      cout << "(" << niz[i].getX() << "," << niz[i].getY() << ") ";
		       }
		       cout << endl;
		   }
	   }
};

int main() {
	IzlomljenaLinija pera;
	pera.ispis();
	pera.dodajTacku(5, 5);
	pera.ispis();
	for (int i = 0; i < 25; i++) {
		pera.dodajTacku(i, i*2);
	}
	pera.ispis();
}