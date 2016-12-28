#include <iostream>
#include <vector>
#include <fstream>
//#include <iomanip.h>
#include <string>
#include <cstdlib>

using namespace std;

class Pitanje {
private:
  string Odgovor[];
  vector<Pitanje> pitanje;
public:
  Pitanje() {
  }
  ~Pitanje() {}
};
class Odgovor {
private:
  string odgovor;
  bool tacan;
};
friend istream& operator>>(istream& is, Pitanje& pitanje) {
        string line;
        getline(is, line);
        istringstream iss(line);
        getline(iss, assignment.pitanje);
        return is;
  }

bool ucitajPocetakPitanja(fs) {
	char pitanje;
	fs >> pitanje;
	if (pitanje == '<') {
		return true;
	} else {
		return false;
	}
}

int main() {
//Pitanje pitanje;
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
