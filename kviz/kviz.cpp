#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "kviz.h"

using namespace std;

int br = 0;

ostream& operator<<(ostream& out, vector<string>& kviz) {
  for(int i = 0; i < br; i++) {
    out << kviz[i] << endl; }
    return out;
}

void brojPitanja(ifstream& mojfajl) {
  string strInput;
  while(mojfajl) {
    getline(mojfajl, strInput);
    if(strInput == "<") {
      br++;
      continue;
    }
  }
}

void popunjavanjeVektora(vector<string>& kviz) {
ifstream mojfajl("/home/dusan/gits/paythonovci/pitalice/CHAPTER2_Variables_and_Fundamental_Data_Types/21_fundamental_variable_types.txt");
string strInput;
string jednoPitanje;
    int i = 0;
    bool isBegin = false;
    while(mojfajl) {
      getline(mojfajl, strInput);
        if("<" == strInput)
        {
            isBegin = true;
            continue;
        }
        else
            if(">" == strInput)
            {
                isBegin = false;
                kviz[i] = jednoPitanje;
                jednoPitanje = "";
                i++;
                continue;
            }
        if(isBegin) {
          jednoPitanje += strInput;
          jednoPitanje += "\n";
    }
  }
}

void ucitajSamoPitanje(vector<string>& kviz) {
  int i = rand() % 17 + 0;
  cout << "Pitanje broj " << i << " je:" << endl;
    string strInput;
    string penis;
    strInput = kviz[i];
    istringstream iss(strInput);
    getline(iss, penis);
      cout << penis << endl;
}

int main() {
  srand(time(NULL));
  Pitanje pitanje;
  ifstream mojfajl("/home/dusan/gits/paythonovci/pitalice/CHAPTER2_Variables_and_Fundamental_Data_Types/21_fundamental_variable_types.txt");
  brojPitanja(mojfajl);
  vector<string> kviz(br);
  cout << "Ukupan broj pitanja je " <<  br << "." << endl;
  popunjavanjeVektora(kviz);
  ucitajSamoPitanje(kviz);
  //cout << kviz;
}
