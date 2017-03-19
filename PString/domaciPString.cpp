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

  PString(const PString &p) {
    int len = 0;
    while (p.rec[len++] != '\0');

    rec = new char[len];

    for (int i = 0; i <= len; i++) {
      rec[i] = p.rec[i];
    }
  }

  ~PString() {
    //cout << "Ukljucio se destruktor" << endl;
    //delete [] rec;
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

  void push_back(char arec) {
    int lenrec = 0;
    while (rec[lenrec++] != '\0');
    // duzina reci koju appendujemo
    char * pom = new char[lenrec - 1];
    // pom = "ovo je neka rec "
    // rec = "ovo je neka rec"
    // arec = " "
    for (int i = 0; i < lenrec - 1; i++) {
      pom[i] = rec[i];
    }
    delete [] rec;
    pom[lenrec - 1] = arec;
    pom[lenrec] = '\0';
    rec = pom;
    }

  void pop_back() {
    int lenrec = 0;
    while(rec[lenrec++] != '\0');
    char *pom = new char[lenrec - 2];
    for (int i = 0; i < lenrec - 2; i++) {
      pom[i] = rec[i];
    }
    delete [] rec;
    pom[lenrec - 1] = '\0';
    rec = pom;
  }

  int len() {
    int len = 0;
    while (rec[len++] != '\0');
    len - 1;
    return len;
  }

  char front() {
    return rec[0];
  }

  char back() {
    int len = 0;
    while (rec[len++] != '\0');
    return rec[len - 2];   // -2 ide jer je poslednje slovo na predposlednjem mestu u nizu
  }

  void clear() {
    delete [] rec;
    rec[0] = '\0';
  }

  PString& operator=(const PString &p);
//  PString& operator+(const PString &p);
  friend ostream& operator<<(ostream &out, const PString &string);
  char& operator[](const int index);
};

PString& PString::operator=(const PString &p) {
    rec = p.rec;
    return *this;
}

/*PString& PString::operator+(const PString &p) {
    PString ps4;
    std::string(ps4.rec) = std::string(this->rec) + std::string(p.rec);
    return ps4;
}*/

ostream& operator<<(ostream &out, const PString &pstring) {
  out << pstring.rec;
  return out;
}

char& PString::operator[](const int index) {
  return rec[index];
}

int main() {
  //PString ps;
  //PString ps1("Ovo je neka rec.");
  //cout << ps1.len() << endl;
  //string s("pr");
  //PString ps2(s);
  //ps1.append(" ");
  //ps1.append("Zika.");
  //cout << ps1 << endl;
  //cout << ps1.len() << endl;
  PString ps1("Ovo je neki text");
  PString ps2("ovo je neki drugi text");
  PString ps3(ps1);
  PString ps4("Bravo mare legendo");
  ps1 = ps2;
  //PString ps4;
  //ps4 = ps1 + ps2;
  //cout << ps4 << endl;
  cout << ps1 << endl;
  cout << ps3 << endl;
  cout << ps1[2] << endl;
  cout << ps4.back() << endl;
  cout << ps4.front() << endl;
  ps4.push_back('!');
  ps1.clear();
  cout << ps4 << endl;
  ps4.pop_back();
  cout << ps4 << endl;
  ps4.clear();
  cout << ps4 << endl;
}



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
// ps1 += ps2; kao ps1.append(ps2);
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
