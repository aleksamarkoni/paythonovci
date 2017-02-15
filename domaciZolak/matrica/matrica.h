#ifndef MATRICA_H
#define MATRICA_H

#include <iostream>

class Mat {
  private:
    int sirina;
    int duzina;
  public:
    int **m;
    Mat(int sirina, int duzina);
    ~Mat();
    friend std::ostream &operator<<(std::ostream &out, Mat m);
    int srednjaVrednostDijagonale();
    int sumNaDijagonali();
    int sumNaSporednojDijagonali();
};
#endif
