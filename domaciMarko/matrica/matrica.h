#ifndef _MATRICA_H_
#define _MATRICA_H_

#include <iostream>

class Matrica {
private:
  int duzinaMatrice;
  int sirinaMatrice;
  int **pokazivac;
public:
  Matrica(int duzinaMatrice, int sirinaMatrice);
  int operator()(int duzinaMatrice, int sirinaMatrice);
  friend std::ostream &operator <<(std::ostream &out, Matrica &mat);
  int getDuzinaMatrice();
  int getSirinaMatrice();
  int popunjavanjeBrMatrice();
  ~Matrica();
};
#endif
