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

  //TODO kopi konstruktor
  PString(const &PString p) {}
  //TODO operator =
  /*
  PString ps1("ovo je neki text");
  PString ps2("ovo je neki drugi text");
  ps1 = ps2;
  cout << ps1 << endl; // "ovo je neki drugi text"
  */

  //TODO operator +
  // recimo da su ps1 i ps2 iste kao iz prethodnog primera
  // PString ps3;
  // ps3 = ps1 + ps2;
  // cout << ps3 << endl; "ovo je neki textovo je neki drugi text"

  //TODO operator[i]
  // vraca karakter unutar naseg string za zadati index i

  //TODO
  // dodati funkcije back i front, koje vracaju poslednji odnosno prvi karakter

  //TODO operator +=
  // ps1 += ps2; kao ps1.append(ps2);\

/*
push_back Append character to string (public member function )
PString ps1("ovo");
ps1.push_back('a');
ovoa

assign Assign content to string (public member function )
PString ps1("ovo je neka recenica");
ps1.assign('pera');
pera

clear clears the string (public member function )
PString ps1("ovo je neka recenica");
ps1.clear();
''

pop_back Delete last character (public member function )
*/

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

    for (int i = 0; i < lenrec - 1; i++) {
      pom[i] = rec[i];
    }

    delete [] rec;

    for (int j = 0; j < lenarec; j++) {
      pom[lenrec - 1 + j] = arec[j];
    }
    pom[lenrec + lenarec - 2] = '\0';

    rec = pom;
  }

  ~PString() {
    delete [] rec;
  }

  int len() {
    int len = 0;
    while (rec[len++] != '\0');
    len - 1;
    return len;
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
  cout << ps1.len() << endl;
  string s("pr");
  PString ps2(s);
  ps1.append(" ");
  ps1.append("Zika.");
  cout << ps1 << endl;
  cout << ps1.len() << endl;
}
