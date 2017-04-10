#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class Korisnik;

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

  friend ostream& operator<<(ostream &out, Kanal &kanal);
};

vector<Kanal> kanali;

class Korisnik {
private:
  int sock;
  string username;
  int korisnikovKanal = -1;
public:
  Korisnik(int sock, string ime) {
    this->sock = sock;
    this->username = ime;
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

bool napusti_kanal(vector<Kanal> &kanali, Korisnik &user) {
  for (int i = 0; i < 2; ++i) {
       for (int j = 0; j < kanali[i].getKorisnici().size(); j++) {
            cout << " Username: " << i+1 << " "
            << kanali[i].getKorisnici()[j].getUsername() << " "
            << kanali[i].getKorisnici()[j].getSocket() << endl;
        }
    cout << kanali[i].getKorisnici().size() << endl;
    for (vector<Korisnik>::iterator it = kanali[i].getKorisnici().begin() ; it != kanali[i].getKorisnici().end(); ++it)
      cout << "\t" << *it;
      kanali[i].getKorisnici().erase(remove_if(kanali[i].getKorisnici().begin(), kanali[i].getKorisnici().end(),
      [&user](Korisnik &k) {
        cout << k.getSocket() << " " << user.getSocket() << endl;
        return k.getSocket() == user.getSocket();} ), kanali[i].getKorisnici().end() );
      cout << kanali[i].getKorisnici().size() << endl;
      for (vector<Korisnik>::iterator it = kanali[i].getKorisnici().begin() ; it != kanali[i].getKorisnici().end(); ++it)
        cout << "\t" << *it;
    }
  }

    /*  if(kanali[j].getKorisnici()[k]->getSocket() == user.getSocket()) {
        //delete kanali[j].getKorisnici()[k];
        cout << "Pokusaj brisanja" << endl;
        cout << "user.getSocket: "<< user.getSocket() << endl;
        cout << "k: " << k << endl;
        cout << "j: " << j << endl;
    //    (kanali[j].getKorisnici()).erase(kanali[j].getKorisnici().begin() + k);
        kanali[j].getKorisnici().erase(remove(kanali[j].getKorisnici().begin(),
        kanali[j].getKorisnici().end(), k), kanali[j].getKorisnici().end());
        cout << "Obrisao: " << endl;
        //cout << "Korisnik: " << kanali[j].getKorisnici()[k].getUsername() <<
        //" je napustio " << kanali[j] << endl;
      }
    }
  }
}

*/


//vec.erase(std::remove(vec.begin(), vec.end(), 8), vec.end());
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
if(napusti_kanal(kanali, *k1)) {
  cout << "removed" << endl;
}

for (int i = 0; i < 2; ++i) {
   for (int j = 0; j < kanali[i].getKorisnici().size(); j++) {
        cout << " Username: " << i+1 << " "
        << kanali[i].getKorisnici()[j].getUsername() << " "
        << kanali[i].getKorisnici()[j].getSocket() << endl;
    }
 }
/*
  cout << "General: " << kanali[0].getKorisnici()[1]->getUsername() << endl;
  cout << "General: " << kanali[0].getKorisnici()[2]->getUsername() << endl;
  cout << "Programming: " << kanali[1].getKorisnici()[0]->getUsername() << endl;
  cout << "Programming: " << kanali[1].getKorisnici()[1]->getUsername() << endl;

  napusti_kanal(kanali, *k1);
  napusti_kanal(kanali, *k2);
  napusti_kanal(kanali, *k3);
  napusti_kanal(kanali, *k4);
  napusti_kanal(kanali, *k5);

  cout << "General: " << kanali[0].getKorisnici()[0]->getUsername() << endl;
  cout << "General: " << kanali[0].getKorisnici()[1]->getUsername() << endl;
  cout << "General: " << kanali[0].getKorisnici()[2]->getUsername() << endl;
  cout << "Programming: " << kanali[1].getKorisnici()[0]->getUsername() << endl;
  cout << "Programming: " << kanali[1].getKorisnici()[1]->getUsername() << endl;
*/
}
