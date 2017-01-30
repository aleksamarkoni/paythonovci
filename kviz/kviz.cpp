#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "kviz.h"
#include "menu.h"
#include "menu.cpp"

using namespace std;

int br = 0;

string& Povezivanje::operator=(Povezivanje& povezivanje) {
  povezivanje.myfile = "/home/dusan/gits/paythonovci/pitalice/CHAPTER2_Variables_and_Fundamental_Data_Types/21_fundamental_variable_types.txt";
  return myfile;
}

Pitanje& Pitanje::operator=(Pitanje& pitanje) {
    istringstream iss;
    getline(iss, pitanje.pitanje);
    return pitanje;
}

ostream& operator<<(ostream& out, Pitanje& pitanje) {
  out << pitanje.pitanje;
  return out;
}

//TODO izbaciti parametar povezivanje
void Povezivanje::brojPitanja(Povezivanje& povezivanje) {
  fstream mojfajl;
  mojfajl.open((povezivanje.myfile).c_str());
  string strInput;
  while(mojfajl) {
    getline(mojfajl, strInput);
    if(strInput == "<") {
      br++;
      continue;
    }
  }
}

void ucitajpitanja() {
  vector<Pitanje> pitanja;
  //otvori fajl bla bla
  Pitanje pitanje;
  int stanje = 0;
  while(mojFajl) {
    getLine(mojFajl, line);
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



void Povezivanje::popunjavanjeVektora(vector<string>& kviz, Povezivanje& povezivanje) {
  fstream mojfajl;
  mojfajl.open((povezivanje.myfile).c_str());
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
int magicnaKockica(int *i, int br){
  *i = rand() % br + 0;
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
  cout << "Odgovori na pitanje broj " << i << " su:" << endl;
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

void ucitajpitanja() {
  vector<Pitanje> pitanja;
  //otvori fajl bla bla
  Pitanje pitanje;
  int stanje = 0;
  while(mojFajl) {
    getLine(mojFajl, line);
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


void ucitajpitanja2() {
  vector<Pitanje> pitanja;
  while(mojFajl) {
    getLine(mojFajl, line);
    if (line == "<") {
      Pitanje pitanje;
      getLine(mojFajl, line); // ucitaj samo pitanje
      pitanje.setPitanje(line);
      getLine(mojFajl, line);
      while (line != ">") {
        pitanje.dodajOdgovor(line, line[0]=="-"?false:true);//dodaj ovaj odgovor na pitanje
        getLine(mojFile, line);
      }
      pitanje.push_back(pitanje);
    }
  }
}


void Povezivanje::popunjavanjeVektora(vector<string>& kviz, Povezivanje& povezivanje) {
  fstream mojfajl;
  mojfajl.open((povezivanje.myfile).c_str());
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
int magicnaKockica(int *i, int br){
  *i = rand() % br + 0;
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
  cout << "Odgovori na pitanje broj " << i << " su:" << endl;
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
  Povezivanje povezivanje;
  Odgovor odgovor;
  string myfile;
  main_menu();
  //TODO ukloniti parametar povezivanje
  povezivanje.izbor(povezivanje);
  povezivanje.brojPitanja(povezivanje);

  //pitati korisnika da izabere kategoriju sa pitanjima
  //pronaci fajl u kome se nalazi kategorija sa pitanjaima
  // otvoriti fajl i ucitati pitanja u niz
  //iz niza random birati pitanje, i prikazati ga korisniku
  //pitati korisnika da da odgovor na pitanje
  //updejtovati score u zavisnosti od odgovora

  vector<Pitanje> kviz();
  povezivanje.ucitajPitanje(&kviz);
  //random izaberi jedno pitanje iz vecorta
  // Pitanje pitanje = kviz[rand(0..kviz.size())]
  pitanje.istampaj(true);
  int brOdgvora = pitanje.kolikoImaOdgvora();

  cout >> "unesite nesto izmedju 1 i " >> brOdgvora >> endl;
  cin << pokusaj;

  if (pitanje.proveriDaLiJeOdgovorTacan(pokusaj)) {
    //povecavam poene,ispisem bravo
  } else {
    // ispisem nije dobro
  }
  pitanje.istampaj();


  vector<string> kviz(br);
  vector< vector< string > > sviOdgovori(br);
  cout << "Ukupan broj pitanja je " <<  br << "." << endl;
  povezivanje.popunjavanjeVektora(kviz, povezivanje);
  magicnaKockica(&i, br);
  //cout << "MagicnaKockica " << i << endl;
  pitanje.ucitajSamoPitanje(kviz, pitanje, i);
  cout << pitanje << endl;
  odgovor.ucitajSamoOdgovor(kviz, sviOdgovori, odgovor, i, brOdgovora);
  //cout << odgovor << endl;
  //cout << kviz;
}
