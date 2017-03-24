#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

enum OPCIJE {
  LISTA_KANALA
};

OPCIJE prva_rec(string &line) {
  if(line == "/lista") {
    return LISTA_KANALA;
  }
  else exit(1);
}

void svi_kanali(string &line) {
  line = "General\nProgramming\nSex\nKolaci";
  cout << line << endl;
}

int main() {
  string line;
  OPCIJE opcije;
  bool running = true;
  while(running) {
    cin >> line;
    if(opcije = prva_rec(line));
    switch(opcije) {
      case LISTA_KANALA:
        svi_kanali(line);
      break;
    }
  }
}
