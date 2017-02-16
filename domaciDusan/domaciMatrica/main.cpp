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
  int m, n;
  unesiBrojeve(&m, &n);


  Matrica mat(m, n);
  cout << mat << endl;
  cout << mat(3, 3) << endl;
  mat.sumNaDijagonali();
  mat.sumNaSporednojDijagonali();
}
