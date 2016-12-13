#include<iostream>
#include "putanja/Zivot.h"
#include "putanjapesic/Zivot.h"


using namespace std;

#define WIDTH 10
#define HEIGHT 10
#define PRAZNO '.'
#define DRVO 'X'

int mod(int a, int b);

void ispis(char mapa[WIDTH][HEIGHT]) {
	cout << endl;
	cout << "---------------------" << endl;
	cout << endl;
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			cout << mapa[i][j];
		}
		cout << endl;
	}
}

int brojSuseda(char mapa[WIDTH][HEIGHT],int i,int j) {
	int br = 0;
	int p, q;
	for (int k = -1; k <= 1; k++) {
		for (int t = -1; t <= 1; t++) {
			p = mod(i + k, WIDTH);
			q = mod(j + t, HEIGHT);
			//if (p < 0) {
			//  p = HEIGHT-1;
			//}
			//if (q < 0) {
			//  q = WIDTH-1;
			//}
			//if (p >= HEIGHT) {
			//  p = 0;
			//}
			//if (q > WIDTH) {
			//  q = 0;
			//}
			if (mapa[p][q] == DRVO)
				br++;
		}
	}
	if (mapa[i][j] == DRVO) {
		br--;
	}
	return br;
}

void Kopiranje(char mapa[WIDTH][HEIGHT], char sg[WIDTH][HEIGHT]);

void jedanKorak(char mapa[WIDTH][HEIGHT]) {
	char sg[WIDTH][HEIGHT];
	int bs = 0;
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (mapa[i][j] == PRAZNO) {
				bs = brojSuseda(mapa, i, j);
				sg[i][j] = mapa[i][j];
				if (bs == 3 && mapa[i][j] == PRAZNO) {
				  sg[i][j] = DRVO;
				}
			} else {
				  bs = brojSuseda(mapa, i, j);
				  if (bs < 2) {
						sg[i][j] = PRAZNO;
					}
					if (bs == 2 || bs == 3) {
						sg[i][j] = DRVO;
					}
					if (bs > 3) {
						sg[i][j] = PRAZNO;
					}
			 }
		}
	}
	ispis(sg);
	Kopiranje(mapa, sg);
}

void Kopiranje(char mapa[WIDTH][HEIGHT], char sg[WIDTH][HEIGHT]) {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			mapa[i][j] = sg[i][j];
    }
  }
}

void uNos(char mapa[WIDTH][HEIGHT]) {
	int n, i, j;
	cout << "Koliko zelite drva ?" << endl;
	cin >> n;
	while (n > 100) {
		cout << " Ne moze vise od 100 drveca, unesite ponovo." << endl;
		cin >> n;
	}
	for (int k = 0; k < n; k++) {
	  cout << "Unesite vrstu: " << endl;
		cin >> i;
		i -= 1;
		while (i < 0) {
			cout << "Ne moze broj 0, unesite ponovo vrstu" << endl;
			cin >> i;
			i -= 1;
		}
		cout << "Unesite kolonu: " << endl;
		cin >> j;
		j -= 1;
		while (j < 0) {
			cout << "Ne moze broj 0, unesite ponovo kolonu" << endl;
			cin >> j;
			j -= 1;
		}
		mapa[i][j] = DRVO;
	}
}

int main() {
	char mapa[WIDTH][HEIGHT];
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			mapa[i][j] = PRAZNO;
		}
	}
	//uNos(mapa);
	
	mapa[0][0] = DRVO;
	mapa[0][1] = DRVO;
	mapa[0][2] = DRVO;
	
	ispis(mapa);
	for (int i = 0, j = 4; i < 2; i++) {
		jedanKorak(mapa);
	}
	
	//int i = 9;
	//int j = 0;
	//i+1; // za ovaj slucaj treba
	//j-1; // za ovde treba 9
	//int rezi = mod(i+1, WIDTH);
	//int rezj = mod(j-1, HEIGHT);
	//cout << rezi << endl;
	//cout << rezj << endl;
	
	//Domaci 
	// 1) Imate klasu koja se zove Zivot()
	//    - private delu, ona treba da ima ovu mapu ovih slova
	//    - imacete podrazumevani konstruktor, koji pravi mapu 10x10
	//	  - imacete drugi konstruktor koji pravi mapu wxh, w duzina, h sirina, koja se zadaje kao parametri konstruktoru
	//	  - ovde treba koristiti dinamicku memoriju
	//    - sto se tice javnih metoda, potrebo je da ima samo sledeci, 
	//		Zivot z = Zivot();
	//      z.postaviDrvo(4, 4); ovde vodi racuna da su indeksi i i j dobri, to jest da nisu negativni i veci od w ili h respektivno	 	 
	//	- void similacija(int i, bool ssk = false); ona vrsi i koraka simulacije. ovde treba voditi racuna da je i >= 0, ova funkcija samo stampa mapu posle i koraka simulacije
	//       i nece vrsiti promenu orginalne konfigurcije.
	// 		 parametar ssk odredjuje da li stampamo sve korake ili samo poslednji
	//    - similacija(5, true);
	//    - overridovati << operator tako da moze da se istampa klasa Zivot, to jest njegova mapa.
	// primer koriscenja ovog programa:
	/*     	Zivot z = Zivot(5, 5);
			z.postaviDrvo(1, 1); // znaci ovo drvo ide na mapa[0][0]
			z.postaviDrvo(1, 2);
			z.postaviDrvo(1, 3);
			cout << z << endl; // kako izgleda trenutna mapa sa drvima
			z.similacija(1); // ovde treba da se ispise ona mapa kao u nasem primeru
			cout << z << endl; // ovde treba da dobijem pocetnu mapu, ne mapu posle jednog koraka
			z.simulacije(5);
			z.similacija(10);
			z.similacija(20);
			z.similacija(40, true);
	*/
	
	//pera(int, konver, prebac, filtir)
	//pera(int) {pera(int, false, false, false)}
	//pera(int, konver) {pera(int, konver, false, false)}
	//pera(int, kover, prea)
	slackeri::Zivot()
	using namespace babe;
	Zivot()
	z.dodajDrvo();
	z.dodajDrvo();
	z.dodajDrvo();
	z.dodajDrvo();
	z.dodajDrvo();
	using namespace slackeri;
	Zivot z = Zivot();
}

int mod(int a, int b)
{ return (a%b+b)%b; }