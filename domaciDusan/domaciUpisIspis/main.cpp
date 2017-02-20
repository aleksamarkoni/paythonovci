#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <typeinfo>
#include "funkcije.h"

using namespace std;

int main() {
  vector <int> nizBrReci;
  vector <string> recenice;
  int brRecenica = 0;
  int izbor = 0;
  int answer;
  string ispis;

  /*run(main_menu,
     ucitajIzFajla,
     spojiReciURecenice,
     ispisNaEkran,
     upisReceniceUFajlRecPoRec,
     iscitavanjeIzFajlaRecPoReC);*/

  run(ispis,
    nizBrReci,
    brRecenica,
    recenice,
    izbor);
}
