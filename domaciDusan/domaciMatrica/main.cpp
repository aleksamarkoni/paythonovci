#include <iostream>
#include <vector>
#include "matrica.h"

using namespace std;

int main() {
  Matrica<char> mapa(11, 11);
  mapa.set(0, 5, 3);
  cout << mapa << endl;
}
