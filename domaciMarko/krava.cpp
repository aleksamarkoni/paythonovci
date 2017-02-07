#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "krava.h"

using namespace std;

Krava::Krava() {
  brojKrava = (rand() % 10) + 1;
  dajeMleko = true;
}

int Krava::getBrojKrava() {
  return brojKrava;
}

bool Krava::ddajeMleko() {
  if (dajeMleko) {
    dajeMleko = true;
  } else {
    //  cout << "NeDajeMleko" << endl;
    }
}

bool Krava::neDajeMleko() {
  if (dajeMleko) {
    dajeMleko = false;
  } else {
  //  cout << "DajeMleko" << endl;
    }
  }

  int Krava::Milkica() {
    int litaraMleka = rand() % 50 + 1;
    if (ddajeMleko()) {
      if (litaraMleka <= 25) {
        neDajeMleko();
        //  cout << "Nije ispunila dnevnu normu dala je samo " << litaraMleka << endl;
      } else {
        //  cout << "Milkica je ispunila dnevnu normu dala je " << litaraMleka << endl;
      }
    }
    return litaraMleka;
  }

  int Krava::Belkica() {
    int litaraMleka = rand() % 50 + 1;
    if (ddajeMleko()) {
      if (litaraMleka <= 25) {
        neDajeMleko();
        //  cout << "Nije ispunila dnevnu normu dala je samo " << litaraMleka << endl;
      } else {
        //  cout << "Milkica je ispunila dnevnu normu dala je " << litaraMleka << endl;
      }
    }
    return litaraMleka;
  }
