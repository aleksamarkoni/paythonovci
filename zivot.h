#include <iostream>
#define PRAZNO '.'
#define DRVO 'X'
using namespace std;

class zivot {
private:
  static int width;
  static int height;
  zivot();
  zivot(int width, int height);
  ~zivot();
  zivot(const zivot& matrica);
public:
  zivot** mapa;
  zivot& operator=(const zivot &zivot);
  int getWidth();
  int getHeight();
  void setWidth(int width1);
  void setHeight(int height1);
  void velicinaMape();
  void praznaMapa(zivot **mapa);
  void uNos(zivot **mapa);
  void Kopiranje(zivot **mapa, zivot **sg);
  void jedanKorak(zivot **mapa);
  int brojSuseda(zivot **mapa, int i, int j);
  void simulacija(int brSimulacija, bool ssk, zivot **mapa);
};
