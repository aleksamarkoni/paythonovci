#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

enum ObjectType {
  EMPTY,
  WALL,
  BUMPER,
  BALL
};

enum Direction {
  RIGHT,
  UP,
  LEFT,
  DOWN
};

int nasumice;

Direction randomDirection() {
  int pravac = (rand() % 3) + 0;
  Direction direction;
  if(pravac == 0) {
    direction = RIGHT;
  }
  else if(pravac == 1) {
    direction = UP;
  }
  else if(pravac == 2) {
    direction = LEFT;
  }
  else {
    direction = DOWN;
  }
  return direction;
}

class Object {
protected:
  int x;
  int y;
  int value;
  int cost;
  int lifetime;
  string vrsta;
  Direction direction;
  ObjectType type;
public:
  Object() {}
  //Empty object
  Object(int x, int y, int cost, string vrsta, ObjectType type) {
    this->x = x;
    this->y = y;
    this->cost = cost;
    this->vrsta = vrsta;
    this->type = type;
  }
  //Bumper object
  Object(int x, int y,  int value, int cost, string vrsta, ObjectType type) {
    this->x = x;
    this->y = y;
    this->value = value;
    this->cost = cost;
    this->vrsta = vrsta;
    this->type = type;
  }
  //Ball object
  Object(int x, int y, int value, Direction direction, int lifetime, string vrsta, ObjectType type) {
    this->x = x;
    this->y = y;
    this->value = value;
    this->direction = direction;
    this->lifetime = lifetime;
    this->vrsta = vrsta;
    this->type = type;
  }

  virtual ~Object() {}

  virtual int getX() {
    return this->x;
  }

  virtual void setX(int x) {
    this->x = x;
  }

  virtual int getY()  {
    return this->y;
  }

  virtual void setY(int y) {
    this->y = y;
  }

  virtual int getValue()  {
    return this->value;
  }

  virtual void setValue(int value) {
    this->value += value;
  }

  virtual int getCost()  {
    return this->cost;
  }

  virtual Direction getDirection() {
    return this->direction;
  }

  virtual void setDirection(Direction direction) {
    this->direction = direction;
  }

  virtual int getLifetime() {
    return this->lifetime;
  }

  virtual void setLifetime(int lifetime) {
    this->lifetime -= lifetime;
  }

  virtual string getVrsta() {
    return this->vrsta;
  }

  virtual ObjectType getObjectType() {
    return this->type;
  }

  virtual bool isAlive(int i, int j, Object ***mat) {}

  virtual Object*** move(int i, int j, Object ***mat, int width, int height) {}
};

class Wall : public Object {
public:
  Wall() {}
  Wall(int x, int y, int cost, string vrsta, ObjectType type)
   : Object(x, y, cost, vrsta, type) {}

  ~Wall() {}

  virtual string getVrsta() override {
    return this->vrsta;
  }

  virtual int getCost() override {
    return this->cost;
  }

  virtual ObjectType getObjectType() override {
    return this->type;
  }
};

class Bumper : public Object {
public:
  Bumper(int x, int y, int value, int cost, string vrsta, ObjectType type)
   : Object(x, y, value, cost, vrsta, type) {}

  virtual ~Bumper() {}

  virtual int getX() override {
    return this->x;
  }

  virtual int getY() override {
    return this->y;
  }

  virtual int getValue() override {
    return this->value;
  }

  virtual int getCost() override {
    return this->cost;
  }

  virtual string getVrsta() override {
    return this->vrsta;
  }

  virtual ObjectType getObjectType() override {
    return this->type;
  }
};

class Ball : public Object {
public:
  Ball(int x, int y, int value, Direction direction, int lifetime, string vrsta, ObjectType type)
   : Object(x, y, value, direction, lifetime, vrsta, type) {}

  virtual ~Ball() {}

  virtual int getX() override {
    return this->x;
  }

  virtual void setX(int x) override {
    this->x = x;
  }

  virtual int getY() override {
    return this->y;
  }

  virtual void setY(int y) override {
    this->y = y;
  }

  virtual int getValue() override {
    return this->value;
  }

  virtual void setValue(int value) override {
    this->value += value;
  }

  virtual Direction getDirection() override {
    return this->direction;
  }

  virtual void setDirection(Direction direction) override {
    this->direction = direction;
  }

  virtual int getLifetime() override {
    return this->lifetime;
  }

  virtual void setLifetime(int lifetime) override {
    this->lifetime -= lifetime;
  }

  virtual string getVrsta() override {
    return this->vrsta;
  }

  virtual ObjectType getObjectType() override {
    return this->type;
  }

  virtual bool isAlive(int i, int j, Object ***mat) override {
    cout << mat[i][j]->getLifetime() << endl;
    return mat[i][j]->getLifetime() > 0;
  }

  virtual Object*** move(int i, int j, Object ***mat, int width, int height) override {
    Direction direction = mat[i][j]->getDirection();
    switch(direction) {
      case RIGHT:
      //Slucaj kada je lopta u donjem desnom cosku
      if(mat[i][j]->getX() == width - 2 && mat[i][j]->getY() == height - 2) {
        if(mat[i+1][j]->getObjectType() == WALL) {
          if(nasumice == 1) {
            while(randomDirection() == RIGHT && randomDirection() == DOWN) {
              direction = randomDirection();
            }
            mat[i][j]->setDirection(direction);
          }
          else {
            mat[i][j]->setDirection(UP);
          }
          mat[i][j]->setY(j-1);
          mat[i][j]->setLifetime(1);
        }
      } //Slucaj kada je sledece polje na desno zid
      else if(mat[i][j]->getX() == width - 2) {
        if(mat[i+1][j]->getObjectType() == WALL) {
          if(nasumice == 1) {
            while(randomDirection() == RIGHT) {
              direction = randomDirection();
            }
            mat[i][j]->setDirection(direction);
          }
          else {
            mat[i][j]->setDirection(DOWN);
          }
          mat[i][j]->setY(j+1);
          mat[i][j]->setLifetime(1);
          //dodajLoptu(mat[i][j]->getX(), mat[i][j]->getY() + 1, mat[i][j]);
          //mat[i][j] = new Object(i, j, 0, "[ ]", EMPTY);
        }
      }
      else { //Standardni slucaj kada je desno prazno ili bumper
        if(mat[i+1][j]->getObjectType() == BUMPER) {
          if(nasumice == 1) {
            while(randomDirection() == RIGHT) {
              direction = randomDirection();
            }
            mat[i][j]->setDirection(direction);
          }
          else {
            mat[i][j]->setDirection(DOWN);
          }
          mat[i][j]->setY(j+1);
          mat[i][j]->setValue(mat[i+1][j]->getValue());
          mat[i][j]->setLifetime(mat[i+1][j]->getCost());
          mat[i][j+1] = new Ball(x, y, 0, direction, lifetime, "[o]", BALL);
          mat[i][j] = new Object(i, j, 0, "[ ]", EMPTY);

        }
        else {
          mat[i][j]->setX(i+1);
          mat[i][j]->setLifetime(1);
        }
      }
      break;
    }
    return mat;
  }

};

/*
proveri smer kretanja lopte
sta stoji na sledecem polju matrice?
postavi sledecu direkciju
pomeri loptu u odgovarajucem smeru na osnovu zadate direkcije
na starom mestu lopte postavi prazno mesto
*/

class Matrica {
private:
  int width;
  int height;
  Object ***mat;
public:
  Matrica(int width, int height) {
    this->width = width;
    this->height = height;
    mat = new Object**[width];
    for(int i = 0; i < width; i++) {
      mat[i] = new Object*[height];
    }
  }

  ~Matrica() {
    for(int i = 0; i < width; i++) {
      delete [] mat[i];
    }
    delete mat;
  }

  void popuniMatricu() {
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        if(i == 0 || j == 0 || i == width - 1 || j == height - 1) {
          mat[i][j] = new Wall(i, j, 1, "[W]", WALL);
        } else {
            mat[i][j] = new Object(i, j, 0, "[ ]", EMPTY);
          }
      }
    }
  }

  int getWidth() {
    return this->width;
  }

  int getHeight() {
    return this->height;
  }

  Object* operator()(int i, int j) {
    return mat[i][j];
  }

  void dodajBumper(int x, int y, Object* obj) {
      mat[x][y] = obj;
  }

  void dodajLoptu(int x, int y, Object* obj) {
    mat[x][y] = obj;
  }

  void unesiLopte() {
    int brLopti, x, y, value, pravac, lifetime;
    Direction direction;
    cout << "Unesi broj lopti" << endl;
    cin >> brLopti;
    for(int i = 0; i < brLopti; i++) {
      cout << "Unesi X koordinatu " << i+1 << ". lopte" << endl;
      cin >> x;
      if(x == 0) {
        x += 1;
      }
      if(x == width - 1) {
        x -= 1;
      }
      cout << "Unesi Y koordinatu " << i+1 << ". lopte" << endl;
      cin >> y;
      if(y == 0) {
        y += 1;
      }
      if(y == height - 1) {
        y -= 1;
      }
      cout << "Unesi pocetnu direkciju lopte" << endl;
      cout << "0 - Desno" << endl;
      cout << "1 - Gore" << endl;
      cout << "2 - Levo" << endl;
      cout << "3 - Dole" << endl;
      cin >> pravac;
      while(pravac < 0 || pravac > 3) {
        cout << "Unesi direkciju ponovo" << endl;
        cin >> pravac;
        if(pravac == 0) {
          direction = RIGHT;
        }
        else if(pravac == 1) {
          direction = UP;
        }
        else if(pravac == 2) {
          direction = LEFT;
        }
        else {
          direction = DOWN;
        }
      }
      cout << "Unesi zivot lopte od 1 do 100" << endl;
      cin >> lifetime;
      while(lifetime == 0 || lifetime < 0 || lifetime > 100) {
        cout << "Ne moze negativna vrednost i nula, unesi ponovo" << endl;
        cin >> lifetime;
      }
      dodajLoptu(x, y, new Ball(x, y, 0, direction, lifetime, "[o]", BALL));
    }
  }

  void unesiBumpere() {
    int brBumpera, x, y, value, cost;
    cout << "Unesi broj bumpera" << endl;
    cin >> brBumpera;
    for(int k = 0; k < brBumpera; k++) {
      cout << "Unesi X koordinatu " << k+1 << ". bumpera" << endl;
      cin >> x;
      if(x == 0) {
        x += 1;
      }
      if(x == width - 1) {
        x -= 1;
      }
      cout << "Unesi Y koordinatu " << k+1 << ". bumpera" << endl;
      cin >> y;
      if(y == 0) {
        y += 1;
      }
      if(y == height - 1) {
        y -= 1;
      }
      cout << "Unesi value " << k+1 << ". bumpera" << endl;
      cin >> value;
      while(value < 0) {
        cout << "Ne moze negativna vrednost, unesi ponovo" << endl;
        cin >> value;
      }
      cout << "Unesi cost " << k+1 << ". bumpera" << endl;
      cin >> cost;
      dodajBumper(x, y, new Bumper(x, y, value, cost, "[B]", BUMPER));
    }
  }

  void pomeranjeLopte() {
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        if(mat[i][j]->getObjectType() == BALL) {
          mat[i][j]->move(i, j, mat, width, height);
        }
      }
    }
  }

  bool running() {
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        if(mat[i][j]->getObjectType() == BALL) {
          return mat[i][j]->isAlive(i, j, mat);
        }
      }
    }
  }

};

void unesiVelicinuMatrice(int &width, int &height) {
  cout << "Unesi sirinu matrice" << endl;
  cin >> width;
  cout << "Unesi visinu matrice" << endl;
  cin >> height;
}

void daLiRandom(int &nasumice) {
  cout << "Da li zelis random pravac na odbitku?" << endl;
  cout << "1 - Da" << endl;
  cout << "0 - Ne" << endl;
  cin >> nasumice;
  while(nasumice < 0 || nasumice > 1) {
    cout << "Moze da se unese samo 1 ili 0, pokusaj ponovo" << endl;
    cin >> nasumice;
  }
}

void iscrtajMatricu(Matrica &matrica) {
  for (int i = 0; i < matrica.getWidth(); i++) {
    cout << endl;
    for (int j = 0; j < matrica.getHeight(); j++) {
      cout << matrica(i, j)->getVrsta() << " ";
    }
  }
  cout << endl;
}

int main() {
  srand(time(NULL));
  int width, height;
  //daLiRandom(nasumice);
  unesiVelicinuMatrice(width, height);
  Matrica matrica(width, height);
  matrica.popuniMatricu();
  matrica.unesiBumpere();
  matrica.unesiLopte();
  while(matrica.running()) {
    matrica.pomeranjeLopte();
    iscrtajMatricu(matrica);
  }

}
