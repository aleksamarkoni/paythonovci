#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <ctime>
#include <sys/time.h>
#include "../../domaciDusan/domaciMatrica/matrica.h"

#define MS_PER_FRAME 750
#define WIDTH 10
#define HEIGHT 15
#define MAX_BROJ_POENA 5

using namespace std;


Matrica mat(WIDTH, HEIGHT);
int x = 5, y = 4;
int dx = 1, dy = 1;
int brojDvojki = 0;
int poeni = 0;
int brojKrugova = 0;

int randomX() {
  int zivotX = rand() % WIDTH;
  return zivotX;
}

int randomY() {
  int zivotY = rand() % HEIGHT;
  return zivotY;
}

void kolikoImaDvojki() {
  for (int i = 0; i < WIDTH; i++ ) {
    for (int j = 0; j < HEIGHT; j++) {
      if (mat(i, j) == 2) {
        brojDvojki++;
      }
    }
  }
}

void ubaciDvojke() {
  if (brojDvojki < 10 ) {
      mat.set(randomX(), randomY(), 2);
  }
  else {
    brojDvojki = 0;
  }
}

void gameLoop() {
  srand (time(NULL));
  while(true) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int start = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    mat.set(x, y, 0);

    if (x + dx >= WIDTH || x + dx < 0)
      dx = -dx;

    if (y + dy >= HEIGHT || y + dy < 0)
      dy = -dy;

    kolikoImaDvojki();

    ubaciDvojke();

    //update
    x += dx;
    y += dy;

    //brojac poena
    if (mat(x, y) == 2) {
      poeni++;
    }

    mat.set(x, y, 1);

    brojKrugova++;

    //uslov za pobedu
    if (poeni >= MAX_BROJ_POENA) {
      cout << "Igra je zavrsena osvojili ste "<< poeni << " poena nakon "
      << brojKrugova << " pomeraja." << endl;
      break;
    }

    //render
    cout << "------------------" << endl;
    cout << mat << endl;

    //ispisPoena
    cout << "Poeni: " << poeni << endl;

    gettimeofday(&tp, NULL);
    long int end = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    long int process_time = end - start;
    cout << process_time << endl;

    long int sleep_time = MS_PER_FRAME - process_time;
    cout << sleep_time << endl;

    struct timespec req = {0};
    req.tv_sec = 0;
    req.tv_nsec = sleep_time * 1000000L;
    nanosleep(&req, (struct timespec *)NULL);
  }
}

int main() {
  gameLoop();
}
