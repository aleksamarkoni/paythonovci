#include "matrica.h"

using namespace std;

Matrica::Matrica(int duzinaMatrice, int sirinaMatrice) {
  this->duzinaMatrice = duzinaMatrice;
  this->sirinaMatrice = sirinaMatrice;
  pokazivac = new int*[duzinaMatrice];
  for (int i = 0; i < duzinaMatrice; i++) {
      pokazivac[i] = new int[sirinaMatrice];
  }
  popunjavanjeBrMatrice();
}

ostream &operator <<(ostream &out, Matrica &mat) {
  for (int i = 0; i < mat.duzinaMatrice; i++) {
    for (int j = 0; j < mat.sirinaMatrice; j++)
      out << mat.pokazivac[i][j] << " ";
    out << endl;
  }
  return out;
}

 int Matrica::popunjavanjeBrMatrice() {
   int br = 1;  // Da bi brojevi starovali od 1 umesto od 0.
   for (int i = 0; i < this->duzinaMatrice; i++) {
     for (int j = 0; j < this->sirinaMatrice; j++) {
       pokazivac[i][j] = br++;

     }
   }
 }

int Matrica::operator()(int duzinaMatrice, int sirinaMatrice) {
  return pokazivac[duzinaMatrice][sirinaMatrice];
}

int Matrica::getDuzinaMatrice() {
  return duzinaMatrice;
}
int Matrica::getSirinaMatrice() {
  return sirinaMatrice;
}
Matrica::~Matrica() {
  for (int i = 0; i < duzinaMatrice; i++) {
    delete [] pokazivac[i];
  }
    delete [] pokazivac;
}
