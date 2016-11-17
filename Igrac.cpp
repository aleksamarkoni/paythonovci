#include <iostream>
#include "Tacka.h"
#include "Item.cpp"

using namespace std;

class Igrac {
private:
  Tacka poz;
  int brItema;
  int velicinaNiza;
  int kolikoMozeDaNosi;
  Item *itemi;
public:
	Igrac(int x, int y) {
		Tacka g(x, y);
		poz = g; // ovde smo se provukli
		brItema = 0;
		velicinaNiza = 5;
		itemi = new Item[velicinaNiza];
		kolikoMozeDaNosi = 200;
	}
	void dodajItem(Item item) {
		if (kolikoNosiTrenutno() + item.getTezina() > kolikoMozeDaNosi) {
			cout << "Ne moze da nosi ovaj item jer je pretezak" << endl;
		} else {
			if (brItema >= velicinaNiza) {
				cout << "prosirujem niz sa " << velicinaNiza << " na " << 2*velicinaNiza << endl;
				velicinaNiza *= 2;
				Item *p = new Item[velicinaNiza];
				for (int i = 0; i < brItema; i++) {
					p[i] = itemi[i];
				}
				delete [] itemi;
				itemi = p;
			}
			itemi[brItema] = item;
			brItema++;
		}
	}
	int kolikoNosiTrenutno() {
		int sum = 0;
		for (int i =0; i < brItema; i++) {
			sum = sum + itemi[i].getTezina();
		}
		return sum;
	}
	int kolikoImasItema() {
		return brItema;
	}
	
	//igram ima {koliko ima itema}, koliko nosi {kolicna} 
	//for (int i = 0; i < brItema; i++) {
	//	outstream << itemi[i];
	//}
	//
	
	~Igrac() {
		delete [] itemi;
	}
};

int main() {
	Item sekira(10, 20);
	Item cvet(11, 1);
	Item balvan(12, 180);
	Igrac pera(5, 5);
	cout << "dadajem iteme" << endl;
	pera.dodajItem(sekira);
	pera.dodajItem(cvet);
	pera.dodajItem(balvan);
	for (int i = 0; i < 20; i++) {
		pera.dodajItem(cvet);
	}
	(cout << "kraj dodavanja, pera ima: ") << pera.kolikoImasItema() << endl;
	cout << "Item sekira: " << sekira << endl;
}