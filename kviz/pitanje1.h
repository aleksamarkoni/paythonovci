#ifndef PITANJE1_H
#define PITANJE1_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

class Pitanje {
private:
  string pitanje;
  vector<Odgovor> odgovori;
public:
  Pitanje() {}
  Pitanje& operator=(Pitanje& pitanje);
  void izvlacenjePitanjaiOdgovora();
  bool proveriDaLiJeOdgovorTacan(int i);
  int kolikoImaOdgvora()
  void istampaj(bool daLiPrikazujemOdgovore = false);
  void setPitanje(string Pitanje);
  void ocistiOdgovore();
  void dodajOdgovor(Odgovor odgovor);
};
#endif
