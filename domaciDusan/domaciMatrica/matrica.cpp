#include "matrica.h"

using namespace std;

Matrica::Matrica(int m, int n) {
  this->m = m; this->n = n;
  mat = new int*[m];
  for(int i = 0; i < m; i++) {
    mat[i] = new int[n];
  }
  popuniMatricu();
}

int Matrica::operator()(int m, int n) {
  assert(m >= 0 && m < this->m);
  assert(n >= 0 && n < this->n);
  return mat[m][n];
}

int Matrica::popuniMatricu() {
  int br = 1;
  for(int i = 0; i < this->m; i++) {
    for(int j = 0; j < this->n; j++) {
      mat[i][j] = br++;
    }
  }
}

std::ostream &operator<<(std::ostream &out, Matrica &mat) {
  for (int i = 0; i < mat.m; i++) {
    for (int j = 0; j < mat.n; j++)
      out << mat.mat[i][j] << " ";
	out << endl;
  }
  return out;
}

Matrica::~Matrica() {
  cout << "Pocinje destruktor" << endl;
  for(int i = 0; i < m; i++) {
    delete [] mat[i];
  }
  delete [] mat;
}

void Matrica::sumNaDijagonali() {
  int sum;
  for (int i = 0; i < this->m; i++) {
    for (int j = 0; j < this->n; j++) {
      if(i == j) {
        sum += mat[i][j];
        cout << "Suma: " << sum << endl;
      }
    }
  }
  cout << "Suma dijagonale je: " << sum << endl;
}

void Matrica::sumNaSporednojDijagonali() {
  int sum = 0;
  for (int i = 0; i < this->m; i++) {
    sum += mat[i][m - i - 1];
    cout << "Suma: " << sum << endl;
  }
  cout << "Suma sporedne dijagonale je: " << sum << endl;
}
