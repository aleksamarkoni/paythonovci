#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <typeinfo>

using namespace std;

string ucitajIzFajla(string &ispis, vector <int> &nizBrReci, int *brRecenica) {
  int brReci;
  fstream mojfajl;
  string myfile;
  string pomocni;
  myfile = "./../../domaciDusan/domaciUpisIspis/input.txt";
  mojfajl.open((myfile).c_str());
  getline(mojfajl, pomocni);
  istringstream (pomocni) >> *brRecenica;
  //cout << typeid(brRecenica).name() << endl;
  //cout << brRecenica << endl << endl;
  while(mojfajl) {
    getline(mojfajl, myfile);
    if(isdigit(myfile[0])) {
      istringstream (myfile) >> brReci;
        nizBrReci.push_back(brReci);
        continue;
        //cout << brReci << endl;
    }
    ispis += myfile;
    ispis += "\n";
  }
  return ispis;
}

void spojiReciURecenice(string ispis,
   vector <int> &nizBrReci,
   int brRecenica,
   vector <string> &recenice) {

  istringstream iss(ispis);
  //cout << ispis << endl;
  string myfile;
  string recenica;
  int brIteracija = 0;
  int krug = 0;
  int m = 0;
  int k = nizBrReci[m];
  for(int i = 0; i < brRecenica;) {
    for(int j = 0; j < k; j++) {
        getline(iss, myfile);
        //cout << myfile << endl;
        recenica += myfile;
        recenica += " ";
        brIteracija++;
        if(j == k-1) {
          recenice.push_back(recenica);
          recenica = "";
          break;
        }
    }
    i++;
    //cout << "krug: " << krug << endl;
    //cout << "k: " << k << endl;
    //cout << "m: " << m << endl;
    //cout << "broj iteracija je: " << brIteracija << endl;
    //cout << endl << endl << endl;
    m = i;
    k = nizBrReci[m];
    brIteracija = 0;
    krug++;
  }
}

void ispisNaEkran(vector <string> &recenice, int brRecenica) {
  for(int i = 0; i < brRecenica; i++) {
    cout << recenice[i] << endl;
  }
  cout << endl;
}

void upisReceniceUFajlRecPoRec() {
  string recenica;
  string rec;
  char c;
  cout << "Unesite recenicu za rastavljanje na reci." << endl;
  getline(cin, recenica);
  //cout << recenica << endl;
  ofstream out("./../../domaciDusan/domaciUpisIspis/razbijanjeRecenice.txt");
  for(int i = 0; i < recenica.length(); i++) {
    if(!isspace(recenica[i])) {
      rec += recenica[i];
    }
    if(isspace(recenica[i])) {
      rec += "\n";
    }
  }
  out << rec;
  out.close();
}

void iscitavanjeIzFajlaRecPoReC() {
  string line;
  ifstream myfile("./../../domaciDusan/domaciUpisIspis/razbijanjeRecenice.txt");
  cout << endl;
    while(myfile.good()) {
      getline(myfile, line);
      cout << line << endl;
    }
    myfile.close();
}

int main() {
  vector <int> nizBrReci;
  vector <string> recenice;
  int brRecenica;
  int izbor = 0;
  int answer;
  string ispis;
  ucitajIzFajla(ispis, nizBrReci, &brRecenica);
  spojiReciURecenice(ispis, nizBrReci, brRecenica, recenice);
  ispisNaEkran(recenice, brRecenica);
  upisReceniceUFajlRecPoRec();
  iscitavanjeIzFajlaRecPoReC();
}
