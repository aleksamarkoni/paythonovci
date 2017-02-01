#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "menu.cpp"
#include "povezivanje.cpp"
#include "pitanje1.cpp"
#include "odgovor.cpp"

using namespace std;

Pitanje& Pitanje::operator=(Pitanje& pitanje) {
    istringstream iss;
    getline(iss, pitanje.pitanje);
    return pitanje;
}

ostream& operator<<(ostream& out) {
  out << pitanje.pitanje;
  return out;
}

/*void Odgovor::ucitajSamoOdgovor(vector<string>& kviz, vector< vector< string > >& sviOdgovori,
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
}*/

int magicnaKockica(int *i, int br){
  *i = rand() % br + 0;
  return *i;
}

int main() {
  int i;
  srand(time(NULL));
  //vector<Pitanje> pitanja;
  Pitanje pitanje;
  Povezivanje povezivanje;
  main_menu();
  povezivanje.izbor();

  //pitati korisnika da izabere kategoriju sa pitanjima
  //pronaci fajl u kome se nalazi kategorija sa pitanjaima
  // otvoriti fajl i ucitati pitanja u niz
  //iz niza random birati pitanje, i prikazati ga korisniku
  //pitati korisnika da da odgovor na pitanje
  //updejtovati score u zavisnosti od odgovora


  //povezivanje.ucitajPitanje(&pitanja);
  //random izaberi jedno pitanje iz vecorta
  // Pitanje pitanje = kviz[rand(0..kviz.size())]
  //pitanje.istampaj(true);
  //int brOdgvora = pitanje.kolikoImaOdgvora();

  //cout >> "unesite nesto izmedju 1 i " >> brOdgvora >> endl;
  //cin << pokusaj;

  //if (pitanje.proveriDaLiJeOdgovorTacan(pokusaj)) {
    //povecavam poene,ispisem bravo
  //} else {
    // ispisem nije dobro
  //}
  //pitanje.istampaj();

  //magicnaKockica(&i, br);
}
