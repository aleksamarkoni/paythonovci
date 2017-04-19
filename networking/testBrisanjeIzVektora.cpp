#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class Kanal;

vector<Kanal> kanali;

class Korisnik {
private:
  int sock;
  string username;
  int korisnikovKanal;
public:
  Korisnik(int sock, string ime) {
    this->sock = sock;
    this->username = ime;
    korisnikovKanal = -1;
  }
  int getSocket() {
    return this->sock;
  }
  string getUsername() {
    return this->username;
  }
  int getKorisnikovKanal() {
    return this->korisnikovKanal;
  }

  friend ostream& operator<<(ostream &out, const Korisnik &user);

};

class IsOdd {
  Korisnik &zaBrisanje;

public:
  IsOdd(Korisnik &zaBrisanje) :
    zaBrisanje(zaBrisanje)
  {}

  bool operator()(Korisnik k) const {
    return k.getSocket() == zaBrisanje.getSocket();
  }
};

class Kanal {
private:
  string ime;
  vector<Korisnik> korisnici;
public:
  Kanal() {}
  Kanal(string imeKanala) {
    setKanal(imeKanala);
  }
  void setKanal(string imeKanala) {
    this->ime = imeKanala;
  }
  vector<Korisnik> getKorisnici() {
    return this->korisnici;
  }
  void dodajKorisnika(Korisnik &user) {
    korisnici.push_back(user);
  }

  void ukloniKorisnika(Korisnik &user) {
    korisnici.erase(
      remove_if(korisnici.begin(), korisnici.end(), IsOdd(user)),
      korisnici.end());
  }

  friend ostream& operator<<(ostream &out, Kanal &kanal);
};

ostream& operator<<(ostream &out, Korisnik &user) {
  out << user.getUsername() << endl;
  return out;
}

ostream& operator<<(ostream &out, Kanal &kanal) {
  out << kanal.ime << endl;
  for (int i = 0; i < kanal.korisnici.size(); i++) {
    out << kanal.korisnici[i] << endl;
  }
  return out;
}

void napusti_sve_kanale(vector<Kanal> &kanali, Korisnik &user) {
  for (int i = 0; i < 2; ++i) {
    kanali[i].ukloniKorisnika(user);
  }
}

int main() {
  string imeKanala;
  string ime;
  Kanal General("General");
  Kanal Programming("Programming");

  Korisnik *k1 = new Korisnik(1, "Dusan");
  Korisnik *k2 = new Korisnik(2, "Nikola");
  Korisnik *k3 = new Korisnik(3, "Marko");
  Korisnik *k4 = new Korisnik(4, "Pesic");
  Korisnik *k5 = new Korisnik(5, "Zolak");

  kanali.push_back(General);
  kanali.push_back(Programming);
  kanali[0].dodajKorisnika(*k1);
  kanali[0].dodajKorisnika(*k2);
  kanali[0].dodajKorisnika(*k3);
  kanali[1].dodajKorisnika(*k4);
  kanali[1].dodajKorisnika(*k5);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < kanali[i].getKorisnici().size(); j++) {
      cout << " Username: " << i+1 << " "
        << kanali[i].getKorisnici()[j].getUsername() << " "
        << kanali[i].getKorisnici()[j].getSocket() << endl;
    }
  }

  napusti_sve_kanale(kanali, *k1);

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < kanali[i].getKorisnici().size(); j++) {
      cout << " Username: " << i+1 << " "
        << kanali[i].getKorisnici()[j].getUsername() << " "
        << kanali[i].getKorisnici()[j].getSocket() << endl;
    }
  }
}
