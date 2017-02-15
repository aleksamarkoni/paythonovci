#include <iostream>
#include <vector>
#include "matrica.h"

using namespace std;

int main() {
  int m, n;
  cout << "Unesite duzinu i sirinu matrice." << endl;
  cin >> m >> n;
  Matrica *mat = new Matrica(m, n);
  mat->popuniMatricu(*mat);
  //mat->ispisiMatricu(*mat);
}
