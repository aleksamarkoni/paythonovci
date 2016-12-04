#include <iostream>

using namespace std;

class ElementListe {
	public:
	   int Vrednost;
	   ElementListe *Sledeci; 
};

class Lista {
	private:
	   ElementListe *_Pocetak;
	public:
	   void DodajNaPocetak(int n) {
		//pravimo novi elemnt
		ElementListe *novi = new ElementListe;
		
		novi->Vrednost = n;
		novi->Sledeci = _Pocetak;
		
		_Pocetak = novi;
	   }
	   void DodajNaKraj(int n) {
	    cout << "DodajNaKraj " << n <<  endl;
	   }
	   int Element(int i) {
	    ElementListe *p = _Pocetak;
		for (int j = 0; j < i; j++) {
			p = p->Sledeci;
		}
		return p->Vrednost;
	   }
};

int main() {
	Lista lista;
	for (int i = 0; i < 10; i++) {
		lista.DodajNaPocetak(i);
	}
	for (int i = 0; i < 10; i++) {
		cout << lista.Element(i) << endl;
	}
	
	//for (int i = 0; i < 10; i++) {
	//	lista.DodajNaKraj(i);
	//}
	//for (int i = 0; i < 10; i++) {
	//	lista.Element(i);
	//}
	
}