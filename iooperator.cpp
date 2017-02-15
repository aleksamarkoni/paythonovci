#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Gost {
private:
  string ime;
  string prezime;
public:
  Gost(string ime, string prezime) {
    this->ime = ime;
    this->prezime = prezime;
  }

  friend ostream& operator <<(ostream& os, const Gost& g) {
    os << "<" << g.ime << " " << g.prezime << ">";
    return os;
  }
};

class Sto {
private:
  vector<Gost> gosti;
public:
  void dodajGosta(Gost g) {
    gosti.push_back(g);
  }
  friend ostream& operator <<(ostream& os, const Sto& sto) {
    for (int i = 0; i < sto.gosti.size(); i++) {
      os << sto.gosti[i] << ",";
    }
    return os;
  }
};

int main() {
  Gost g1("pera", "peric");
  Gost g2("zika", "zikic");
  //int operator +(int a, int b)
  //a + b + c
  Sto sto;
  sto.dodajGosta(g1);
  sto.dodajGosta(g2);

  cout << sto << endl;

}
