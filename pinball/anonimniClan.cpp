#include <iostream>

using namespace std;

class Object {
protected:
  int value;
  int pozicija;
  string vrsta;
public:
  Object();
  Object(int value, int pozicija, string vrsta) {
    //cout << "Pozivam (Base) Object constructor" << endl;
    this->value = value;
    this->pozicija = pozicija;
    this->vrsta = vrsta;
  }
  virtual ~Object() {
    //cout << "Poziv na (Base) Object destructor" << endl;
  }
  virtual int getValue() {
    return this->value;
  }

  virtual int getPozicija() {
    return this->pozicija;
  }

  virtual string getVrsta() {
    return this->vrsta;
  }

};

class Bumper : public Object {
public:
  Bumper(int value, int pozicija, string vrsta) : Object(value, pozicija, vrsta) {
    //cout << "Pozivam bumper constructor" << endl;
  }
  virtual ~Bumper() {
    //cout << "Poziv na bumper Destructor" << endl;
  }
  virtual int getValue() override {
    //cout << "Poziv na override" << endl;
    return this->value;
  }

  virtual int getPozicija() override {
    //cout << "Poziv na override" << endl;
    return this->pozicija;
  }

  virtual string getVrsta() override {
    //cout << "Poziv na override" << endl;
    return this->vrsta;
  }
};

class Niz {
private:
  int width;
  Object** niz;
public:
  Niz(int width) {
    this->width = width;
    niz = new Object*[width];
  }
  ~Niz() {
    delete niz;
  }
  void upis(int value, int pozicija) {
    for(int i = 0; i < width; i++) {
      if(i == pozicija) {  //Ovde imam problem
        niz[i] = new Bumper(value, pozicija, "[B]");
      } else {
        niz[i] = new Object(0, 0, "[ ]");
      }
    }
  }
  Object* operator[](int i) {
    return niz[i];
  }
};

int main() {
  int width;
  cout << "Unesi velicinu niza" << endl;
  cin >> width;
  int pozicija;
  cout << "Unesi poziciju bumpera" << endl;
  cin >> pozicija;
  int value;
  cout << "Unesi vrednost bumpera" << endl;
  cin >> value;
  Niz niz(width);
  niz.upis(value, pozicija);
  //Object *niz[4];

  for(int i = 0; i < width; i++) {
      //cout << niz[i]->getValue() << endl;
      //cout << niz[i]->getPozicija() << endl;
      cout << niz[i]->getVrsta() << " ";
  }
}
