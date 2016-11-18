#include <iostream>

using namespace std;

class Vojnik {
public:
	int i;
	bool ziv;
	Vojnik() {
		ziv = true;
	}
};

class Josiph {
   public:
      int k;
      Vojnik *niz;
      Josiph(int koliko) {
	     k = koliko;
	     niz = new Vojnik[k];
		 for (int i = 0; i < k; i++) {
			niz[i].i = i+1;
		 }
	  }
	  void ispis() {
		for (int i = 0; i < k; i++) {
			cout << "(" << niz[i].i << ", " << niz[i].ziv << ")" << endl;
		 }
	  }
};

int main() {
	int k;
	cout << "Koliko vojnika?: ";
	cin >> k;
	Josiph josiph(k);
	josiph.ispis();
}