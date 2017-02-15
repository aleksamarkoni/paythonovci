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
  //TODO da li je m izmedju 0 i this->m
  //TODO da li je n izmedju 0 i this->n
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
