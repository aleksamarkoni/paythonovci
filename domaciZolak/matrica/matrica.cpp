#include <iostream>
#include "matrica.h"

using namespace std;

Mat::Mat(int sirina, int duzina) {
  int br = 0;
  m = new int *[sirina];                   // alociranje memorije
    for (int i = 0; i < sirina; i++)
        m[i] = new int[duzina];
  for (int i = 0; i < sirina; i++) {       //popunjavanje niza
    for (int j = 0; j < duzina; j++) {
      br++;
      m[i][j] = br;
    }
  }
  this->sirina = sirina;
  this->duzina = duzina;
}

Mat::~Mat() {
  for( int i = 0 ; i < sirina ; i++ ) {
    delete [] m[i] ;
  }
  delete [] m ;
}

int Mat::srednjaVrednostDijagonale() {  //int jer nece drugacije...
  float srednjaVrednost = 0;
  int br = 0;
  if(this->sirina == this->duzina) {
    for (int i = 0; i < this->sirina; i++) {
      for (int j = 0; j < this->duzina; j++) {
        if(i == j) {
          cout << m[i][j];       // test za elemente matrice izbacuje 0 0 9 a treba da bude 1 5 9...
          srednjaVrednost += m[i][j];
          br++;                  // br se uvecava za svaki element u dijagonali
        }
      }
    }
  srednjaVrednost = srednjaVrednost / br;
  return srednjaVrednost;
  }
  else {
    return 0;
  }
}

int Mat::sumNaDijagonali() {
  int sum = 0;
  int br = 0;
  if(this->sirina == this->duzina) {
    for (int i = 0; i < this->sirina; i++) {
      for (int j = 0; j < this->duzina; j++) {
        if(i == j) {
          sum += m[i][j];
          br++;                  // br se uvecava za svaki element u dijagonali
        }
        else continue;
      }
    }
  return sum;
  }
  else {
    return 0;
  }
}


int Mat::sumNaSporednojDijagonali() {
  int sum = 0;
  int br = 0;
  if(this->sirina == this->duzina) {
    for (int i = 0; i < this->sirina; i++) {
      for (int j = 0; j < this->duzina; j++) {
        if((i+j) == (this->sirina-1)) {
          sum += m[i][j];
          br++;                  // br se uvecava za svaki element u dijagonali
        }
        else continue;
      }
    }
  return sum;
  }
  else {
    return 0;
  }
}



ostream &operator<<(ostream &out, Mat m) {
  for (int i = 0; i < m.sirina; i++) {
    for (int j = 0; j < m.duzina; j++)
      out << m.m[i][j] << " ";
      cout << endl;
  }
  return out;
}
