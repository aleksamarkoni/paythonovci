#include <iostream>

using namespace std;

enum OPCIJA {
  LIST_CHANNELS,
  LIST_USERS,
  ENTER_CHANNEL,
  QUIT,
  ERROR
};

/*
1. /list_channels
2. /list_users
3. /enter_channel
4. /leave_channel
5. /user poruka, ovo ce poslati poruku samo odredjenom useru
6. /quit, prekida vezu sa serverom
*/

OPCIJA obradi_liniju(string line) {
  /* pravilne opcije su:
    |/opcija
    |   /opcija
    |/opcija
    |/user poruka
    trim opcija za string u c++
  // nepravilne opcije, za koje obradi_liniju vraca -1:
    |    /     opcija  // trim bi od ovog napravio /    opcija
    |/daj_listu_svih_konektovanih_usera_is_srbije -> opcija nije podrzana od strane servera
  */
  if (line == "list_channels") {
    return LIST_CHANNELS;
  } else if (line == "list_users") {
    return LIST_USERS;
  } else if (line == "quit") {
    return QUIT;
  } else {
    return ERROR;
  }
}

int main() {
  string line;
  bool radi = true;
  while (radi) {
    cin >> line; // ili ako treba koristiti getline, u sustini, ide jedna opcija po liniji
    OPCIJA opcija = obradi_liniju(line);
    switch(opcija) {
      case LIST_CHANNELS:
        //list_channels();
        cout << "listam kanale" << endl;
        break;
      case LIST_USERS:
        cout << "listam usere" << endl;
        break;
      case QUIT:
        radi = false;
        break;
      default:
        cout << "ne prepoznajem opciju" << endl;
        break;
    }
  }
}
