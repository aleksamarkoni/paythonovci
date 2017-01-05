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
};

class Odgovor: Pitanje {
private:
  string odgovor;
  bool tacan;
};
#endif
