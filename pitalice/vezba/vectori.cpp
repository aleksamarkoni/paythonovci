#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "ucitavanjePitanja.h"

using namespace std;

istream& operator>>(istream& is, Pitanje& pitanje) {
  getline(is, pitanje.pitanje);
  return is;
  }

ostream& operator<<(ostream& out, Pitanje& pitanje) {
  out << pitanje.pitanje << endl;
  return out;
}

/*bool ucitajPocetakPitanja(inf) {
	char pitanje;
	inf >> pitanje;
	if (pitanje == '<') {
		return true;
	} else {
		return false;
	}
}*/

int main() {
vector<Pitanje> pitanje;
ifstream inf("21_fundamental_variable_types.txt");
 while (inf){
    Pitanje pitanje;
    inf >> pitanje;
    cout << pitanje;
    }
  return 0;
}
