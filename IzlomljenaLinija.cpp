#include <iostream>
#include "Tacka.h"
using namespace std;

class IzlomljenaLinija {
	private:
	   int poz;
		 int velicinaNiza;
		 Tacka *niz;
	public:
	   IzlomljenaLinija(){
		   poz = 0;
			 velicinaNiza = 5;
			 niz = new Tacka[velicinaNiza];
	   }
	   void dodajTacku(int x, int y) {
		   Tacka p(x,y);
		   dodajTacku(p);
	   }
	   void dodajTacku(Tacka a) {
		   if (poz >= velicinaNiza) {
	 				velicinaNiza *= 2;
	 				Tacka *p = new Tacka[velicinaNiza];
	 				for (int i = 0; i < poz; i++) {
	 					p[i] = niz[i];
	 				}
	 				delete [] niz;
	 				niz = p;
	 			}
	 			niz[poz] = a;
	 			poz++;
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
