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
  friend istream& operator>>(istream& is, Pitanje& pitanje);
  friend ostream& operator<<(ostream& out, Pitanje& pitanje);
};

class Odgovor {
private:
  string odgovor;
  bool tacan;
};
#endif
