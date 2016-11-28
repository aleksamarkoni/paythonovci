#include <iostream>
#include <stdlib.h>
#include "Josiphklasa.h"
#include "Vojnik.h"

using namespace std;

void Josiph::ispis() {
	for (int i = 0; i < z; i++) {
		cout << "(" << krug[i].getPoz() << ", " << (krug[i].getZiv()?"Ziv":"Mrtav") << ")";
  }
	cout << "\n" << endl;
}

ostream &operator<<( ostream &output, const Vojnik &a ) {
	output << "(" << a.getPoz() << "," << (a.getZiv()?"Ziv":"Mrtav") << ")";
return output;
}
Josiph::Josiph() {
 z = 5;
 u = 5;
 krug = new Vojnik[u];
 for (int i = 0; i < z; i++) {
	 krug[i].getPoz() = i+1;
	 krug[i] = dodajVojnike();
	}
}

void Josiph::dodajVojnike() {
    int vrsta = rand() * 4 +1;
    switch (vrsta) {
        case 1:
           Vojnik();
           break;
        case 2:
           Sreckovic::Sreckovic();
           break;
			  case 3:
				   Glavonja();
					 break;
				case 4:
				   VojnikGS();
					 break;
    }
}

Josiph::Josiph(int koliko, int gp) {
	u = koliko;
	z = koliko;
	krug = new Vojnik[u];
  for (int i = 0; i < z; i++) {
	  krug[i].getPoz() = i+1;
		krug[i] = dodajVojnike();

  }
}

void Josiph::killThemAll(int m) {
  if ( m == 0 ) {
    m = 1;
  }
  for (int i = 0; i < z; i+=(m+1)) {
      krug[(i+m)%z].getZiv() = ubijVojnika();
  }
}

Vojnik Josiph::LastStand(int m) {
	while(z > 1) {
  cout << test; endl;
  killThemAll(m);
	cout << test; endl;
  removeDeadSoldersInPlace2();
  }
  return krug[0];
 }

void Josiph::removeDeadSoldiers() {
	Vojnik *krugZivih = new Vojnik[u];
	int br = 0;
	for (int i = 0; i < z; i++) {
		if (krug[i].getZiv()) {
			krugZivih[br++] = krug[i];
		}
	}
	z = br;
	delete [] krug;
	krug = krugZivih;
	}

	void Josiph::removeDeadSoldersInPlace() {
		int br = 0;
		for (int i = 0; i < z; i++) {
			if (krug[i].getZiv()) {
				krug[br++] = krug[i];
			}
		}
		z = br;
	}

  void Josiph::removeDeadSoldersInPlace2() {
    int br = 0;
    u = z;
    for (int i = 0; i < u; i++) {
      if (krug[i].getZiv()) {
        krug[br++] = krug[i]; }
        else {
        z--; }
      }
    }

	ostream &operator<<( ostream &output, const Josiph &a ) {
	 output << "[";
	 if (a.z > 0) {
		 int i = 0;
		 for (; i < a.z - 1; i++) {
			 output << a.krug[i] << ",";
		 }
		 output << a.krug[i];
	 }
	 output << "]";
	 return output;
	}

int main() {
	int n;
  int m;
	int gp;
	cout << "Koliko vojnika?: ";
	cin >> n;
  cout << "Kojeg od sebe ubijaju? ";
  cin >> m;
	cout << "Na kojoj poziciji je Glavonja Sreckovic? ";
	cin >> gp;
	if (gp > n) {
	cin >> gp; }
	Josiph test(n);
  cout<< test.LastStand(m) << endl;
}
