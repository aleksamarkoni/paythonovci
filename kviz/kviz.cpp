#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
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

int main() {
  Pitanje pitanje;
  ifstream mojfajl("/home/dusan/gits/paythonovci/pitalice/CHAPTER2_Variables_and_Fundamental_Data_Types/21_fundamental_variable_types.txt");
  brojPitanja(mojfajl);
  vector<string> kviz(br);
  cout << br << endl;
  popunjavanjeVektora(kviz);
  cout << kviz;
}
