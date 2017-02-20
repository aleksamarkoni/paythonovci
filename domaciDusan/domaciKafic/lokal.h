#ifndef LOKAL_H
#define LOKAL_H
#include <iostream>
#include <vector>
#include "konobari.h"
#include "sto.h"
//#include "pice.h"

using namespace std;

class Lokal {
public: //lokal public

  class Kolektiv {
  private:
    int i;
    vector <Konobar> konobari;
    //vector <Pice> pice;
    //vector <Hrana> hrana;
    //vector <Muzika> muzika;
  public:
    Kolektiv();
    void generisiKonobare(Lokal &pivnica);
    void ispisKonobara(Lokal &pivnica);
    friend ostream& operator<<(ostream &out, Kolektiv &kolektiv);
  };

private: //lokal private
  int brojStolova;
  vector <Sto> stolovi;

public: //lokal public
  Kolektiv kolektiv;
  Lokal();
  int getBrojStolova();
  //Kolektiv getKolektiv();
  vector<Sto> getStolovi();
  void generisiStolove();
  void ispisStolova(Lokal &pivnica);
  int ukupanBrojGostiju(Lokal &pivnica);
  void ispisUkupnogBrojaGostiju(Lokal &pivnica);
  friend ostream& operator<<(ostream& out, Lokal &pivnica);
};

#endif
