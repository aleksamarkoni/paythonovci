#include <string>
#include <iostream>

using namespace std;

class Korisnik {
private:
  int sock;
  string username;
public:
  Korisnik() {}
  Korisnik(int sock, string username) {
    this->sock = sock;
    this->username = username;
  }

  int getSocket() {
    return sock;
  }
  
  string getUsername() {
    return username;
  }

  friend ostream& operator<<(ostream &out, const Korisnik &user);
};

ostream& operator<<(ostream &out, const Korisnik &user) {
  out << user.sock << " " << user.username << endl;
  return out;
}
