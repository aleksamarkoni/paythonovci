#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int main() {
  int brojRecenica, brojReci;
  string strInput, recenica;
  fstream myFile("input.txt");

  getline(myFile, strInput);
  istringstream ( strInput ) >> brojRecenica;
  int zbir = brojRecenica;
    cout << "Ukupan broj Recenica je : " << zbir << endl;

  vector<string> recenice(brojRecenica);
  for(int i = 0; i < brojRecenica; i++) {
  recenica = " ";
  getline(myFile, strInput);
  istringstream ( strInput ) >> brojReci;
    cout << "Broj Reci je : " << brojReci << endl;
    for (int j = 0; j < brojReci; j++) {
       getline(myFile, strInput);
       recenica += strInput;
       recenica += " ";
       cout << "Rec " << (j+1) << " je: " << strInput << endl;
    }
  recenice[i] = recenica;
}
  //  cout << "==== Jaooo moj ucitelju sta mi radis... ====" << endl;
  recenice.push_back(recenica);

  for (int i = 0; i < recenice.size(); i++) {
    cout << "Cela recenica " << (i+1) << " je: " << recenice[i] << endl;
  }
}
