#include <iostream>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include "lokal.h"
//#include "cenaPica.h"

using namespace std;

int main() {
  srand(time(NULL));
  Lokal pivnica;
  cout << "Pivnica ima " << pivnica.getBrojStolova() << " " << "stolova." << endl;
  pivnica.generisiStolove();
  pivnica.ispisStolova(pivnica);
  pivnica.ukupanBrojGostiju(pivnica);
  pivnica.ispisUkupnogBrojaGostiju(pivnica);
  pivnica.kolektiv.generisiKonobare(pivnica);
  pivnica.kolektiv.ispisKonobara(pivnica);
}
