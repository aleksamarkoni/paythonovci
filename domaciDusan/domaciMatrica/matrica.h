#ifndef MATRICA_H
#define MATRICA_H

#include <iostream>

class Matrica {
private:
  int m, n;
  int **mat;
public:
  Matrica(int i, int j);
  ~Matrica();
  int popuniMatricu(Matrica &mat);
  void ispisiMatricu(Matrica &mat);
  //Matrica& operator=(Matrica &mat);
  int* operator[](int n);
  //int operator[](int m);
  int operator()(int n, int m);
};

#endif
