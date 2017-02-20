#ifndef PICE_H
#define PICE_H

class Pice : private Cena {
private:
  int pivo;
  int kafa;
  int rakija;
  bool prodato;
public:
  Pice();
  ~Pice();
};

#endif
