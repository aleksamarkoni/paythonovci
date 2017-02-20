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
  vector<string> recenice(brojRecenica);
  for(int i = 0; i < brojRecenica; i++) {
    recenica = " ";
    getline(myFile, strInput);
    istringstream ( strInput ) >> brojReci;
    for (int j = 0; j < brojReci; j++) {
       getline(myFile, strInput);
       recenica += strInput;
       recenica += " ";
    }
    recenice[i] = recenica;
  }
  for (int i = 0; i < recenice.size(); i++)
    cout << "Cela recenica " << (i+1) << " je: " << recenice[i] << endl;
}
