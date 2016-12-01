#include "Vojnik.h"
#include "VojnikGS.h"
#include <stdlib.h>

using namespace std;

VojnikGS::VojnikGS() {
	ziv = true;
	brojZivota = 3;
}

void VojnikGS::ubijVojnika() {
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
