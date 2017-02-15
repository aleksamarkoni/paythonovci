#include "matrica.h"

using namespace std;
/*
Matrica& Matrica::operator=(Matrica &mat) {
  int i, j;
  for(int n = 0; n < i; n++) {
    *mat[n] = n+1;
    for(int m = 0; m < j; j++) {
      mat[n][m] = m+1;
    }
  }
  return mat;
}
*/

int* Matrica::operator[](int n) {
    return mat[n];
}

int Matrica::operator()(int n, int m) {
  for(int i = 0; i < this->n; i++) {
    for(int j = 0; j < this->m; j++) {
      return mat[n][m];
    }
  }
}

Matrica::Matrica(int m, int n) {
  mat = new int*[n];
  for(int i = 0; i < n; i++) {
    mat[i] = new int[m];
    this->m = m; this->n = n;
  }
}

int Matrica::popuniMatricu(Matrica &mat) {
  int br = 1;
  for(int i = 0; i < this->n; i++) {
    for(int j = 0; j < this->m; j++) {
      mat[i][j] = br;
      br++;
      cout << mat[i][j] << endl;
    }
  }
}

void Matrica::ispisiMatricu(Matrica &mat) {
  for(int i = 0; i < this->n; i++) {
    cout << endl;
    for(int j = 0; j < this->m; j++) {
      cout << mat[i][j] << " ";
    }
  }
  cout << endl;
}

//int saberiDijagonale()
