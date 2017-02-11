#include <iostream>
#include <ctime>
#include <vector>
#include <stdlib.h>
//#include "konacnaZarada.h"
#include "lokal.h"
#include "sto.h"
//#include "konobari.h"
//#include "pice.h"
//#include "cenaPica.h"

using namespace std;

int main() {
  srand(time(NULL));
  Lokal pivnica;
  cout << "Pivnica ima " << pivnica.getBrojStolova() << " " << "stolova." << endl;
  pivnica.generisiStolove();
  pivnica.ispis(pivnica);
}
