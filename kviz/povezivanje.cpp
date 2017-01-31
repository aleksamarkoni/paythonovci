#ifndef POVEZIVANJE_CPP
#define POVEZIVANJE_CPP
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "povezivanje.h"

using namespace std;

string getmyfile() {
  return this->myfile;
}

/*string& Povezivanje::operator=() {
    myfile = "/../../../../pitalice/CHAPTER2_Variables_and_Fundamental_Data_Types/21_fundamental_variable_types.txt";
  return myfile;
}*/

int izbor() {
int izbor;
cin >> izbor;
  switch(izbor) {
    case 1:
      myfile = "/../../../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/21_fundamental_variable_types.txt";
    break;
    case 2:
      myfile = "/../../../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/22_void.txt";
    break;
    case 3:
      myfile = "/../../../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/23_variable_sizes.txt";
    break;
    case 4:
      myfile = "/../../../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/24_integers.txt";
    break;
    case 5:
      myfile = "/../../../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/25_floating_point_numbers.txt";
    break;
    case 6:
      myfile = "/../../../../pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/26_boolean_values.txt";
    break;
    case 7:
      return 0;
    break;
  }
}

void ucitajPitanja(Pitanje& pitanje) {
  int stanje = 0;
  string line;
  while(myfile) {
    getline(myfile, line);
    if ("<" == line && stanje == 0) {
      pitanje = new Pitanje();
      stanje = 1;
    } else if (stanje == 1) {
      // ova linija je pitanje
      pitanje.setPitanje(line);
      stanje = 2;
    } else if (stanje == 2) {
      if (line != ">") {
        pitanje.dodajOdgovor(line);
      } else {
        pitanja.push_back(pitanje);
        stanje = 0;
      }
    }
  }
}

#endif
