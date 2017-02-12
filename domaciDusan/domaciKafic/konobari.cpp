#include "konobari.h"

using namespace std;

ostream& operator<<(ostream &out, Konobar &konobar) {
  out << "dnevnicu od " << konobar.dnevnica << " i "
   << konobar.baksis << " dinara baksisa";
   return out;
}

Konobar::Konobar() {
  dnevnica = 2000;
  int sansaZaBansis;
  sansaZaBansis = rand()% 100 + 1;
  if(sansaZaBansis <= 15) {
    baksis = rand()% 500 + 50;
  } else {
    baksis = 0;
  }
}

int Konobar::getBaksis() {
  return baksis;
}

int Konobar::getDnevnica() {
  return dnevnica;
}
