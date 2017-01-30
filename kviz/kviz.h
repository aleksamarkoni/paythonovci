#ifndef UCITAJ_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//TODO izdvoj ovo u posebne fajlovi povezivanje.h. i povezivanje.cpp
class Povezivanje {
private:
  string myfile;
public:
  Povezivanje() {}
  ~Povezivanje() {}
  void getString(string myfile) {}
  string& operator=(Povezivanje& povezivanje);
  void brojPitanja(Povezivanje& povezivanje);
  //TODO obrisati ovaj parametar
  int izbor(Povezivanje& povezivanje);
  void popunjavanjeVektora(vector<string>& kviz, Povezivanje& povezivanje);
}

class Pitanje {
private:
  string pitanje;
  vector<Odgovor> odgovori;
public:
  Pitanje(string pitanje) {
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

  void setPitanje(string Pitanje);
  void ocistiOdgovore();
  void dodajOdgovor(Odgovor odgovor);

  int kolikoImaOdgvora() {
    return odgovori.size();
  }

  bool proveriDaLiJeOdgovorTacan(int i) {
    if (i >= 1 && i <= odgovori.size()) {
      return odgovori[i-1].getTacan();
    }
    return false;
  }
  void istampaj(bool daLiPrikazujemOdgovore = false) {
    ...
    if (daLiPrikazujemOdgovore == true) {
      // stampam za znak onakav kakav jeste
    } else {
      // stampam samo crticu
    }
  }
}

//TODO isto i za pitanje pitanje.h i pitanje.cpp
class Pitanje {
private:
  string pitanje;
  vector<Odgovor> odgovori;
public:
  Pitanje() {}
  ~Pitanje() {}
  Pitanje& operator=(Pitanje& pitanje);
  friend ostream& operator<<(ostream& out, Pitanje& pitanje);
  void ucitajSamoPitanje(vector<string>& kviz, Pitanje& pitanje, int i);
};

//TODO odgovor.h odgovor.cpp
class Odgovor: public Pitanje {
private:
  string odgovor;
  bool tacan;
public:
  Odgovor() {}
  ~Odgovor() {}
  void ucitajSamoOdgovor(vector<string>& kviz,
     vector< vector< string > >& sviOdgovori,
     Odgovor &odgovor, int i, int brOdgovora);
};
#endif
