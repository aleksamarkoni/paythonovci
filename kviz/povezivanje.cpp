#ifndef POVEZIVANJE_CPP
#define POVEZIVANJE_CPP
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "izPocetkaPovezivanje.h"

using namespace std;

string Pitanje::getPitanje() {
  return this->pitanje;
}

string Odgovor::getOdgovor() {
  return this->odgovor;
}

string Povezivanje::dodajOdgovor(string line, Odgovor &odgovor) {
  odgovor.getOdgovor() = line;
  return odgovor.getOdgovor();
}

string Pitanje::setPitanje(Pitanje *novoPitanje, string line) {
  novoPitanje->pitanje = line;
  return novoPitanje->pitanje;
}

string Povezivanje::getmyfile() {
  return this->myfile;
}

int Povezivanje::izbor() {
int izbor;
cin >> izbor;
  switch(izbor) {
    case 1:
      getmyfile() = "/../../../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/21_fundamental_variable_types.txt";
    break;
    case 2:
      getmyfile() = "/../../../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/22_void.txt";
    break;
    case 3:
      getmyfile() = "/../../../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/23_variable_sizes.txt";
    break;
    case 4:
      getmyfile() = "/../../../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/24_integers.txt";
    break;
    case 5:
      getmyfile() = "/../../../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/25_floating_point_numbers.txt";
    break;
    case 6:
      getmyfile() = "/../../../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/26_boolean_values.txt";
    break;
    case 7:
      return 0;
    break;
  }
}

vector<Pitanje> Povezivanje::getPitanja() {
  return this->pitanja;
}

ostream& operator<<(ostream& out, Pitanje& pitanje) {
  Povezivanje povezivanje;
  int i, br;
  for(int i = 0; i < br; i++) {
    out << povezivanje.getPitanja()[i] << endl;
    return out;
  }
}

void Povezivanje::ucitajPitanja(int *br) {
  int stanje = 0;
  br = 0;
  Odgovor odgovor;
  Pitanje *novoPitanje;
  string line;
  istringstream iss(myfile);
  while(iss) {
    getline(iss, line);
    if ("<" == line && stanje == 0) {
      //Pitanje *novoPitanje = &pitanje;
      //new(novoPitanje) Pitanje();
      Pitanje *novoPitanje = new Pitanje();
      stanje = 1;
    } else if (stanje == 1) {
      // ova linija je pitanje
      novoPitanje->getPitanje() = line;
      stanje = 2;
    } else if (stanje == 2) {
      if (line != ">") {
        novoPitanje->getPitanje() = dodajOdgovor(line, odgovor);
      } else {
        pitanja.push_back(*novoPitanje);
        stanje = 0;
        br++;
      }
    }
  }
}

void ispisi(Povezivanje &povezivanje, int *br) {
  for(int i = 0; i < *br; i++) {
    cout << povezivanje.getPitanja()[i] << endl;
  }
}

#endif
