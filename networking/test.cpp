#include <iostream>
#include <vector>


class Korisnik;

class Kanal {
public:
  string ime;
  vector <Korisnik> korisnici;
public:
  Kanal() {}
  Kanal(string imeKanala) {
    setKanal(imeKanala);
  }
};



void napusti_kanal(vector<Kanal> kanali, Korisnik &user) {
  for(int j = 0; j < i; j++) {
    for(int k = 0; k < i; k++)
    if(kanali[j].getKorisnici()[k].getSocket() == user.getSocket()) {
      kanali[j].getKorisnici().erase(kanali[j].getKorisnici().begin() + k);
      cout << "Korisnik: " << kanali[j].getKorisnici()[k].getUsername() <<
       " je napustio " << kanali[j] << endl;
    }
  }
}



int main() {


  
}
