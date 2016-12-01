#include "Vojnik.h"
#include <stdlib.h>
#include "Sreckovic.h"
#include "Glavonja.h"
#include "VojnikGS.h"

void Vojnik::ubijVojnika(){
  ziv = false;
}
Vojnik::Vojnik() {
	ziv = true;
  }
int Vojnik::getPoz(){
  return poz;
  }
bool Vojnik::getZiv(){
  return ziv;
  }

void Vojnik::setPoz(int poz) {
  this->poz = poz;
  }

  void Vojnik::setZiv(bool ziv) {
  this->ziv = ziv;
  }
  ostream &operator<<( ostream &output, const Vojnik &a ) {
  	output << "(" << a.poz << "," << (a.ziv?"Ziv":"Mrtav") << ")";
  return output;
  }
