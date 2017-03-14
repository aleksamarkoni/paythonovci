#include <iostream>
#include <vector>

using namespace std;

class Widget{
public:
  virtual void stampaj() {
    cout << "Ovo je Widget" << endl;
  }
};

class Button : public Widget {
public:
  void stampaj() {
    cout << "Ovo je Button" << endl;
  }

  void clickMe() {
    cout << "Cliknuo sam na button" << endl;
  }
};

class Input : public Widget {
  void stampaj() {
    cout << "Ovo je Input" << endl;
  }
};

class Output : public Widget {
  void stampaj() {
    cout << "Ovo je Output" << endl;
  }
};

class TextBox : public Widget {

};

class Window {
public:
  vector<Widget*> elementi;
  void dodajWidget(Widget * element) {
    elementi.push_back(element);
  }

void stampaj() {
  for (int i = 0; i < elementi.size(); i++) {
    elementi[i]->stampaj();
  }
}


};

void odradiNesto(Window * prozor) {
  //prozor->elementi[0]->clickMe(); ovo je greska
  Button * b = (Button*) prozor->elementi[0];
  b->clickMe();
}

int main() {
  Window prozor;
  Button copy;
  Input input;
  Output output;
  TextBox textBox;
  prozor.dodajWidget(&copy);
  prozor.dodajWidget(&input);
  prozor.dodajWidget(&output);
  prozor.dodajWidget(&textBox);

  copy.clickMe();
  odradiNesto(&prozor);
  prozor.stampaj();
}
