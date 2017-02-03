#ifndef POVEZIVANJE_CPP
#define POVEZIVANJE_CPP
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "izPocetkaPovezivanje.h"

//TODO ne treba define za cpp fajlove i ne include cpp

using namespace std;

string Pitanje::setPitanje(Pitanje *novoPitanje, string pomocni) {
  novoPitanje->pitanje = pomocni;
  return novoPitanje->pitanje;
}

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

/*string Pitanje::setPitanje(Pitanje *novoPitanje, string line) {
  novoPitanje->pitanje = line;
  return novoPitanje->pitanje;
}*/

string Povezivanje::getmyfile() {
  return this->myfile;
}

int Povezivanje::izbor() {
int izbor;
cin >> izbor;
  switch(izbor) {
    case 1:
      myfile = "./../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/21_fundamental_variable_types.txt";
      cout << "Biranje oblasti:" << myfile << endl;
    break;
    case 2:
      myfile = "./../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/22_void.txt";
    break;
    case 3:
      myfile = "./../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/23_variable_sizes.txt";
    break;
    case 4:
      myfile = "./../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/24_integers.txt";
    break;
    case 5:
      myfile = "./../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/25_floating_point_numbers.txt";
    break;
    case 6:
      myfile = "./../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/26_boolean_values.txt";
    break;
    case 7:
      exit(1);
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

void Povezivanje::ucitajPitanja(int *br, string pomocni) {

  int stanje = 0;
  br = 0;
  Odgovor odgovor;
  Pitanje *novoPitanje = new Pitanje();
  novoPitanje->pitanje = "";
  //obrisi odgovore
  string line;
  fstream mojfajl;
  mojfajl.open((myfile).c_str());
  cout << "Otvaranje fajla:" << myfile << endl;
  //istringstream iss(mojfajl);
  while(mojfajl) {
    getline(mojfajl, line);
    cout << "Prva linija:" << line << endl;
    if ("<" == line && stanje == 0) {
      //Pitanje *novoPitanje = &pitanje;
      //new(novoPitanje) Pitanje();
      stanje = 1;
    } else if (stanje == 1) {
      // ova linija je pitanje
      cout << "Pitanje:" << line << endl;
      pomocni = line;
      cout << "Pomocni:" << pomocni << endl;
      novoPitanje->setPitanje(novoPitanje, pomocni);
      cout << novoPitanje->getPitanje() << endl;
      stanje = 2;
    } else if (stanje == 2) {
      if (line != ">") {
        novoPitanje->getPitanje() = dodajOdgovor(line, odgovor);
      } else {
        pitanja.push_back(*novoPitanje);
        stanje = 0;
        br++;
        delete novoPitanje;
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
