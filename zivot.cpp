#include<iostream>

using namespace std;

#define WIDTH 4
#define HEIGHT 4
#define PRAZNO '.'
#define DRVO 'X'

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
			p = i + k;
			q = j + t;
			if (p < 0) {
			  p = HEIGHT-1;
			}
			if (q < 0) {
			  q = WIDTH-1;
			}
			if (p > HEIGHT) {
			  p = 0;
			}
			if (q > WIDTH) {
			  q = 0;
			}
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
	uNos(mapa);
	ispis(mapa);
	for (int i = 0; i < 10; i++) {
	jedanKorak(mapa);
  }
}
