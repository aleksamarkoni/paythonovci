#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <stdlib.h>
#include "../../domaciDusan/domaciMatrica/matrica.h"

#define MS_PER_FRAME 500
#define WIDTH 10
#define HEIGHT 15

using namespace std;

Matrica mat(WIDTH, HEIGHT);
int x = 2, y = 3;
int dx = 1, dy = 1;

void okviri() {
  if (x + dx >= WIDTH || x + dx < 0)
    dx = -dx;
  if (y + dy >= HEIGHT || y + dy < 0)
    dy = -dy;
}

void randomDva() {
  int x2, y2;
  for(int i = 0; i < 10; i++) {
    x2 = rand() % WIDTH;
    y2 = rand() % HEIGHT;
    if(x2 != x || y2 != y)
    mat.set(x2, y2, 2);
  }
}

void reset() {
  if( mat(x, y) == 2) {
    mat.set(x, y, 0);
  }
  else {
    mat.set(x, y, 0);
  }
}

void update() {
  x += dx;
  y += dy;
  mat.set(x, y, 1);
}

void render() {
  cout << "------------------------------" << endl;
  cout << mat << endl;
}

void gameLoop() {
  while(true) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int start = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    mat.set(x, y, 1);

    okviri();
    reset();
    randomDva();
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
