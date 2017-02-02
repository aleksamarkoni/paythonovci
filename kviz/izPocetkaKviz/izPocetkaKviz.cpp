#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "izPocetkaMenu.cpp"
#include "izPocetkaPovezivanje.cpp"
#include "izPocetkaPitanje.cpp"
#include "izPocetkaOdgovor.cpp"

using namespace std;

string pomocni;
int br;

int magicnaKockica(int *i, int br){
  *i = rand() % br + 0;
  return *i;
}

int main() {
  int i;
  srand(time(NULL));
  Povezivanje povezivanje;
  main_menu();
  povezivanje.izbor();
  povezivanje.ucitajPitanja(&br, pomocni);
  ispisi(povezivanje, &br);
}
