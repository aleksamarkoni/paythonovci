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
		   cout << "dodaj tacku" << endl;
           Tacka p(x,y);
           //dodajTacku(p);
		   dodajTacku(3, 7);
		   int p1 = 21;
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
	   
	friend ostream &operator<<( ostream &output, const IzlomljenaLinija &a ) {
		output << "[";
		if (a.poz > 0) {
			int i = 0;
			for (; i < a.poz - 1; i++) {
				output << a.niz[i] << ",";
			}
			output << a.niz[i];
		}
		output << "]";
		return output;
	}
};

int main() {
    IzlomljenaLinija pera;
    Tacka a;
    cout << pera << endl;
	pera.dodajTacku(a);
	cout << pera << endl;
	pera.dodajTacku(3, 3);
    for (int i = 0; i < 25; i++) { // i = 1
        pera.dodajTacku(i, i*2);
    }
	cout << pera << endl;
}