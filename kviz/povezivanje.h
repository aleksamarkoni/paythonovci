#ifndef POVEZIVANJE_H
#define POVEZIVANJE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Pitanje;

class Povezivanje {
private:
  string myfile;
  vector<Pitanje> pitanja;
public:
  Povezivanje() {}
  ~Povezivanje() {}
  string getmyfile();
  void getString(string myfile);
  //string& operator=();
  void ucitajPitanja(Pitanje& pitanje);
  int izbor();
};

#endif
