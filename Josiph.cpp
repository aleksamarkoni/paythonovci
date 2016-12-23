#include <iostream>
#include "Josiph.h"
#include "Vojnik.h"

using namespace std;

void Josiph::ispis() {
	for (int i = 0; i < k; i++) {
		cout << "(" << niz[i].poz << ", " << niz[i].ziv << ")" <<endl;
  }
	cout << "\n" << endl;
}

Josiph::Josiph(int koliko) {
	k = koliko;
	k2 = 0;
	niz = new Vojnik[k];
for (int i = 0; i < k; i++) {
	niz[i].poz = i+1;
}
}
void Josiph::LastStand() {
	k2 = 0;
for (int i = 0; i < k; i++) {
	if ( niz[i].poz % 2 == 0){
	  niz[i].ziv = false;
     }
		 if ( niz[i].ziv == true ){
			 k2++;
		 }
   }
	 Josiph::LastStand2();
 }
void Josiph::LastStand2() {

	while ( k2 != 1) {
  Josiph::ispis();
	niz2 = new Vojnik[k2];
	delete [] niz;
	niz = niz2;
	k = k2;
	delete [] niz2;
	Josiph::LastStand();}
	Josiph::ispis();
}

Vojnik::Vojnik() {
	ziv = true;
}

int main() {
	int n;
	int poz;
	cout << "Koliko vojnika?: ";
	cin >> n;
	Josiph Josiph(n);
	Josiph.ispis();
	Josiph.LastStand();
	Josiph.ispis();
}
