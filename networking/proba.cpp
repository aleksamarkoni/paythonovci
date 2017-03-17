#include <iostream>
#include "Korisnik.cpp"

using namespace std;

int main() {
  int niz[50];
  niz[0] = 4;
  niz[1] = 23;

  for (int i = 0; i < 2; i++) {

  }

  vector<int> nizvector(50);
  nizvector.push_back(4);
  nizvector.push_back(23);

  for (int i = 0; nizvector.size(); i++) {

  }

  char rec[20] = "ove je neka rec";
  char rec1[20];
  for (int i = 0; i < 16; i++) {
    rec1[i] = rec[i];
  }

  string recstring("ovo je neka rec");
  string rec1string(recstring);
  recstring.c_str();

  Korisnik pera(123, "pera");
  cout << pera << endl;
  cout << pera.getUsername() << endl;
  cout << pera.getUsername().c_str() << endl;
}
