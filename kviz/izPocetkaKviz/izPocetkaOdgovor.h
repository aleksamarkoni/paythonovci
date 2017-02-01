#ifndef ODGOVOR_H
#define ODGOVOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <time.h>

class Odgovor {
private:
  string odgovor;
  bool tacan;
public:
  Odgovor() {}
  ~Odgovor() {}
  string getOdgovor();
  void ucitajSamoOdgovor(vector<string>& kviz,
     vector< vector< string > >& sviOdgovori,
     Odgovor &odgovor, int i, int brOdgovora);
};
#endif
