#include "lokal.h"

using namespace std;

ostream& operator<<(ostream& out, Lokal &pivnica) {
  for (int k = 0; k < pivnica.stolovi.size(); k++) {
    out << pivnica.stolovi[k] << endl;
  }
  return out;
}

Lokal::Lokal() {
  brojStolova = 15;
}

//Kolektiv Lokal::getKolektiv() {
//  return kolektiv;
//}

vector <Sto> Lokal::getStolovi() {
  return stolovi;
}

int Lokal::getBrojStolova() {
  return brojStolova;
}

void Lokal::generisiStolove() {
  for(int i = 0; i < brojStolova; i++) {
    stolovi.push_back(Sto());
  }
}


void Lokal::ispisStolova(Lokal &pivnica) {
  for (int k = 0; k < getBrojStolova(); k++) {
    cout << k+1 <<". sto ima: " << pivnica.stolovi[k] << " gostiju." << endl;
  }
}

int Lokal::ukupanBrojGostiju(Lokal &pivnica) {
  int ukupanBrojGostiju = 0;
  for (int k = 0; k < pivnica.stolovi.size(); k++) {
    ukupanBrojGostiju += pivnica.stolovi[k].getBrojGostiju();
  }
  return ukupanBrojGostiju;
}

void Lokal::ispisUkupnogBrojaGostiju(Lokal &pivnica) {
  cout << "Ukupno ima: " << ukupanBrojGostiju(pivnica) << " gostiju." << endl;
}
