#include "taksisti.h"

using namespace std;

/*ostream &operator<<(ostream &out, Taksisti &vozaci) {
  out << vozaci.getBrojVozaca(vozaci) << endl;
  return out;
}*/

//Taksisti &Taksisti::operator=(Taksisti &vozaci) {
//  int t;
 // setBrojVozaca(t, vozaci);
 // return vozaci;
//}


void Taksisti::setBrojVozaca(int t) {
  this->brojTaksista = t;
}

int Taksisti::getBrojVozaca() {
  return brojTaksista;
}
