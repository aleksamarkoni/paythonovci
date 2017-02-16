#include <iostream>
#include <vector>
#include "matrica.h"

using namespace std;

void unesiBrojeve(int *m, int *n) {
  cout << "Unesite duzinu i sirinu matrice." << endl;
  cin >> *m >> *n;
  while(*m != *n) {
    cout << "Ne moze bato, ovuda neces proci." << endl;
    cin >> *m >> *n;
  }
}

int main() {
  Matrica<char> mapa(11, 11);
  mapa.set(0, 5, 3);
  cout << mapa << endl;
}
