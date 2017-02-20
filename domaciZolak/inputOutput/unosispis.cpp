#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string recenica;
  int brojReci = 0;
  int br = 0;
  cout << "Unesite recenicu: " << endl;
  getline(cin, recenica);
  for (int i = 0; i < recenica.length(); i++) {
    if (recenica[i] == ' ')
      brojReci++;
    }
  string rec[brojReci+1];
  for (int i = 0; i < recenica.length(); i++) {
    if (recenica[i] == ' ')
      br++;
    else
      rec[br] += recenica[i];
  }
  for (int i = 0; i <= br; i++) {
    cout << rec[i] << endl;
  }
}
