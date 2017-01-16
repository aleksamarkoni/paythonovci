#ifndef UCITAJ_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Pitanje {
private:
  string pitanje;
public:
  Pitanje() {}
  ~Pitanje() {}
  Pitanje& operator=(Pitanje& pitanje);
  friend ostream& operator<<(ostream& out, Pitanje& pitanje);
  void ucitajSamoPitanje(vector<string>& kviz, Pitanje& pitanje, int i);

};

class Odgovor: public Pitanje {
private:
  string odgovor;
  bool tacan;
public:
  Odgovor() {}
  ~Odgovor() {}
  void ucitajSamoOdgovor(vector<string>& kviz, vector< vector< string > >& sviOdgovori,
     Odgovor &odgovor, int i, int brOdgovora);

};
#endif
