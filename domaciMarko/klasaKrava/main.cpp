#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "krava.h"

using namespace std;
/*
class Farma : public Krava {
private:
  int stoka;
  int farmer;
  int obrok;
public:
  Farma() {}
  ~Farma() {}
};*/
void izaberiKravu(int *izbor) {
  cout << "_______________________________" << endl;
  cout << "|------ Farma pythonovci ------|" << endl;
  cout << "|------- JEDITE KOD NAS -------|" << endl;
  cout << "|______________________________|" << endl;
  cout << "|______________________________|" << endl;
  cout << "|----- Izaberite kravu---------|" << endl;
  cout << "|______________________________|" << endl;
  cout << "| 1. Milkica                   |" << endl;
  cout << "| 2. Belkica                   |" << endl;
  cout << "|______________________________|" << endl;
  cin >> *izbor;

}


int main() {
  srand (time(NULL));
  Krava krava;
  krava.Milkica();
  krava.Belkica();

  int izbor;
  izaberiKravu(&izbor);
    switch(izbor) {
          case 1:
            cout << "Od ukupno : " << krava.getBrojKrava() << " krava izabrali ste Milkicu" << endl;
            cout << "Milkica je danas dala: " << krava.Milkica() << " liter mleka" << endl;
          break;
          case 2:
            cout << "Od ukupno : " << krava.getBrojKrava() << " krava izabrali ste Belkica" << endl;
            cout << "Belkica je danas dala: " << krava.Belkica() << " liter mleka" << endl;
          break;
}
}
