#ifndef MATRICA_H
#define MATRICA_H

#include <iostream>
#include <string>
#include <assert.h>
#include <ctime>

class Matrica {
private:
  std::string ime;
  int m, n;
  int **mat;
  void popuniMatricu();
public:
  Matrica();
  Matrica(int m, int n);
  Matrica(int m, int n, std::string ime);
  Matrica& operator= (const Matrica &cmat);
  Matrica(const Matrica &mat);
  ~Matrica();
  void set(int m, int n, int v);
  friend std::ostream &operator<<(std::ostream &out, Matrica &mat);
  int operator()(int n, int m);
  void sumNaDijagonali();
  void sumNaSporednojDijagonali();
};
#endif
