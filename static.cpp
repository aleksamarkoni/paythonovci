#include <iostream>
#include <string>

using namespace std;

class Osoba {
public:
   static int id_count; 
   Osoba() {
	ime = "";
	prezime = "";
	godine = 0;
	id = id_count++;
   }
   string ime;
   string prezime;
   int godine;
   int id;
};

int Osoba::id_count;

int main() {
  cout << Osoba::id_count << endl;
  Osoba a = Osoba();
  cout << a.id << " " << Osoba::id_count << " " << a.id_count << endl;
  Osoba b = Osoba();
  cout << b.id << " " << Osoba::id_count << " " << b.id_count << " a: " << a.id_count << endl;
  
}