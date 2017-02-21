#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <cstdlib>
#include <vector>
#include "../domaciMatrica/matrica.h"

#define MS_PER_FRAME 500
#define WIDTH 10
#define HEIGHT 15

using namespace std;

Matrica mat(WIDTH, HEIGHT);
int x, y;
int dx = 1, dy = 1;
int dvaX = 0, dvaY = 0;
int brojac = 0;
int score = 0;
bool running = 1;

void daLiJeKrajMape() {
  if (x + dx >= WIDTH || x + dx < 0)
    dx = -dx;

  if (y + dy >= HEIGHT || y + dy < 0)
    dy = -dy;
}

void randomBrojJedan() {
  if(brojac == 0) {
    x = rand() % WIDTH;
    y = rand() % HEIGHT;
    mat.set(x, y, 0);
    cout << "Random X: " << x << "\n" << "Random Y: " << y << endl;
  }
}

void randomBrojeviDva() {
bool isto = 1;
int Xprovera[10];
int Yprovera[10];
  for(brojac; brojac < 10; brojac++) {
    dvaX = rand() % WIDTH;
    dvaY = rand() % HEIGHT;
    Xprovera[brojac] = dvaX;

    cout << "dvaX: " << dvaX << endl;
    Yprovera[brojac] = dvaY;

    cout << "dvaY: " << dvaX << endl;
    if(brojac > 0) {
      while(isto) {
          for(int test = 0; test < 10; test++) {
            if(Xprovera[test] == dvaX && Yprovera[test] == dvaY) {
              cout << "Xniz: " << Xprovera[test] << endl;
              cout << "dvaX: " << dvaX << endl;

              cout << "Yniz: " << Yprovera[test] << endl;
              cout << "dvaY: " << dvaX << endl;

              cout << "Ista lokacija" << endl;
              dvaX = rand() % WIDTH;
              dvaY = rand() % HEIGHT;
            } else {
                isto = 0;
              }
          }
        }
      }
    if(dvaX != x || dvaY != y ) {
      mat.set(dvaX, dvaY, 2);
    }
    cout << "Brojac: " << brojac << endl;
  }
}

int resetPolja() {
  mat.set(x, y, 0);
}

void update() {
  x += dx;
  y += dy;
  if(mat(x, y) == 2) {
    brojac = 8;
    score++;
  }
  mat.set(x, y, 1);
  cout << "Score " << score << endl;
  if(score == 5) {
    running = 0;
  }
}

void render() {
  cout << "------------------" << endl;
  cout << mat << endl;
}

void gameLoop() {
  while(running) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int start = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    daLiJeKrajMape();
    resetPolja();
    randomBrojJedan();
    randomBrojeviDva();

    update();
    cout << "Brojac: " << brojac << endl;
    render();

    gettimeofday(&tp, NULL);
    long int end = tp.tv_sec * 1000 + tp.tv_usec / 1000;

    long int process_time = end - start;
    //cout << process_time << endl;

    long int sleep_time = MS_PER_FRAME - process_time;
    //cout << sleep_time << endl;

    struct timespec req = {0};
    req.tv_sec = 0;
    req.tv_nsec = sleep_time * 1000000L;
    nanosleep(&req, (struct timespec *)NULL);
    brojac++;
  }
}

int main() {
  srand(time(NULL));
  gameLoop();
}
