#include<iostream>

using namespace std;

#define WIDTH 10
#define HEIGHT 10
#define PRAZNO '.'
#define DRVO 'X'

void ispis(char mapa[WIDTH][HEIGHT]) {
	cout << endl;
	cout << "---------------------" << endl;
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			cout << mapa[i][j];
		}
		cout << endl;
	}
}

int brojSuseda(char mapa[WIDTH][HEIGHT],int i,int j) {
	int br = 0;
	for (int k = -1; k <= 1; k++) {
		for (int t = -1; t <= 1; t++) {
			if (mapa[i+k][j+t] == DRVO)
				br++;
		}
	}
	if (mapa[i][j] == DRVO) {
		br--;
	}
	return br;
}

void jednaKorak(char mapa[WIDTH][HEIGHT]) {
	char sg[WIDTH][HEIGHT];
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (mapa[i][j] == PRAZNO) {
				sg[i][j] = mapa[i][j];
			} else {
				// ovde ide provera koja gleda da li drvo prezivi
				int bs = brojSuseda(mapa, i, j);
			}
		}
	}
	ispis(sg);
}

int main() {
	char mapa[WIDTH][HEIGHT];
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			mapa[i][j] = PRAZNO;
		}
	}
	
	mapa[3][4] = DRVO;
	mapa[3][5] = DRVO;
	
	ispis(mapa);
	jednaKorak(mapa);
	
}