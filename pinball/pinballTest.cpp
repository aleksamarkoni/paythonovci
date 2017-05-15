#include <iostream>

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

class Object;
class Wall;
class Bumper;
class Ball;

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
    for (int i = 0; i < mat.getWidth(); i++) {
      for (int j = 0; j < mat.getHeight(); j++) {
        if(i == 0 || j == 0 || i == mat.getWidth() - 1 || j == mat.getHeight() - 1) {
          mat[i][j] = new Wall(i, j, 1, "[W]", WALL);
        } else {
            mat[i][j] = new Object(i, j, 0, 0, "[ ]", EMPTY);
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

  void dodajZid(int x, int y, Object* obj) {
    mat[x][y] = obj;
  }

  void dodajPrazno(int x, int y, Object* obj) {
    mat[x][y] = obj;
  }

};

class Object {
protected:
  int x;
  int y;
  int value;
  int cost;
  int direction;
  int lifetime;
  string vrsta;
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
  Object(int x, int y, int value, int direction, int lifetime, string vrsta, ObjectType type) {
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

  virtual int getY()  {
    return this->y;
  }

  virtual int getValue()  {
    return this->value;
  }

  virtual int getCost()  {
    return this->cost;
  }

  virtual int getDirection() {
    return this->direction;
  }

  virtual int getLifetime() {
    return this->lifetime;
  }

  virtual string getVrsta() {
    return this->vrsta;
  }

  virtual ObjectType getObjectType() {
    return this->type;
  }

  virtual void move() {}
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

  virtual ObjectType getObjectType() override {
    return this->type;
  }
};

class Bumper : public Object {
public:
  Bumper(int x, int y, int value, int cost, string vrsta, ObjectType type)
   : Object(x, y, value, cost, vrsta, type) {
  }

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
private:
  Direction direction;
public:
  Ball(int x, int y, int value, int direction, int lifetime, string vrsta, ObjectType type)
   : Object(x, y, value, direction, lifetime, vrsta, type) {
  }

  virtual ~Ball() {}

  virtual int getX() override {
    return this->x;
  }

  virtual int getY() override {
    return this->y;
  }

  virtual int getValue() override {
    return this->value;
  }

  virtual int getDirection() override {
    return this->direction;
  }

  virtual int getLifetime() override {
    return this->lifetime;
  }

  virtual string getVrsta() override {
    return this->vrsta;
  }

  virtual ObjectType getObjectType() override {
    return this->type;
  }

  virtual void move() override {

  }

};

void unesiVelicinuMatrice(int &width, int &height) {
  cout << "Unesi sirinu matrice" << endl;
  cin >> width;
  cout << "Unesi visinu matrice" << endl;
  cin >> height;
}

void unesiLopte(Matrica &mat) {
  int brLopti, x, y, value, direction, lifetime;
  cout << "Unesi broj lopti" << endl;
  cin >> brLopti;
  for(int i = 0; i < brLopti; i++) {
    cout << "Unesi X koordinatu " << i+1 << ". lopte" << endl;
    cin >> x;
    if(x == 0) {
      x += 1;
    }
    if(x == mat.getWidth() - 1) {
      x -= 1;
    }
    cout << "Unesi Y koordinatu " << i+1 << ". lopte" << endl;
    cin >> y;
    if(y == 0) {
      y += 1;
    }
    if(y == mat.getHeight() - 1) {
      y -= 1;
    }
    cout << "Unesi pocetnu direkciju lopte" << endl;
    cout << "0 - Desno" << endl;
    cout << "1 - Gore" << endl;
    cout << "2 - Levo" << endl;
    cout << "3 - Dole" << endl;
    cin >> direction;
    while(direction < 0 || direction > 3) {
      cout << "Unesi direkciju ponovo" << endl;
      cin >> direction;
    }

    cout << "Unesi zivot lopte od 1 do 100" << endl;
    cin >> lifetime;
    while(lifetime == 0 || lifetime < 0 || lifetime > 100) {
      cout << "Ne moze negativna vrednost i nula, unesi ponovo" << endl;
      cin >> lifetime;
    }
    mat.dodajLoptu(x, y, new Ball(x, y, 0, direction, lifetime, "[o]", BALL));
  }
}

void unesiBumpere(Matrica &mat) {
  int brBumpera, x, y, value, cost;
  cout << "Unesi broj bumpera" << endl;
  cin >> brBumpera;
  for(int k = 0; k < brBumpera; k++) {
    cout << "Unesi X koordinatu " << k+1 << ". bumpera" << endl;
    cin >> x;
    if(x == 0) {
      x += 1;
    }
    if(x == mat.getWidth() - 1) {
      x -= 1;
    }
    cout << "Unesi Y koordinatu " << k+1 << ". bumpera" << endl;
    cin >> y;
    if(y == 0) {
      y += 1;
    }
    if(y == mat.getHeight() - 1) {
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
    mat.dodajBumper(x, y, new Bumper(x, y, value, cost, "[B]", BUMPER));
  }
}

void unesiZid(Matrica &mat) {
  mat[i][j] = new Wall(i, j, 1, "[W]", WALL);
}
void popuniMatricu() {
  for (int i = 0; i < mat.getWidth(); i++) {
    for (int j = 0; j < mat.getHeight(); j++) {
      if(i == 0 || j == 0 || i == mat.getWidth() - 1 || j == mat.getHeight() - 1) {
        mat[i][j] = new Wall(i, j, 1, "[W]", WALL);
      } else {
          mat[i][j] = new Object(i, j, 0, 0, "[ ]", EMPTY);
        }
    }
  }
}
/*
void pomeranjeLopte(Matrica &mat) {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      if(mat[i][j]->getObjectType() == BALL) {
        mat[i][j]->move();
      }
    }
  }
}
*/
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
  int width, height;
  unesiVelicinuMatrice(width, height);
  Matrica matrica(width, height);
  popuniMatricu(matrica);
  unesiBumpere(matrica);
  unesiLopte(matrica);
  iscrtajMatricu(matrica);
}
