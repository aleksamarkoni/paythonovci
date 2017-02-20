#include <iostream>
#include "matrica.h"

using namespace std;

int main() {
  Mat* m = new Mat(3, 3);
  cout << *m;
  if (m->srednjaVrednostDijagonale() == 0) {
    cout << "ne moze" << endl;
  }
  else {
  cout << "Srednja vrednost dijagonale: " << m->srednjaVrednostDijagonale() << endl;
  cout << "Suma glavne dijagonale: " << m->sumNaDijagonali() << endl;
  cout << "Suma sporedne dijagonale: " << m->sumNaSporednojDijagonali() << endl;
  }
}
