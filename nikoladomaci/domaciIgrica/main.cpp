#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <stdlib.h>
#include "matrica.h"

#define MS_PER_FRAME 500
#define WIDTH 10
#define HEIGHT 15

using namespace std;


Matrica mat(WIDTH, HEIGHT);
  int x, y;
  int dx = 1, dy = 1;
  int dvaX = 0;
  int dvaY = 0;
  int br = 0;
  int score = 0;

void krajMape() {
  if (x + dx >= WIDTH || x + dx < 0)
    dx = -dx;

  if (y + dy >= HEIGHT || y + dy < 0)
    dy = -dy;
}

int resetPolja() {
  mat.set(x, y, 0);
}

void render() {
cout << "------------------" << endl;
cout << mat << endl;
cout << score << endl;
}

void update() {
  x += dx;
  y += dy;
  if (mat(x, y) == 2 ) {
    br++;
    score++;
  }
  mat.set(x, y, 1);
}

void generisanjeRandBrojeva1() {
  if (br == 0) {
    x = rand() % WIDTH;
    y = rand() % HEIGHT;
    mat.set(x, y, 0);
    cout << x << y << endl;
  }
}

void generisanjeRandBrojeva2() {
  for(int br; br < 10; br++) {
    dvaX = rand() % WIDTH;
    dvaY = rand() % HEIGHT;
    if (dvaX !=x || dvaY !=y) {
      mat.set(dvaX, dvaY, 2);
    }
  }
}

void gameLoop() {
  while(true) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int start = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    krajMape();
    resetPolja();
    generisanjeRandBrojeva1();
    generisanjeRandBrojeva2();
    update();
    render();

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
  srand(time(NULL));
  gameLoop();
}
