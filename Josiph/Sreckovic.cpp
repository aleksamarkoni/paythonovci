#include "Vojnik.h"
#include <stdlib.h>
#include "Sreckovic.h"

Sreckovic::Sreckovic() {
  ziv = true;
  }

void Sreckovic::ubijVojnika() {
	srand (time(NULL));
	int iSecret = rand() % 100 + 1;
		if (iSecret <= 70) {
			ziv = false;
				cout << "Sreckovic je ubijen" << endl;}
 	  else {
		cout << "Sreckovic je vec mrtav" << endl;
	}
}
