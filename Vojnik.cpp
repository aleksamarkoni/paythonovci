#include <iostream>
#include <stdlib.h>    

using namespace std;

class Vojnik {
protected:
	int poz;
	bool ziv;
public:
	Vojnik() {
		poz = 0;
		ziv = true;
	}
	
	Vojnik(int p) : poz(p), ziv(true) {}
	
	int getPoz() {
		return poz;
	}
	
	bool daLiJeZiz() {
		return ziv;
	}
	
	void setPoz(int poz) {
		this->poz = poz;
	}
	
	void setZiv(bool ziv) {
		this->ziv = ziv;
	}
	
	void ubijVojnika() {
		if (ziv) {
			ziv = false;
		} else {
			cout << "vojnik je vec mrtav" << endl;
		}
	}
	
	friend ostream &operator<<( ostream &output, const Vojnik &a ) {
		output << "(" << a.poz << "," << (a.ziv?"Ziv":"Mrtav") << ")";
		return output;
	}
};

class Sreckovic : public Vojnik {
public:
	Sreckovic() {
		poz = 0;
		ziv = true;
	}
	
	Sreckovic(int p) {
		poz = p;
		ziv = true;
	}
	void ubijVojnika() {
		srand (time(NULL));
		int iSecret = rand() % 100 + 1;
		if (ziv) {
			if (iSecret <= 10) {
				ziv = false;
				cout << "Vojnik je ubijen" << endl;
			} else {
				cout << "Sreckovic je preziveo" << endl;
			}
		} else {
			cout << "vojnik je vec mrtav" << endl;
		}
	}
};

class Glavonja : public Vojnik {
private:
   int brojZivota;
public:
	Glavonja() {
		poz = 0;
		ziv = true;
		brojZivota = 2;
	}
	
	Glavonja(int p) {
		poz = p;
		ziv = true;
		brojZivota = 2;
	}
	void ubijVojnika() {
		if (ziv) {
			brojZivota--;
			if (brojZivota == 0) {
				ziv = false;
				cout << "Vojnik je ubijen" << endl;
			} else {
				cout << "Glavonja zivi i ima jos " << brojZivota << " zivota" << endl;
			}
		} else {
			cout << "vojnik je vec mrtav" << endl;
		}
	}
};

// napraviti vojnika koji ima 3 zivota, i prilikom svakog ubistva ima 30 posto sanse da prezivi

int main() {
	Vojnik aca;
	cout << aca << endl;
	Vojnik babaLover(4);
	cout << babaLover << endl;
	cout << "Ubijam vojnika" << endl;
	babaLover.ubijVojnika();
	cout << babaLover << endl;
	
	Sreckovic nikola(5);
	cout << "Ubijam vojnika" << endl;
	nikola.ubijVojnika();
	cout << nikola << endl;
	
	Glavonja Dusan(10);
	cout << "Ubijam Glavonja" << endl;
	Dusan.ubijVojnika();
	cout << Dusan << endl;
	cout << "Ubijam Glavonju ponovo" << endl;
	Dusan.ubijVojnika();
	cout << Dusan << endl;
}