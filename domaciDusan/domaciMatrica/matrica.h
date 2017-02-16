#ifndef MATRICA_H
#define MATRICA_H

#include <iostream>

class Matrica {
private:
  int m, n;
  int **mat;
  int popuniMatricu();
public:
  Matrica(int m, int n);
  ~Matrica();
  friend std::ostream &operator<<(std::ostream &out, Matrica &mat);
  int operator()(int n, int m);
  void sumNaDijagonali();
  void sumNaSporednojDijagonali();
};

#endif
