#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <cstdlib>
#include "../domaciDusan/domaciMatrica/matrica.h"

#define MS_PER_FRAME 500
#define WIDTH 10
#define HEIGHT 15
#define BROJ_DVOJKI 10

using namespace std;


Matrica mat(WIDTH, HEIGHT);
int x, y;
int dx, dy;
int poeni;

void setup() {
  //pozicija igraca
  x = rand() % WIDTH;
  y = rand() % HEIGHT;
  mat.set(x,y,1);

  // smer kretanja
  dx = 1;
  dy = 1;
  // random generator
  srand (time(NULL));

  //broj poena
  poeni = 0;

  //ubacujemo dvojke
  assert(WIDTH * HEIGHT - 1 >= BROJ_DVOJKI);
  int br_dvojki = 0;
  while(br_dvojki < BROJ_DVOJKI) {
    int xp = rand() % WIDTH;
    int yp = rand() % HEIGHT;
    // da li na mat(xp,yp) stoji igrac ili vec dvojka
    if (!(mat(xp, yp) == 1 || mat(xp, yp) == 2)) {
      mat.set(xp, yp, 2);
      br_dvojki++;
    }
  }
}

void update() {

  mat.set(x, y, 0);

  if (x + dx >= WIDTH || x + dx < 0)
    dx = -dx;

  if (y + dy >= HEIGHT || y + dy < 0)
    dy = -dy;




  //update igraca
  x += dx;
  y += dy;


  if (mat(x,y) == 2) {
    poeni++;
    while(true) {
      int xp = rand() % WIDTH;
      int yp = rand() % HEIGHT;
      // da li na mat(xp,yp) stoji igrac ili vec dvojka
      if (!(mat(xp, yp) == 1 || mat(xp, yp) == 2)) {
        mat.set(xp, yp, 2);
        break;
      }
    }
  }

  mat.set(x, y, 1);
}

void render() {
  cout << "-------- " << poeni << " -------- " << endl;
  cout << mat << endl;
}

void gameLoop() {

  setup();

  while(true) {
    //pocetno vreme frejma
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int start = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    //logika update i prikaz frejm
    update();
    render();

    //krajnje vreme frejma
    gettimeofday(&tp, NULL);
    long int end = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    //koliko je trajala obrada frejma
    long int process_time = end - start;
    cout << process_time << endl;

    // koliko treba jos da odspavam
    long int sleep_time = MS_PER_FRAME - process_time;
    cout << sleep_time << endl;

    //spavam
    struct timespec req = {0};
    req.tv_sec = 0;
    req.tv_nsec = sleep_time * 1000000L;
    nanosleep(&req, (struct timespec *)NULL);
  }
}

int main() {
  gameLoop();
}
