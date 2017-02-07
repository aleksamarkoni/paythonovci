#include <iostream>
#include <string>
#include <ctime>
#include "lokal.h"
#include "kafic.h"
#include "pub.h"

using namespace std;

void izborLokala(int *izbor) {
  cout << "Izaberite vrstu lokala" << endl;
  cout << "1. Kafic" << endl;
  cout << "2. Pub" << endl;
  cout << "3. Klub" << endl;
  cout << "4. Kafana" << endl;
  cout << "0 za izlaz" << endl;
  cin >> *izbor;
}

void izborKafica(int *izbor) {
  cout << "Izaberite kafic" << endl;
  cout << "1. Renesansa" << endl;
  cout << "2. Bridge" << endl;
  cout << "3. Ultra Caffe" << endl;
  cout << "0 za izlaz" << endl;
  cin >> *izbor;
}

void izborPuba(int *izbor) {
  cout << "Izaberite pub" << endl;
  cout << "1. Lion pub" << endl;
  cout << "2. London pub" << endl;
  cout << "3. Zlatna krigla" << endl;
  cout << "0 za izlaz" << endl;
  cin >> *izbor;
}

void izborKluba(int *izbor) {
  cout << "Izaberite klub" << endl;
  cout << "1. Johnny" << endl;
  cout << "2. Inter duo" << endl;
  cout << "3. Museum" << endl;
  cout << "0 za izlaz" << endl;
  cin >> *izbor;
}

void izborKafane(int *izbor) {
  cout << "Izaberite kafanu" << endl;
  cout << "1. Sve moje zore" << endl;
  cout << "2. Tri soma" << endl;
  cout << "3. Mustuluk" << endl;
  cout << "0 za izlaz" << endl;
  cin >> *izbor;
}

int dan_u_nedelji() {
  const string DAY[] = {"Ned", "Pon", "Uto", "Sre", "Cet", "Pet", "Sub"};
  time_t rawtime;
  tm * timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  int wday = timeinfo->tm_wday;
  return wday;
}

void danasnjaAkcija(Kafic& kafic) {
  switch (dan_u_nedelji()) {
    case 4:
      kafic.setAkcija("Kafa + limunada = 119 RSD");
    break;
    case 5:
      kafic.setAkcija("Kola + espreso = 179 RSD");
    break;
    case 2:
      kafic.setAkcija("Studentska kafa = 39 RSD");
    break;
  }
}


int main() {
  Kafic kafic1("Kafic", "Renesansa", "Kralja Aleksandra I Karadjordjevica");
  danasnjaAkcija(kafic1);
  Kafic kafic2("Kafic", "Bridge", "Suboticeva BB");
  kafic2.setAkcija("Espreso + Kola = 149 RSD");
  Kafic kafic3("Kafic", "Ultra Caffe", "Aviv Park");
  kafic3.setAkcija("1. Kafa = 30 RSD \n2. Espreso = 60 RSD \n3. Kola = 80 RSD");
  Pub pub1("Pub", "Lion", "Bulevar oslobodjenja BB", "Njuske", "Erdinger 199 RSD");
  Pub pub2("Pub", "London", "Gimnazijska", "Vatrene kise", "Zajecarsko 100 RSD");
  Pub pub3("Pub", "Zlatna krigla", "Koce Kolarova", "/", "Hobogoblin pivo 289 RSD");
  int izbor;
  izborLokala(&izbor);
  switch(izbor) {
    case 1:
      izborKafica(&izbor);
      switch(izbor) {
        case 1:
          cout << kafic1.getVrstaKafica() << " " << kafic1.getImeKafica() << endl;
          cout << kafic1.getAdresaKafica() << endl;
          cout << "Danas je na akciji: " << endl << kafic1.getAkcija() << endl;
        break;
        case 2:
          cout << kafic2.getVrstaKafica() << " " << kafic2.getImeKafica() << endl;
          cout << kafic2.getAdresaKafica() << endl;
          cout << "Danas je na akciji: " << endl << kafic2.getAkcija() << endl;
        break;
        case 3:
          cout << kafic3.getVrstaKafica() << " " << kafic3.getImeKafica() << endl;
          cout << kafic3.getAdresaKafica() << endl;
          cout << "Happy Hour od 16h do 18h: " << endl << kafic3.getAkcija() << endl;
        break;
        case 0:
          cout << "Hvala sto ste koristili nasu aplikaciju!" << endl;
        return 0;
        default:
          cout << "Pogresan izbor" << endl;
        return 0;
      }
    break;
    case 2:
      izborPuba(&izbor);
      switch(izbor) {
        case 1:
          cout << pub1.getImePuba() << " " << pub1.getVrstaPuba() << endl;
          cout << pub1.getAdresaPuba() << endl;
          cout << "Veceras nastupa bend: " << endl << pub1.getBend() << endl;
          cout << "Vecerasnja promocija: " << endl << pub1.getPromocija() << endl;
        break;
        case 2:
          cout << pub2.getImePuba() << " " << pub2.getVrstaPuba() << endl;
          cout << pub2.getAdresaPuba() << endl;
          cout << "Veceras nastupa bend: " << endl << pub2.getBend() << endl;
          cout << "Vecerasnja promocija: " << endl << pub1.getPromocija() << endl;
        break;
        case 3:
          cout << pub3.getImePuba() << " " << pub3.getVrstaPuba() << endl;
          cout << pub3.getAdresaPuba() << endl;
          cout << "Veceras nastupa bend: " << endl << pub3.getBend() << endl;
          cout << "Vecerasnja promocija: " << endl << pub3.getPromocija() << endl;
        break;
        case 0:
          cout << "Hvala sto ste koristili nasu aplikaciju!" << endl;
        return 0;
        default:
          cout << "Pogresan izbor" << endl;
        return 0;
      }
    break;
    case 3:
      izborKluba(&izbor);
    break;
    case 4:
      izborKafane(&izbor);
    break;
    case 0:
      cout << "Hvala sto ste koristili nasu aplikaciju!" << endl;
    return 0;
    default:
      cout << "Pogresan izbor" << endl;
    return 0;
  }
}
