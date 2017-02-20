#ifndef FUNKCIJE_H
#define FUNKCIJE_H
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

string ucitajIzFajla(string &ispis, vector <int> &nizBrReci, int &brRecenica);

void spojiReciURecenice(string &ispis,
   vector <int> &nizBrReci,
   int &brRecenica,
   vector <string> &recenice);

void ispisNaEkran(vector <string> &recenice, int &brRecenica);

void upisReceniceUFajlRecPoRec(vector <int> &nizBrReci);

void iscitavanjeIzFajlaRecPoReC(vector <int> &nizBrReci);

int main_menu(int &izbor);

 /*void run( int (*f0)(int*), string (*f1)(string&, vector<int>&, int&),
  void (*f2)(string&, vector<int>&, int, vector<string>&),
  void (*f3)(vector<string>&, int), void (*f)(vector<int>&),
  void (*f4)(vector<int>&), void (*f5)(vector<int>&) );*/

int run(string ispis,
   vector <int> nizBrReci,
    int brRecenica,
    vector <string> recenice,
    int izbor);

#endif
