#include <iostream>
#include <string>
#include "lokal.h"
#include "kafic.h"

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

int main() {
  Lokal kafic1("Kafic", "Renesansa", "Kralja Aleksandra I Karadjordjevica");
  Lokal kafic2("Kafic", "Bridge", "Suboticeva BB");
  int izbor;
  izborLokala(&izbor);
  switch(izbor) {
    case 1:
      izborKafica(&izbor);
      switch(izbor) {
        case 1:
          cout << kafic1.getVrsta() << " " << kafic1.getIme() << endl;
          cout << kafic1.getAdresa() << endl;
          //cout << kafic1.akcija("proba") << endl;
        break;
        case 2:
          cout << kafic2.getVrsta() << " " << kafic2.getIme() << endl;
          cout << kafic2.getAdresa() << endl;
        break;
        case 3:
          //ispisInformacija();
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
