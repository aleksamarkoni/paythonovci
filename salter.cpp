#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class SaVezom {
private:
  int evrici;
public:
  SaVezom() {
    evrici = (rand() % 10000) + 0;
  }
  ~SaVezom() {}

  int getEvrici() const {
    return this->evrici;
  }

  bool sortiraj(const SaVezom & s1, const SaVezom & s2);

  ostream& operator<<(ostream& out) {
    vector <SaVezom> Veza;
    int i,k;
    for (k = 0; k < i; k++) {
      out << Veza[k].getEvrici() << endl;
      return out;
    }
  }
};

int konstruktorNizaRandom(int *i) {
  *i = (rand() % 20) + 0;
  return *i;
}

bool sortiraj(const SaVezom & s1, const SaVezom & s2) {
   if (s1.getEvrici() != s2.getEvrici())
   return s1.getEvrici() > s2.getEvrici();
}

void upisPederaSaVezom(int *i, vector <SaVezom>& Veza) {
  for (int k = 0; k < *i; k++) {
    Veza.push_back(SaVezom());
    //cout << Veza[k].getEvrici() << endl;
  }

}

void printNizova(int *i, vector <SaVezom> &Veza) {
  for (int k; k < *i; k++){
    cout << Veza[k].getEvrici() << endl;
  }
}

int main() {
  srand(time(NULL));
  int i;
  vector <SaVezom> Veza;
  Veza.reserve(i);
  konstruktorNizaRandom(&i);
  upisPederaSaVezom(&i, Veza);
  sort(Veza.begin(), Veza.end(), sortiraj);
  printNizova(&i, Veza);

}
