#include <iostream>

using namespace std;

class Pravougaonik {
public:
    int x;
    int y;
    int sirina;
    int duzina;
public:
    Pravougaonik() {
		this->x = 0;
		this->y = 0;
		this->sirina = 0;
		this->duzina = 0;
	}
	
	int povrsina() {
	   return sirina*duzina;
    }
	
    int obim() {
	   return 2*(sirina + duzina);
	}
};

int main() {
	Pravougaonik p;
	Pravougaonik *pp;
	cout << p.x << " " << p.y << " " << p.sirina << " " << p.duzina << endl;
	cout << "Adresa pravougaonika: " << (&p) << endl;
	cout << "Adreas pokazivaca pp: " << (&pp) << " vrednost u pp: " << pp << endl;
	pp = &p;
	cout << "Adresa pravougaonika: " << (&p) << endl;
	cout << "Adreas pokazivaca pp: " << (&pp) << " vrednost u pp: " << pp << endl;
	cout << pp->x << " " << (*pp).y << " " << pp->sirina << " " << pp->duzina << endl;
	pp->x = 13;
	cout << pp->x << " " << (*pp).y << " " << pp->sirina << " " << pp->duzina << endl;
}