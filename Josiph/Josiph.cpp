#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Josiphklasa.h"
#include "Vojnik.h"

using namespace std;

/*Josiph::Josiph() {
 z = 5;
 u = 5;
 int poz;
 krug = new Vojnik[u];
 for (int i = 0; i < z; i++) {
 	poz = i+1;
  	krug[i].setPoz(poz);
	 //krug[i].getPoz() = i+1;
	 krug[i] = dodajVojnike();
	}
}*/

Josiph::Josiph(int koliko) {
	int vrsta = 0;
	u = koliko;
	z = koliko;
	//int poz;
	krug = new Vojnik[u];
  for (int i = 0; i < z; i++) {
  	krug[i] = dodajVojnika(&vrsta);
  	//poz = i+1;
  	krug[i].poz = i+1;
		cout << krug[i] << endl;
	 // krug[i].getPoz() = i+1;
  }
}

Vojnik Josiph::dodajVojnika(int *vrsta) {
	srand (time(NULL));
		*vrsta += rand() % 4 + 1;
		if (*vrsta > 4){
		*vrsta = rand() % 4 + 1;}
			cout << *vrsta << endl;
    switch (*vrsta) {
      case 1:
					 return Vojnik();
           break;
      case 2:
					 return Sreckovic();
           break;
      case 3:
           return Glavonja();
           break;
      case 4:
           return VojnikGS();
           break;
    }
}

void Josiph::killThemAll(int m) {
  if ( m == 0 ) {
    m = 1;
  }
  for (int i = 0; i < z; i+=(m+1)) {
    krug[(i+m)%z].ubijVojnika();
  }
}

Vojnik Josiph::LastStand(int m) {
  while(z > 1) {
  //cout << test << endl;
  killThemAll(m);
  //cout << test << endl;
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

int main() {
	int n;
  int m;
	cout << "Koliko vojnika?: ";
	cin >> n;
  cout << "Kojeg od sebe ubijaju? ";
  cin >> m;
	Josiph test(n);
	cout << test << endl;
  cout<< test.LastStand(m) << endl;
  cout << test << endl;
}
