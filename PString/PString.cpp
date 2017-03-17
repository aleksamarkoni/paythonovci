#include <iostream>
#include <string>

using namespace std;

//|'o'|'v'|'o'|'a'|_|_|....

class PString {
private:
  char *rec;
public:
  PString() {
    rec = new char[1];
    rec[0] = '\0';
  }

  PString(const char *nekarec) {
    // racunam duzinu reci
    int len = 0;
    while (nekarec[len++] != '\0');

    // alociram dovoljno memorije
    rec = new char[len];

    //kopiram neku rec u nasu memoriju
    for (int i = 0; i <= len; i++) {
      rec[i] = nekarec[i];
    }
  }

  PString(string s) {
    //izracunaj len
    int len = s.length();
    //alocira memoriju
    rec = new char[len + 1];
    // kopira sadrzaj stringa u nasu memoriju
    for (int i = 0; i < len; i++) {
      rec[i] = s[i];
    }
    // na kraj dodaje \0 jer se to ne kopira u prethodnom koraku
    rec[len] = '\0';
  }

  void append(const char *arec) {
    // duzina nase reci
    int lenrec = 0;
    while (rec[lenrec++] != '\0');

    // duzina reci koju appendujemo
    int lenarec = 0;
    while (arec[lenarec++] != '\0');

    char * pom = new char[lenrec + lenarec - 1];

    // pom = "ovo je neka rec "
    // rec = "ovo je neka rec"
    // arec = " "

  }

  ~PString() {
    delete [] rec;
  }

  friend ostream& operator<<(ostream &out, const PString &string);
};

ostream& operator<<(ostream &out, const PString &pstring) {
  out << pstring.rec;
  return out;
}

int main() {
  PString ps;
  PString ps1("Ovo je neka rec.");
  string s("proba stringa");
  PString ps2(s);
  ps1.append(" ");
  ps1.append("Ovo je nastavak.");
  cout << ps1 << endl;
}
