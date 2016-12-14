#include<iostream>

using namespace std;

class zivot {
private:
	int width;
	int height;
	static const char prazno = '.';
	static const char drvo = 'X';
	int **mapa;
	zivot(const zivot &mapa) {
		int **mapa = new int*[width];
		for(int i = 0; i < width; i++)
		    mapa[i] = new int[height];
	}
  zivot() {
		width = 10;
		height = 10;
		int **mapa = new int*[width];
		for(int i = 0; i < width; i++)
		    mapa[i] = new int[height];
	}
  zivot(int w, int h) {
		int **mapa = new int*[w];
		for(int i = 0; i < w; i++)
		    mapa[i] = new int[h];
	}
  ~zivot();
public:

	int getwidth() {
		return width;
	}

	int getheight() {
		return height;
	}
   zivot mapa = zivot();
	 zivot mapa = zivot(int w, int h);
};

void simulacija(int bs, bool ssk = false) {
    if (bs >= 0) {
		  if (ssk == true) {
				for(int i = 0; i < bs; i++) {
					jedanKorak();
					cout << mapa << endl;
				}
			} else {
			    for(int i = 0; i < bs; i++) {
				    jedanKorak();
				  }
			    cout << mapa << endl;
			  }
		}
}

int mod(int a, int b) {
	return (a%b+b)%b;
}

ostream &operator<<(ostream &output, const zivot &mapa) {
	output << endl;
	output << "---------------------" << endl;
	output << endl;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			output << mapa[i][j];
		}
		output << endl;
	}
	return output;
}

int brojSuseda(char mapa[width][height],int i,int j) {
	int br = 0;
	int p, q;
	for (int k = -1; k <= 1; k++) {
		for (int t = -1; t <= 1; t++) {
			p = mod(i + k, width);
			q = mod(j + t, height);

			if (mapa[p][q] == drvo)
			br++;
		}
	}
	if (mapa[i][j] == drvo) {
		br--;
	}
	return br;
}

void Kopiranje(char mapa[width][height], char sg[width][height]);

void jedanKorak(char mapa[width][height]) {
	char sg[width][height];
	int bs = 0;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {	char drvo = 'X';

			if (mapa[i][j] == prazno) {
				bs = brojSuseda(mapa, i, j);
				sg[i][j] = mapa[i][j];
				if (bs == 3 && mapa[i][j] == prazno) {
					sg[i][j] = drvo;
				}
			} else {
				bs = brojSuseda(mapa, i, j);
				if (bs < 2) {
					sg[i][j] = prazno;
				}
				if (bs == 2 || bs == 3) {
					sg[i][j] = drvo;
				}
				if (bs > 3) {
					sg[i][j] = prazno;
				}
			}
		}
	}
	ispis(sg);
	Kopiranje(mapa, sg);
}

void Kopiranje(char mapa[width][height], char sg[width][height]) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			mapa[i][j] = sg[i][j];
		}
	}
}

void uNos(char mapa[width][height]) {
	int n, i, j, bs;
	cout << "Unesite broj simulacija" << endl;
	cin >> bs;
	cout << "Koliko zelite drva ?" << endl;
	cin >> n;
	while (n !> width*height) {
		cout << " Ne moze toliko drveca, unesite ponovo." << endl;
		cin >> n;
	}
	for (int k = 0; k < n; k++) {
		cout << "Unesite vrstu: " << endl;
		cin >> i;
		i -= 1;
		while (i < 0 && i !> width) {
			cout << "Ne moze broj 0, unesite ponovo vrstu" << endl;
			cin >> i;
			i -= 1;
		}
		cout << "Unesite kolonu: " << endl;
		cin >> j;
		j -= 1;
		while (j < 0 && !> height) {
			cout << "Ne moze broj 0, unesite ponovo kolonu" << endl;
			cin >> j;
			j -= 1;
		}
		mapa[i][j] = drvo;
	}
}

int main() {
	char mapa[width][height];
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			mapa[i][j] = prazno;
		}
	}
	uNos(mapa);
  mapa.simulacija(5, true);
	for (int i = 0, j = 4; i < 2; i++) {
		jedanKorak(mapa);
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
	//	- void simulacija(int i, bool ssk = false); ona vrsi i koraka simulacije. ovde treba voditi racuna da je i >= 0, ova funkcija samo stampa mapu posle i koraka simulacije
	//       i nece vrsiti promenu orginalne konfigurcije.
	// 		 parametar ssk odredjuje da li stampamo sve korake ili samo poslednji
	//    - simulacija(5, true);
	//    - overridovati << operator tako da moze da se istampa klasa Zivot, to jest njegova mapa.
	// primer koriscenja ovog programa:
	/*     	Zivot z = Zivot(5, 5);
	z.postaviDrvo(1, 1); // znaci ovo drvo ide na mapa[0][0]
	z.postaviDrvo(1, 2);
	z.postaviDrvo(1, 3);
	cout << z << endl; // kako izgleda trenutna mapa sa drvima
	z.simulacija(1); // ovde treba da se ispise ona mapa kao u nasem primeru
	cout << z << endl; // ovde treba da dobijem pocetnu mapu, ne mapu posle jednog koraka
	z.simulacije(5);
	z.simulacija(10);
	z.simulacija(20);
	z.simulacija(40, true);
	*/

	//pera(int, konver, prebac, filtir)
	//pera(int) {pera(int, false, false, false)}
	//pera(int, konver) {pera(int, konver, false, false)}
	//pera(int, kover, prea)

}
