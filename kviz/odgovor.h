#ifndef ODGOVOR_H
#define ODGOVOR_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

class Odgovor: public Pitanje {
private:
  string odgovor;
  bool tacan;
public:
  Odgovor() {}
  ~Odgovor() {}
};
