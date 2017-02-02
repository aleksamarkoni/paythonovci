#ifndef PITANJE1_H
#define PITANJE1_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "izPocetkaOdgovor.h"

class Pitanje {
private:
  string pitanje;
  vector<Odgovor> odgovori;
public:
  Pitanje() {}
  void setPitanje(Pitanje *novoPitanje, string pomocni);
  string getPitanje();
  void izvlacenjePitanjaiOdgovora(string pitanje, string myfile);
  bool proveriDaLiJeOdgovorTacan(int i);
  int kolikoImaOdgvora();
  void istampaj(bool daLiPrikazujemOdgovore = false);
  //string setPitanje(Pitanje *novoPitanje, string line);
  void ocistiOdgovore();
  friend ostream& operator<<(ostream& out, Pitanje& pitanje);
};
#endif
