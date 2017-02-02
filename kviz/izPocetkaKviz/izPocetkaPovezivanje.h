#ifndef POVEZIVANJE_H
#define POVEZIVANJE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "izPocetkaPitanje.h"
#include "izPocetkaOdgovor.h"

using namespace std;

class Povezivanje {
private:
  string myfile;
  vector<Pitanje> pitanja;
public:
  Povezivanje() {}
  ~Povezivanje() {}
  string getmyfile();
  vector<Pitanje> getPitanja();
  string dodajOdgovor(string line, Odgovor &odgovor);
  void ucitajPitanja(int *br, string pomocni);
  int izbor();
};

#endif
