#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class Object {
protected:
  int value;
  int pozicija;
public:
  Object() {}
  Object(int, int) {
    this->value = value;
    this->pozicija = pozicija;
    cout << "Poziva se (Base) - Object constructor" << endl;
  }
  virtual ~Object() {
    cout << "Poziva se Object destructor" << endl;
  }

  virtual int getValue() {
    cout << "Poziva se (Base) getValue()" << endl;
    return this->value;
  }

  virtual int getPozicija() {
    return this->pozicija;
  }

  //int operator* () {
  //  return this->value;
  //}
  friend ostream& operator<<(ostream& out, Object* obj);
  //virtual ostream& print(ostream& out, Object* obj) const {
  //  cout << obj << endl;
  //  return out;
  //}
};
ostream& operator<<(ostream& out, Object* obj) {
  out << "Test " << obj << endl;
  //obj->print(out, &*obj);
  return out;
}

class Bumper : public Object {
public:
  Bumper(int value, int pozicija) : Object(value, pozicija) {
    cout << "Poziva se bumper constructor" << endl;
  }
  virtual ~Bumper() {
    cout << "Poziva se Bumper destructor" << endl;
  }

  virtual int getValue() override {
    cout << "Poziva se override" << endl;
    return this->value;
  }

  virtual int getPozicija() override {
    return this->pozicija;
  }

  //virtual ostream& print(ostream& out, Object* obj) const override {
  //    cout << obj << endl;
  //    return out;
  //  }
};

class Niz {
private:
  int width;
  Object **niz;
public:
  Niz() {}
  Niz(int width) {
    this->width = width;
    niz = new Object*[width];
  }

  int getWidth() {
    return this->width;
  }

  ~Niz() {
    //for(int i = 0; i < width; i++) {
    //  delete [] niz[i];
    //}
    delete niz;
  }

  void popuniNiz() {
    int value, pozicija, brBumpera;
    cout << "Unesi broj bumpera" << endl;
    cin >> brBumpera;
    for(int j = 0; j < brBumpera; j++) {
      cout << "Unesi poziciju bumpera" << endl;
      cin >> pozicija;
      cout << "Unesi vrednost bumpera" << endl;
      cin >> value;
      for(int i = 0; i < width; i++) {
        if(i == pozicija) {
          niz[i] = new Bumper(value, pozicija);
        } else {
          niz[i] = new Object(0, 0);
        }
      }
    }
  }

  Object** getNiz() {
      return this->niz;
  }

  //friend ostream& operator<<(ostream& out, Niz &niz);
  Object* operator[](int i) {
    return niz[i];
  }
};

//ostream& operator<<(ostream &out, Niz& niz) {
//  for(int i = 0; i < niz.width; i++) {
//    out << niz.niz[i] << " ";
//  }
//  return out;
//}

int main() {
  int width;
  cout << "Unesi duzinu niza" << endl;
  cin >> width;
  Niz niz(width);
  //ostream_iterator<Object**> outIter( cout, " " );
  //copy(niz.getNiz().begin(), niz.getNiz().end(), outIter);
  for(int i = 0; i < niz.getWidth(); i++) {
    cout << niz.getNiz()[i]->getValue() << endl;
    //cout << obj->getValue() << endl;
  }
}
