#include <iostream>
#include <stdlib.h>
#include "Josiphklasa.h"
#include "Vojnik.h"
#include "VojnikGS.h"

using namespace std;

void Josiph::ispis() {
	for (int i = 0; i < z; i++) {
		cout << "(" << krug[i].poz << ", " << (krug[i].ziv?"Ziv":"Mrtav") << ")";
  }
	cout << "\n" << endl;
}

ostream &operator<<( ostream &output, const Vojnik &a ) {
	output << "(" << a.poz << "," << (a.ziv?"Ziv":"Mrtav") << ")";
return output;
}
Josiph::Josiph() {
 z = 5;
 u = 5;
 krug = new Vojnik[u];
 for (int i = 0; i < z; i++) {
	 krug[i].poz = i+1;
	}
}

Josiph::Josiph(int koliko, int gp) {
	u = koliko;
	z = koliko;
	krug = new Vojnik[u];
  for (int i = 0; i < z; i++) {
	  krug[i].poz = i+1;
  }
		krug[gp] = Glavonja();
}

void Josiph::killThemAll(int m) {
  if ( m == 0 ) {
    m = 1;
  }
  for (int i = 0; i < z; i+=(m+1)) {
      krug[(i+m)%z].ziv = false;
  }
}

void ubijVojnika() {
	srand (time(NULL));
	int iSecret = rand() % 100 + 1;
	if (ziv) {
		if (iSecret <= 70)
			brojZivota--;
			if (brojZivota == 0) {
				ziv = false;
				cout << "Glavonja Sreckovic je ubijen" << endl;
		} else {
			cout << "Glavonja Sreckovic zivi i ima jos " << brojZivota << " zivota" << endl;
		}
	} else {
		cout << "Glavonja Sreckovic je vec mrtav" << endl;
	}
}

Vojnik Josiph::LastStand(int m) {
	while(z > 1) {
  ispis();
  killThemAll(m);
  ispis();
  removeDeadSoldersInPlace2();
  }
  return krug[0];
 }

void Josiph::removeDeadSoldiers() {
	Vojnik *krugZivih = new Vojnik[u];
	int br = 0;
	for (int i = 0; i < z; i++) {
		if (krug[i].ziv) {
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
			if (krug[i].ziv) {
				krug[br++] = krug[i];
			}
		}
		z = br;
	}

  void Josiph::removeDeadSoldersInPlace2() {
    int br = 0;
    u = z;
    for (int i = 0; i < u; i++) {
      if (krug[i].ziv) {
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

Vojnik::Vojnik() {
	ziv = true;
}

VojnikGS::Glavonja() {
	ziv = true;
	brojZivota = 3;
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
