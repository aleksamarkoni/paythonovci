#include<iostream>
#include "zivot.h"

using namespace std;

int zivot::mod(int a, int b) {
	return (a%b+b)%b;
}

void Unos(int *width, int *height) {
  *width = 0;
  *height = 0;
  cout << "Unesite sirinu mape:" << endl;
  cin >> *width;
  while ( *width <= 0 || *width > 100) {
    cout << "Unos je izvan opsega, unesite ponovo sirinu mape:" << endl;
    cin >> *width;
  }
  cout << "Unesite visinu mape:" << endl;
  cin >> *height;
  while ( *height <= 0 || *height > 100) {
    cout << "Unos je izvan opsega, unesite ponovo sirinu mape:" << endl;
    cin >> *height;

  }
}

zivot::zivot() {
  this->width = 10;
  this->height = 10;
  mapa = new char*[width];
  for(int i = 0; i < width; i++)
    mapa[i] = new char[height];
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      mapa[i][j] = PRAZNO;
    }
  }
}

zivot::zivot(int width, int height) {
  //TODO treba proveriti width i height < 0
  if ( width < 0 || height < 0 ) {
    cout << "Ne valja" << endl;
    Unos(&width, &height);
  }
  this->width = width;
  this->height = height;
  mapa = new char*[width];
  for(int i = 0; i < width; i++)
    mapa[i] = new char[height];
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      mapa[i][j] = PRAZNO;
    }
  }
}

zivot::zivot(const zivot& o) {
  this->width = o.getWidth();
  this->height = o.getHeight();
  mapa = new char*[width];
  for(int i = 0; i < width; i++)
    mapa[i] = new char[height];
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      mapa[i][j] = o.dajPolje(i, j);
    }
  }
}

zivot& zivot::operator=(const zivot &o) {
  this->width = o.getWidth();
  this->height = o.getHeight();
  mapa = new char*[width];
  for(int i = 0; i < width; i++)
    mapa[i] = new char[height];
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      mapa[i][j] = o.dajPolje(i, j);
    }
  }
  //TODO objasniti ovo
  return *this;
}

zivot::~zivot() {
  for(int i = 0; i < width; i++) {
    delete [] mapa[i];
  }
  delete [] mapa;
}

int zivot::getWidth() const {
  return width;
}

int zivot::getHeight() const {
  return height;
}

char zivot::dajPolje(int i, int j) const {
	//TODO proveriti da li su i i j u opsezima
  if ( i < 0 || i > width ) {
    cout << "Error!" << endl;
  }
  if ( j < 0 || j > height ) {
    cout << "Error!" << endl;
  }
	return mapa[i][j];
}

void zivot::dodajDrvo() {
  //TODO ovde idu provere i i j > 0 i manje od width height
  int i, j, brDrva, k;
  cout << "Koliko drva zelite da unesete?" << endl;
  cin >> brDrva;
  while ( brDrva > width*height) {
    cout << "Nema mesta na mapi." << endl;
    cin >> brDrva;
  }
  for ( k = 0; k < brDrva; k++ ) {
    cout << "Unesite koordinate drveta." << endl;
    cin >> i;
    if ( i < 0 || i > width ) {
      cout << "Ne moze van mape." << endl;
      cin >> i;
    }
    cin >> j;
    if ( j < 0 || j > height ) {
      cout << "Ne moze van mape." << endl;
      cin >> j;
    }
  mapa[i][j] = DRVO;
  }
}

ostream& operator <<(ostream& out,const zivot &z) {
  out << "--------------" << endl;
  for (int i = 0; i < z.width; i++) {
    for (int j = 0; j < z.height; j++) {
      cout << z.mapa[i][j];
    }
  cout << endl;
  }
}

int zivot::brojSuseda(int i, int j) {
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

/*void Kopiranje(char sg[width][height], int width, int height) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			mapa[i][j] = sg[i][j];
		}
	}
}*/

bool zivot::SetSim() {
	this->ssk = true;
}

void zivot::simulacija(int brSimulacija, bool ssk = false) {
	zivot kopija = zivot(*this);
	zivot pom = zivot(width, height);
	int bs = 0;
	for (int k = 0; k < brSimulacija; k++) {
	  for (int i = 0; i < width; i++) {
		  for (int j = 0; j < height; j++) {
        if (kopija.mapa[i][j] == PRAZNO) {
			  bs = brojSuseda(i, j);
			  pom.mapa[i][j] = kopija.mapa[i][j];
			  if (bs == 3 && kopija.mapa[i][j] == PRAZNO) {
				  pom.mapa[i][j] = DRVO;
			  }
		  } else {
			  bs = brojSuseda(i, j);
			  if (bs < 2) {
				  pom.mapa[i][j] = PRAZNO;
			  }
			  if (bs == 2 || bs == 3) {
				  pom.mapa[i][j] = DRVO;
			  }
			  if (bs > 3) {
				  pom.mapa[i][j] = PRAZNO;
			  }
	  	}
	  }
  }
	if (ssk == true) {
		cout << pom;
	}
}
	kopija = pom;
if (ssk == false) {
	cout << kopija;
}
}

/*void zivot::simulacija(int brSimulacija, bool ssk = false) {
	zivot pom;
	zivot kopija;
  for (int k = 0; k < brSimulacija; k++) {
      jedanKorak(width, height);
    if (ssk == true) {
      cout << pom;
		}
  }
    kopija = pom;
if (ssk == false) {
    cout << kopija;
  }
}*/

int main() {
  //zivot::velicinaMape();
  //zivot mapa = zivot();

  //zivot::praznaMapa(mapa);
  //zivot::uNos(mapa);
  //zivot::simulacija(brSimulacija, ssk, mapa);
  //}

	//Domaci
	// 1) Imate klasu koja se zove Zivot()
	//    - private delu, ona treba da ima ovu mapu ovih slova
	//    - imacete podrazumevani konstruktor, koji pravi mapu 10x10
	//	  - imacete drugi konstruktor koji pravi mapu wxh, w duzina, h sirina, koja se zadaje kao parametri konstruktoru
	//	  - ovde treba koristiti dinamicku memoriju
	//    - sto se tice javnih metoda, potrebo je da ima samo sledeci,
	//		Zivot z = Zivot();
	//      z.postaviDRVO(4, 4); ovde vodi racuna da su indeksi i i j dobri, to jest da nisu negativni i veci od w ili h respektivno
	//	- void similacija(int i, bool ssk = false); ona vrsi i koraka simulacije. ovde treba voditi racuna da je i >= 0, ova funkcija samo stampa mapu posle i koraka simulacije
	//       i nece vrsiti promenu orginalne konfigurcije.
	// 		 parametar ssk odredjuje da li stampamo sve korake ili samo poslednji
	//    - similacija(5, true);
	//    - overridovati << operator tako da moze da se istampa klasa Zivot, to jest njegova mapa.
	// primer koriscenja ovog programa:
	/*     	Zivot z = Zivot(5, 5);
			z.postaviDRVO(1, 1); // znaci ovo DRVO ide na mapa[0][0]
			z.postaviDRVO(1, 2);
			z.postaviDRVO(1, 3);
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
	z.dodajDRVO();
	z.dodajDRVO();
	z.dodajDRVO();
	z.dodajDRVO();
	z.dodajDRVO();
	using namespace slackeri;
	Zivot z = Zivot();*/
  /*zivot z = zivot();
	cout << z;
	z.dodajDRVO(2, 2);
	cout << z;
	zivot p = zivot(z);
	cout << "ovo je p" << endl;
	cout << p;
	//TODO objasniti zasto vracamo pozaziva *this kod operator=
	zivot j = p = z;
	//hint da bi ovo j = p = z moglo da radi. Zbog cega?
	cout << "ovo je j" << endl;
	cout << j;*/
  int width, height;
  Unos(&width, &height);
  zivot h = zivot(width, height);
  h.dodajDrvo();
	int brSimulacija = 5;
	h.SetSim();
  h.simulacija(brSimulacija, true);
  //Unos(&width, &height);
  //zivot p = zivot(width,height);
  cout << h;
}
