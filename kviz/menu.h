#ifndef MENU_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void main_menu() {
  int izbor;
  cout << " _________________________________" << endl;
  cout << " |     DOBRODOSLI U KVIZ C++     |" << endl;
  cout << " | Izaberite oblast:             |" << endl;
  cout << " | 1) Fundamental variable types |" << endl;
  cout << " | 2) Void                       |" << endl;
  cout << " | 3) Variable sizes             |" << endl;
  cout << " | 4) Integers                   |" << endl;
  cout << " | 5) Floating point numbers     |" << endl;
  cout << " | 6) Boolean values             |" << endl;
  cout << " | 7) Exit                       |" << endl;
  cout << " _________________________________" << endl;
  cin >> izbor;
switch(izbor) {
  /*case 1:
  ifstream mojfajl("/home/nikola/gits/paythonovci/pitalice/CHAPTER2_Variables_and_Fundamental_Data_Types/21_fundamental_variable_types.txt");
  cout << mojfajl;
  break;
}*/}
#endif
