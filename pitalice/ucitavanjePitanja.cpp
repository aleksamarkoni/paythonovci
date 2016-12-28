#include <iostream>
#include <vector>
#include <fstream>
//#include <iomanip.h>
#include <string>
#include <cstdlib>

using namespace std;

class Pitanje {
private:
  string pitanje;
public:
  friend istream& operator>>(istream& is, Pitanje& pitanje);
  friend ostream& operator<<(ostream& out, Pitanje& pitanje);
  Pitanje() {}
  ~Pitanje() {}
};
class Odgovor {
private:
  string odgovor;
  bool tacan;
};
istream& operator>>(istream& is, Pitanje& pitanje) {
  getline(is, pitanje);
  is = pitanje;
  return is;
}

ostream& operator<<(ostream& out, Pitanje& pitanje) {
  out << pitanje << endl;
}

/*bool ucitajPocetakPitanja(fs) {
	char pitanje;
	fs >> pitanje;
	if (pitanje == '<') {
		return true;
	} else {
		return false;
	}
}*/

int main() {
//Pitanje pitanje;
vector<Pitanje> kviz;
ifstream inf("21fundamentalvariabletypes.txt");
 while (inf){
    Pitanje pitanje;
    inf >> pitanje;
    cout << pitanje;
    }
  return 0;
//cin.getline("/home/marko/gits/paythonovci/pitalice/21fundamentalvariabletypes.txt", kviz);
//cout << kviz << endl;
}
