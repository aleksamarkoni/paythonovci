#include "lokal.h"
#include "sto.h"

using namespace std;

ostream& operator<<(ostream& out, Lokal &pivnica) {
  for (int k = 0; k < pivnica.stolovi.size(); k++) {
    out << pivnica.stolovi[k] << endl;
  }
  return out;
}

/*
int& Lokal::operator()(const int index) {
  return stolovi[index];
}
*/

void Lokal::ispis(Lokal &pivnica) {
  for (int k = 0; k < getBrojStolova(); k++) {
    cout << k+1 <<". sto ima: " << pivnica.stolovi[k] << " gostiju." << endl;
  }
}

Lokal::Lokal() {
  brojStolova = 15;
}

Lokal::~Lokal() {}

int Lokal::getBrojStolova() {
  return brojStolova;
}

/*vector <Sto> Lokal::getStolovi() {
  return stolovi;
}*/

void Lokal::generisiStolove() {
  for(int i = 0; i < brojStolova; i++) {
    stolovi.push_back(Sto());
  }
}
