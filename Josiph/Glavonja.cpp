#include "Vojnik.h"
#include "Glavonja.h"

using namespace std;

Glavonja::Glavonja() {
	ziv = true;
  brojZivota = 2;
  }

void Glavonja::ubijVojnika() {
	if (ziv) {
		brojZivota--;
			if (brojZivota == 0) {
				ziv = false;
				cout << "Glavonja je ubijen" << endl;
		} else {
			cout << "Glavonja zivi i ima jos " << brojZivota << " zivota" << endl;
		}
	} else {
		cout << "Glavonja je vec mrtav" << endl;
	}
}
