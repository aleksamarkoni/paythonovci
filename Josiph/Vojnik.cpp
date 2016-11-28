#include "Vojnik.h"

void Vojnik::ubijVojnika(){
  ziv = false;
}
Vojnik::Vojnik() {
	ziv = true;
  }
int Vojnik::getPoz() {
  return poz;
  }
bool Vojnik::getZiv() {
  return ziv;
  }
