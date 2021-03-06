#ifndef PITANJE1_H
#define PITANJE1_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "pitanje1.h"

using namespace std;

void izvlacenjePitanjaiOdgovora() {
  string line;
  isstream iss(pitanje);
  getLine(iss, line);
  if (line == "<") {
    getLine(mojFajl, line); // ucitaj samo pitanje
    pitanje = line;
    getLine(mojFajl, line);
    while (line != ">") {
      Odgovor odgovor(line, line[0]=="-"?false:true);
      odgovori.push_back(odgovor);//dodaj ovaj odgovor na pitanje
      getLine(mojFile, line);
    }
  }
}

bool proveriDaLiJeOdgovorTacan(int i) {
  if (i >= 1 && i <= odgovori.size()) {
    return odgovori[i-1].getTacan();
  }
  return false;
}

void istampaj(bool daLiPrikazujemOdgovore = false) {
  if (daLiPrikazujemOdgovore == true) {
    // stampam za znak onakav kakav jeste
  } else {
    // stampam samo crticu
  }
}

int kolikoImaOdgvora() {
  return odgovori.size();
}

#endif
