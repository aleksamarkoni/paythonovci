#include <iostream>
#include <string>
#include "pice.h"
#include "pivo.h"
#include "vino.h"

using namespace std;

void glavniMenu(char *izbor1) {
  cout << endl << endl;
  cout << "Hello, welcome to Jacks`s store." << endl;
  cout << endl;
  cout << "%%%%Product Name****Unit Price****Amount in Storage%%%%" << endl;
  cout << " Beer: $2.00; 10 Bottles " << endl;
  cout << " Soda: $3.00  10 Bottles" << endl;
  cout << " Wine: $5.00  10 Bottles" << endl;
  cout << " Gum:  $1     50 bars "<< endl;
  cout << " Milk: $6     30 Bottles." << endl;
  cout << "*******************************************************" << endl;
  cout << endl << endl;
  cout << "Please select the food you prefer, [P]ivo, [V]ino, [C]igerate, [G]um, [M]ilk." << endl;
  cout << "If you finish your shopping, please press [C] for check out." << endl;
  cin >> *izbor1;
}


void izborPiva(int *izbor) {
  cout << "Izaberite pivo" << endl;
  cout << "1. Grimbergen Blanche" << endl;
  cout << "2. Budweiser Budvar" << endl;
  cout << "3. Guinness Extra" << endl;
  cout << "0 za izlaz" << endl;
  cin >> *izbor;
}

void izborVina(int *izbor) {
  cout << "Izaberite vino" << endl;
  cout << "1. Ali-kant-buše" << endl;
  cout << "2. Sultanina bela" << endl;
  cout << "3. Buvijeova ranka" << endl;
  cout << "0 za izlaz" << endl;
  cin >> *izbor;
}

int main() {
  Pivo pivo1("pšenično pivo", "Grimbergen Blanche", "Belgija", "Alkoholno");
  Pivo pivo2("Lager pivo", "Budweiser Budvar", "Češka", "Bezalkoholno");
  Pivo pivo3("Stout pivo", "Guinness Extra", "Irska", "Alkoholno");
  Vino vino1("Bojadiseri", "Ali-kant-buše", "Francuska", "K-ING Vinarija");
  Vino vino2("Besemene", "Sultanina bela", "Turska", "Promont Distillery");
  Vino vino3("Belo vino", "Buvijeova ranka", "Srbija", "Destilerija Petrović");
  int izbor;
  char izbor1;
  glavniMenu(&izbor1);
  switch(izbor1) {
    case 'P':
      izborPiva(&izbor);
      switch(izbor) {
        case 1:
          cout << pivo1.getTip() << " " << pivo1.getVrstaPiva() << " " << pivo1.getImePiva() << ", zemlja porekla: " << pivo1.getPorekloPiva() << endl;
        break;
        case 2:
          cout << pivo2.getTip() << " " << pivo2.getVrstaPiva() << " " << pivo2.getImePiva() << ", zemlja porekla: " << pivo2.getPorekloPiva() << endl;
        break;
        case 3:
        cout << pivo3.getTip() << " " << pivo3.getVrstaPiva() << " " << pivo3.getImePiva() << ", zemlja porekla: " << pivo3.getPorekloPiva() << endl;
        break;
        case 0:
          cout << "Prijatan dan!" << endl;
        return 0;
        default:
          cout << "Pogresan izbor" << endl;
        return 0;
      }
    break;
    case 'V':
      izborVina(&izbor);
      switch(izbor) {
        case 1:
          cout << vino1.getImeVina() << " vrste " << vino1.getVrstaVina() << endl;
          cout << "zemlja porekla: " << vino1.getPorekloVina() << endl;
          cout << "proizvodjac: " << vino1.getProizvodjac() << endl;
        break;
        case 2:
          cout << vino2.getImeVina() << " vrste " << vino2.getVrstaVina() << endl;
          cout << "zemlja porekla: " << vino2.getPorekloVina() << endl;
          cout << "proizvodjac: " << vino2.getProizvodjac() << endl;
        break;
        case 3:
          cout << vino3.getImeVina() << " vrste " << vino3.getVrstaVina() << endl;
          cout << "zemlja porekla: " << vino3.getPorekloVina() << endl;
          cout << "proizvodjac: " << vino3.getProizvodjac() << endl;
        break;
        case 0:
          cout << "Prijatan dan!" << endl;
        return 0;
        default:
          cout << "Pogresan izbor" << endl;
        return 0;
      }
    break;
    case 3:
      //izborZvala(&izbor);
    break;
    case 4:
      //izborCigara(&izbor);
    break;
    case 0:
      cout << "Hvala sto ste koristili nasu aplikaciju!" << endl;
    return 0;
    default:
      cout << "Pogresan izbor" << endl;
    return 0;
  }
}
