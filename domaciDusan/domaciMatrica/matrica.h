#ifndef MATRICA_H
#define MATRICA_H

#include <iostream>
#include <string>
#include <assert.h>

template <class T>
class Matrica {
private:
  std::string ime;
  int m, n;
  T **mat;
  void popuniMatricu();
public:
  Matrica();
  Matrica(int m, int n);
  Matrica(int m, int n, std::string ime);
  Matrica& operator= (const Matrica &cmat);
  Matrica(const Matrica &mat);
  ~Matrica();
  friend std::ostream &operator<<(std::ostream &out, Matrica<T> &mat);
  T operator()(int n, int m);
  void set(int m, int n, T v);
  friend std::ostream &operator<<(std::ostream &out, Matrica &mat);
  int operator()(int n, int m);
  void sumNaDijagonali();
  void sumNaSporednojDijagonali();
};
#endif
