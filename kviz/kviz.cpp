#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "kviz.h"
//#include "menu.h"

using namespace std;

int br = 0;

Pitanje& Pitanje::operator=(Pitanje& pitanje) {
    istringstream iss;
    getline(iss, pitanje.pitanje);
    return pitanje;
}
ostream& operator<<(ostream& out, Pitanje& pitanje) {
  out << pitanje.pitanje;
  return out;
}

void brojPitanja(ifstream& mojfajl) {
  string strInput;
  while(mojfajl) {
    getline(mojfajl, strInput);
    if(strInput == "<") {
      br++;
      continue;
    }
  }
}

void popunjavanjeVektora(vector<string>& kviz) {
ifstream mojfajl("/home/nikola/gits/paythonovci/pitalice/CHAPTER2_Variables_and_Fundamental_Data_Types/21_fundamental_variable_types.txt");
string strInput;
string jednoPitanje;
    int i = 0;
    bool isBegin = false;
    while(mojfajl) {
      getline(mojfajl, strInput);
        if("<" == strInput)
        {
            isBegin = true;
            continue;
        }
        else
            if(">" == strInput)
            {
                isBegin = false;
                kviz[i] = jednoPitanje;
                jednoPitanje = "";
                i++;
                continue;
            }
        if(isBegin) {
          jednoPitanje += strInput;
          jednoPitanje += "\n";
    }
  }
}
int magicnaKockica(int *i){
  *i = rand() % 17 + 0;
  return *i;
}

void Pitanje::ucitajSamoPitanje(vector<string>& kviz, Pitanje &pitanje, int i) {
    cout << "Pitanje broj " << i << " je:" << endl;
    string strInput;
    strInput = kviz[i];
    istringstream iss(strInput);
    getline(iss, pitanje.pitanje);
}
void Odgovor::ucitajSamoOdgovor(vector<string>& kviz, vector< vector< string > >& sviOdgovori,
   Odgovor &odgovor, int i, int brOdgovora) {
  cout << "Odgovor " << i << " je:" << endl;
  size_t found;
  string strInput;
  string jednoPitanje;
  strInput = kviz[i];
  istringstream iss(strInput);
  while(iss) {
    getline(iss, jednoPitanje);
    if(!jednoPitanje.find("*") || !jednoPitanje.find("-")) {
    odgovor.odgovor = jednoPitanje;
    sviOdgovori[i].push_back(odgovor.odgovor);
    cout << sviOdgovori[i][brOdgovora] << endl;
    brOdgovora++;
    } else {
    continue;
      }
  }
}

int main() {
  int i;
  int brOdgovora = 0;
  srand(time(NULL));
  Pitanje pitanje;
  Odgovor odgovor;
  ifstream mojfajl("/home/nikola/gits/paythonovci/pitalice/CHAPTER2_Variables_and_Fundamental_Data_Types/21_fundamental_variable_types.txt");
  //ifstream mojfajl;
  //main_menu();
  brojPitanja(mojfajl);
  vector<string> kviz(br);
  vector< vector< string > > sviOdgovori(br);
  cout << "Ukupan broj pitanja je " <<  br << "." << endl;
  popunjavanjeVektora(kviz);
  magicnaKockica(&i);
  //cout << "MagicnaKockica " << i << endl;
  pitanje.ucitajSamoPitanje(kviz, pitanje, i);
  cout << pitanje << endl;
  odgovor.ucitajSamoOdgovor(kviz, sviOdgovori, odgovor, i, brOdgovora);
  //cout << odgovor << endl;

  //cout << kviz;
}
