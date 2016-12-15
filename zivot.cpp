#include<iostream>
#include "zivot.h"

using namespace std;

int zivot::mod(int a, int b) {
	return (a%b+b)%b;
}

zivot::zivot() {
  this->width = 10;
  this->height = 10;
  mapa = new char*[width];
  for(int i = 0; i < width; i++)
    mapa[i] = new char[height];
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      mapa[i][j] = PRAZNO;
    }
  }
}

zivot::zivot(int width, int height) {
  //TODO treba proveriti width i height < 0
  this->width = width;
  this->height = height;
  mapa = new char*[width];
  for(int i = 0; i < width; i++)
    mapa[i] = new char[height];
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
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
    for (int j = 0; j < height; j++) {
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
    for (int j = 0; j < height; j++) {
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
	return mapa[i][j];
}

void zivot::dodajDrvo(int i, int j) {
  //TODO ovde idu provere i i j > 0 i manje od widht height
  mapa[i][j] = DRVO;
}

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
    zivot z = zivot();
	cout << z;
	z.dodajDrvo(2, 2);
	cout << z;
	zivot p = zivot(z);
	cout << "ovo je p" << endl;
	cout << p;
	//TODO objasniti zasto vracamo pozaziva *this kod operator=
	zivot j = p = z;
	//hint da bi ovo j = p = z moglo da radi. Zbog cega?
	cout << "ovo je j" << endl;
	cout << j;
}