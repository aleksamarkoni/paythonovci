#include<iostream>
#include "zivot.h"

using namespace std;

int mod(int a, int b) {
	return (a%b+b)%b;
}

zivot& zivot::operator=(const zivot &mapa) {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      mapa[i][j] = PRAZNO;
    }
  }
  return *this;
}

void zivot::setWidth(int width1) {
	width = width1;
}

void zivot::setHeight(int height1) {
	height = height1;
}

zivot::zivot() {
	width = 10;
	height = 10;
  mapa = PRAZNO;
}
zivot::~zivot() {
	for(int i = 0; i < height; i++) {
    delete [] mapa[i];
  }
delete [] mapa;
}

zivot::zivot(int width, int height) {
  mapa = new char*[width];
	for(int i = 0; i < width; i++)
		mapa[i] = new char[height];
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        mapa[i][j] = PRAZNO;
    }
  }
}
zivot(const zivot& matrica) {
	width = matrica.width;
	height = matrica.height;
}

/*
ostream &operator<<(ostream &output, &mapa) {
	cout << endl;
	cout << "---------------------" << endl;
	cout << endl;
			cout << mapa << endl;
}
*/
int zivot::brojSuseda(zivot **mapa, int i, int j) {
	int br = 0;
	int p, q;
	for (int k = -1; k <= 1; k++) {
		for (int t = -1; t <= 1; t++) {
			p = mod(i + k, width);
			q = mod(j + t, height);
			if (mapa[p][q] == DRVO)
				br++;
		}
	}
	if (mapa[i][j] == DRVO) {
		br--;
	}
	return br;
}

void zivot::jedanKorak(zivot **mapa) {
	zivot **sg;
	int bs = 0;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
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
	cout << sg << endl;
	Kopiranje(mapa, sg);
}

void zivot::Kopiranje(zivot **mapa, zivot **sg) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			mapa[i][j] = sg[i][j];
    }
  }
}

void zivot::velicinaMape() {
	int width1, height1;
	cout << "Unesite sirinu mape." << endl;
	cin >> width1;
	cout << "Unesite visinu mape." << endl;
	cin >> height1;
	zivot::setWidth(width1);
	zivot::setHeight(height1);
}

void zivot::uNos(zivot **mapa) {
	int n, i, j, brSimulacija;
	cout << "Koliko zelite drva?" << endl;
	cin >> n;
	while (n > width*height) {
		cout << " Ne moze toliko drveca, unesite ponovo." << endl;
		cin >> n;
	}
	for (int k = 0; k < n; k++) {
		cout << "Unesite vrstu:" << endl;
		cin >> i;
		i -= 1;
		while (i < 0 && i > width) {
			cout << "Ne moze broj 0 i broj veci od vrste, unesite ponovo vrstu." << endl;
			cin >> i;
			i -= 1;
		}
		cout << "Unesite kolonu:" << endl;
		cin >> j;
		j -= 1;
		while (j < 0 && j > height) {
			cout << "Ne moze broj 0 i broj veci od kolone, unesite ponovo kolonu." << endl;
			cin >> j;
			j -= 1;
		}
		mapa[i][j] = DRVO;
	}
	cout << "Unesite broj simulacija" << endl;
	cin >> brSimulacija;
}

void zivot::simulacija(int brSimulacija, bool ssk = false, zivot **mapa) {
    if (brSimulacija >= 0) {
		  if (ssk == true) {
				for(int i = 0; i < brSimulacija; i++) {
					zivot::jedanKorak(mapa);
					cout << mapa << endl;
				}
			} else {
			    for(int i = 0; i < brSimulacija; i++) {
				    zivot::jedanKorak(mapa);
				  }
			    cout << mapa << endl;
			  }
		}
}

void zivot::praznaMapa(zivot **mapa) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			mapa[i][j] = PRAZNO;
		}
	}
}

int main() {
	zivot::velicinaMape();
  //zivot mapa = zivot();

	zivot::praznaMapa(mapa);
	zivot::uNos(mapa);
  zivot::simulacija(brSimulacija, ssk, mapa);
	}

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
			z.postaviDrvo(1, 1); // znaci ovo DRVO ide na mapa[0][0]
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
	/*slackeri::Zivot()
	using namespace babe;
	Zivot()
	z.dodajDrvo();
	z.dodajDrvo();
	z.dodajDrvo();
	z.dodajDrvo();
	z.dodajDrvo();
	using namespace slackeri;
	Zivot z = Zivot();*/
