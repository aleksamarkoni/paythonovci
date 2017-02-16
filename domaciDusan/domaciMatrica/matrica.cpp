#include "matrica.h"

using namespace std;

Matrica<T>::Matrica() {
  this->ime = "Podrazumevana matrica";
  m = 5; n = 5;
  mat = new T*[m];
  for(int i = 0; i < m; i++) {
    mat[i] = new T[n];
  }
  popuniMatricu();
}

Matrica<T>::Matrica(const Matrica &cmat) {
  cout << "Kopi konstruktor" << endl;
  this->ime = cmat.ime;
  m = cmat.m; n = cmat.n;
  mat = new T*[m];
  for(int i = 0; i < m; i++) {
    mat[i] = new T[n];
  }
  for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
		mat[i][j] = cmat.mat[i][j];
	}
  }
}

Matrica<T>::Matrica(int m, int n) {
  this->m = m; this->n = n;
  this->ime = "Nepoznato ime";
  mat = new T*[m];
  for(int i = 0; i < m; i++) {
    mat[i] = new T[n];
  }
  popuniMatricu();
}

Matrica<T>::Matrica(int m, int n, std::string ime) {
  this->ime = ime;
  this->m = m; this->n = n;
  mat = new T*[m];
  for(int i = 0; i < m; i++) {
    mat[i] = new T[n];
  }
  popuniMatricu();
}

Matrica& Matrica<T>::operator= (const Matrica &cmat)
{
	
   cout << "Operator jednakosti" << endl;
  // self-assignment guard
  if (this == &cmat)
    return *this;

  for(int i = 0; i < m; i++) {
    delete [] mat[i];
  }
  delete [] mat;
 
  this->ime = cmat.ime;
  m = cmat.m; n = cmat.n;
  mat = new T*[m];
  for(int i = 0; i < m; i++) {
    mat[i] = new T[n];
  }
  for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
		mat[i][j] = cmat.mat[i][j];
	}
  }
 
  // return the existing object so we can chain this operator
  return *this;
}

T Matrica<T>::operator()(int m, int n) {
  //TODO da li je m izmedju 0 i this->m
  //TODO da li je n izmedju 0 i this->n
  return mat[m][n];
}

void Matrica<T>::popuniMatricu() {
  for(int i = 0; i < this->m; i++) {
    for(int j = 0; j < this->n; j++) {
      mat[i][j] = 0;
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

Matrica<T>::~Matrica() {
  cout << "Pocinje destruktor za " << ime << endl;
  for(int i = 0; i < m; i++) {
    delete [] mat[i];
  }
  delete [] mat;
}

void Matrica<T>::set(int m, int n, T v) {
  //TODO asserts
  mat[m][n] = v;
}
