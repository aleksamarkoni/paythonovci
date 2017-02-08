#include "lokal.h"
#include "sto.h"

using namespace std;

ostream& operator<<(ostream& out, Lokal &pivnica) {
  int i,k;
  i = getBrojStolova();
  for (k = 0; k < i; k++) {
    out << pivnica.stolovi[k] << endl;
  }
  return out;
}

int& Lokal::operator()(const int index) {
  return stolovi[index];
}

int Lokal::ispis() {
  int i,k;
  i = getBrojStolova();
  for (k = 0; k < i; k++) {
    cout << stolovi[k] << endl;
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
