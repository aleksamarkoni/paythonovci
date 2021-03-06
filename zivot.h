#include <iostream>
#define PRAZNO '.'
#define DRVO 'X'
using namespace std;

class zivot {
private:
  int width;
  int height;
  char **mapa;
  bool ssk;
  int mod(int a, int b);
  int brojSuseda(int i, int j);
public:
  zivot();
  zivot(int width, int height);
  ~zivot();
  zivot(const zivot& zivot);
  zivot& operator=(const zivot &zivot);
  void dodajDrvo();
  int getWidth() const;
  int getHeight() const;
  char dajPolje(int i, int j) const;
  void simulacija(int brSimulacija, bool ssk);

  friend ostream& operator <<(ostream& out,const zivot &z);
};
