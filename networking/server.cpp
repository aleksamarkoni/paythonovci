/*
** server.c -- a stream socket server demo
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define PORT "34502" // the port client will be connecting to
#define IP_ADRESS "192.168.0.151"
#define BACKLOG 10     // how many pending connections queue will hold
#define BROJ_KANALA 4

int connected_client[100];
int i = 0;
string ispis;
enum OPCIJE {
  LISTA_KANALA,
  GENERAL,
  PROGRAMMING,
  SEX,
  KOLACI,
  KORISNICI,
  IZADJI,
  POMOC,
  ERROR
};

class Kanal;

class Korisnik {
private:
  int sock;
  string username;
  int korisnikovKanal;
public:
  Korisnik() {}
  Korisnik(int sock, char *username) {
    setSocket(sock);
    setUsername(username);
    korisnikovKanal = -1;
  }
  void setSocket(int sock) {
    this->sock = sock;
  }
  void setUsername(char *username) {
      this->username = username;
  }
  void prosiriUsername() {
    this->username.append(": ");
  }
  int getSocket() {
    return sock;
  }
  string getUsername() {
    return username;
  }
  int getKorisnikovKanal() {
    return korisnikovKanal;
  }
  void setKorisnikovKanal(int izbor) {
    this->korisnikovKanal = izbor;
  }
  void konvStrUChar(char *nickname) {
    int len = username.length();
    for (int i = 0; i < len; i++) {
      nickname[i] = username[i];
    }
  }
  void konvStrUChar(char *nickname, string ispis) {
    int len = ispis.length();
    for (int i = 0; i < len - 1; i++) {
      nickname[i] = ispis[i];
    }
    nickname[len] = '\0';
  }

  friend ostream& operator<<(ostream &out, const Korisnik &user);
};

class IsOdd {
  Korisnik &zaBrisanje;

public:
  IsOdd(Korisnik &zaBrisanje) :
    zaBrisanje(zaBrisanje)
  {}

  bool operator()(Korisnik k) const {
    return k.getSocket() == zaBrisanje.getSocket();
  }
};

class Kanal {
private:
  string ime;
  vector <Korisnik> korisnici;
public:
  Kanal() {}
  Kanal(string imeKanala) {
    setKanal(imeKanala);
  }
  void setKanal(string imeKanala) {
    this->ime = imeKanala;
  }
  void dodajKorisnika(Korisnik *user) {
    korisnici.push_back(*user);
    cout << "Upisao korisnika" << endl;
  }
  string getImeKanala() {
    return this->ime;
  }
  vector<Korisnik> getKorisnici() {
    return this->korisnici;
  }

  void ukloniKorisnika(Korisnik &user) {
    korisnici.erase(
      remove_if(korisnici.begin(), korisnici.end(), IsOdd(user)),
      korisnici.end());
  }

  void konvKANALStrUChar(char *pomocni, int izbor, vector<Kanal> kanali) {
    int len = ime.length();
    for (int i = 0; i < len; i++) {
      pomocni[i] = kanali[izbor - 1].ime[i];
    }
  }
  friend ostream& operator<<(ostream &out, Kanal &kanal);
};

vector<Kanal> kanali;
Kanal General("General");
Kanal Programming("Programming");
Kanal Sex("Sex");
Kanal Kolaci("Kolaci");

ostream& operator<<(ostream &out, Korisnik &user) {
  //probajte ovo
  out << user.getUsername() << endl;
  return out;
}

void napusti_sve_kanale(vector<Kanal> &kanali, Korisnik &user) {
  for (int j = 0; j < BROJ_KANALA; ++j) {
    kanali[j].ukloniKorisnika(user);
  }
}

ostream& operator<<(ostream &out, Kanal &kanal) {
  //TODO
  out << kanal.ime << endl;
  for (int i = 0; i < kanal.korisnici.size(); i++) {
    out << kanal.korisnici[i] << endl;
  }
  return out;
}

//the thread function
void *connection_handler(void *);

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

char prvo_slovo(char *message) {
  return message[0];
}

OPCIJE prva_rec(char *message) {
  string str1 = message;
  size_t pos = str1.find(" ");
  string str2 = str1.substr(0, pos);
  if(str2 == "/kanali") {
    return LISTA_KANALA;
  }
  else if(str2 == "/General" || str2 == "/general" || str2 == "/1") {
    return GENERAL;
  }
  else if(str2 == "/Programming" || str2 == "/programming" || str2 == "/2") {
    return PROGRAMMING;
  }
  else if(str2 == "/Sex" || str2 == "/sex" || str2 == "/3") {
    return SEX;
  }
  else if(str2 == "/Kolaci" || str2 == "/kolaci" || str2 == "/4") {
    return KOLACI;
  }
  else if(str2 == "/Korisnici" || str2 == "/korisnici") {
    return KORISNICI;
  }
  else if(str2 == "/izadji" || str2 == "/leave" || str2 == "/Izadji" || str2 == "/Leave") {
    return IZADJI;
  }
  else if(str2 == "/Help" || str2 == "/help" || str2 == "/?" || str2 == "/pomoc" || str2 == "/Pomoc") {
    return POMOC;
  }
  else return ERROR;
}

void svi_kanali(Korisnik &user) {
  string skanali;
  char *kanaliChar;
  for (int k = 0; k < kanali.size(); k++) {
    skanali += to_string(k+1) + " - ";
    skanali += kanali[k].getImeKanala();
    skanali += "\n";
  }
  int len = skanali.length();
  kanaliChar = new char[len - 1];
  for (int p = 0; p < len - 1; p++) {
    kanaliChar[p] = skanali[p];
  }
  kanaliChar[len - 1] = '\0';
  write(user.getSocket(), kanaliChar, strlen(kanaliChar));
  delete kanaliChar;
}

void svi_korisnici(Korisnik &user) {
  string korisnik;
  char *korisnik_char;
  int broj_korisnika = kanali[user.getKorisnikovKanal()].getKorisnici().size();
  for (int k = 0; k < broj_korisnika; k++) {
    korisnik += to_string(k+1) + " - ";
    korisnik += kanali[user.getKorisnikovKanal()].getKorisnici()[k].getUsername();
    korisnik.erase(korisnik.length() - 2);
    korisnik += "\n";
  }
  int len = korisnik.length();
  korisnik_char = new char[len - 1];
  for (int p = 0; p < len - 1; p++) {
    korisnik_char[p] = korisnik[p];
  }
  korisnik_char[len - 1] = '\0';
  write(user.getSocket(), korisnik_char, strlen(korisnik_char));
  delete korisnik_char;
}

//TO DO prvi korisnik ima newline ostali se zalepe jedan za drugog
void konvertovanje(char *nickname, string username) {
  int len = username.length();
  for (int i = 0; i < len - 2; i++) {
    nickname[i] = username[i];
  }
  nickname[len-2] = '\n';
  nickname[len-1] = '\0';
}

void sveOpcije(Korisnik &user) {
  string str;
  char *prebaci;
  str = "Lista svih kanala - /kanali\n";
  str += "Lista svih korisnika - /korisnici\n";
  str += "Kanal general - /general - /1\n";
  str += "Kanal programming - /programming - /2\n";
  str += "Kanal Sex - /sex - /3\n";
  str += "Kanal Kolaci - /kolaci - /4\n";
  str += "Izlaz iz kanala - /leave - /izadji\n";
  int len = str.length();
  prebaci = new char[len - 1];
  for (int p = 0; p < len - 1; p++) {
    prebaci[p] = str[p];
  }
  prebaci[len] = '\0';
  write(user.getSocket(), prebaci, strlen(prebaci));
  delete prebaci;
}

void izbor_kanala(OPCIJE opcije, Korisnik *user) {
  int j, izbor, broj_korisnika;
  string korisnik;
  char korisnik_char[666];
  cout << "Izbor: " << opcije << endl;
  switch(opcije) {
    case LISTA_KANALA:
      svi_kanali(*user);
    break;
    case GENERAL:
      izbor = 0;
      if (user->getKorisnikovKanal() != -1 ) {
        cout << "U kanalu_General :  " << endl;
        napusti_sve_kanale(kanali, *user);
        user->setKorisnikovKanal(-1);
        cout << "Promenio korisnikov kanal na: " << user->getKorisnikovKanal() << endl;
      }
      if(user->getKorisnikovKanal() != 0) {
        user->setKorisnikovKanal(izbor);
        kanali[0].dodajKorisnika(user);
        write (user->getSocket(), "Kanal: General", 14);
        cout << "Kanal: " << kanali[0] << endl;
      } else {
        write (user->getSocket(), "Vec se nalazis u tom kanalu", 27);
      }
    break;
    case PROGRAMMING:
      izbor = 1;
      if (user->getKorisnikovKanal() != -1 ) {
        cout << "U kanalu Programing :  " << endl;
        napusti_sve_kanale(kanali, *user);
        user->setKorisnikovKanal(-1);
        cout << "Promenio korisnikov kanal na: " << user->getKorisnikovKanal() << endl;
      }
      if(user->getKorisnikovKanal() != 1) {
        user->setKorisnikovKanal(izbor);
        kanali[1].dodajKorisnika(user);
        write (user->getSocket(), "Kanal: Programming", 18);
        cout << "Kanal: " << kanali[1] << endl;
      } else {
        write (user->getSocket(), "Vec se nalazis u tom kanalu", 27);
      }
    break;
    case SEX:
      izbor = 2;
      if (user->getKorisnikovKanal() != -1 ) {
        cout << "U kanalu Sex :  " << endl;
        napusti_sve_kanale(kanali, *user);
        user->setKorisnikovKanal(-1);
        cout << "Promenio korisnikov kanal na: " << user->getKorisnikovKanal() << endl;
      }
      if(user->getKorisnikovKanal() != 2) {
        user->setKorisnikovKanal(izbor);
        kanali[2].dodajKorisnika(user);
        write (user->getSocket(), "Kanal: Sex", 10);
        cout << "Kanal: " << kanali[2] << endl;
      } else {
        write (user->getSocket(), "Vec se nalazis u tom kanalu", 27);
      }
    break;
    case KOLACI:
      izbor = 3;
      if (user->getKorisnikovKanal() != -1 ) {
        cout << "U kanalu Kolaci :  " << endl;
        napusti_sve_kanale(kanali, *user);
        user->setKorisnikovKanal(-1);
        cout << "Promenio korisnikov kanal na: " << user->getKorisnikovKanal() << endl;
      }
      if(user->getKorisnikovKanal() != 3) {
        user->setKorisnikovKanal(izbor);
        kanali[3].dodajKorisnika(user);
        write (user->getSocket(), "Kanal: Kolaci", 13);
        cout << "Kanal: " << kanali[3] << endl;
      } else {
        write (user->getSocket(), "Vec se nalazis u tom kanalu", 27);
      }
    break;
    case KORISNICI:
    /*cout << "Lista korisnika" << endl;
      broj_korisnika = kanali[user->getKorisnikovKanal()].getKorisnici().size();
      for(int q = 0; q < broj_korisnik; q++) {
        korisnik = kanali[user->getKorisnikovKanal()].getKorisnici()[q].getUsername();
        cout << "korisnik length = " << korisnik.length() << endl;
        konvertovanje(korisnik_char, korisnik);
        cout << "korisnik_char = " << strlen(korisnik_char) << endl;
        cout << korisnik_char << endl;
        write(user->getSocket(), korisnik_char , strlen(korisnik_char));
      }*/
      svi_korisnici(*user);
    break;
    case IZADJI:
    cout << "Poziv na leave" << endl;
      if (user->getKorisnikovKanal() != -1 ) {
        napusti_sve_kanale(kanali, *user);
        user->setKorisnikovKanal(-1);
        cout << "Promenio korisnikov kanal na: " << user->getKorisnikovKanal() << endl;
        write(user->getSocket(), "Napustio kanal", 14);
      }
      else {
        write(user->getSocket(), "Niste ni u jednom kanalu", 24);
      }
    break;
    case POMOC:
    cout << "Pozvali pomoc" << endl;
      sveOpcije(*user);
    break;
    case ERROR:
      cout << "Error - pogresna opcija" << endl;
      write(user->getSocket(), "Pogresna opcija", 15);
      write(user->getSocket(), "Pomoc - /help - /pomoc - /?", 29);
    break;
    default:
    cout << "Pozvao se default" << endl;
      write(user->getSocket(), "Ne znam sta si hteo", 19);
    break;
  }
}

int main(void) {
    int sockfd, new_fd;  // listen on sock_fd, new connection on new_fd
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr; // connector's address information
    socklen_t sin_size;
    struct sigaction sa;
    int yes=1;
    char s[INET6_ADDRSTRLEN];
    int rv;

    kanali.push_back(General);
    kanali.push_back(Programming);
    kanali.push_back(Sex);
    kanali.push_back(Kolaci);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(IP_ADRESS, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // loop through all the results and bind to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("server: socket");
            continue;
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
                sizeof(int)) == -1) {
            perror("setsockopt");
            exit(1);
        }

        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("server: bind");
            continue;
        }

        break;
    }

    freeaddrinfo(servinfo); // all done with this structure

    if (p == NULL)  {
        fprintf(stderr, "server: failed to bind\n");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while(1) {  // main accept() loop
        printf("server: waiting for connections...\n");
        sin_size = sizeof their_addr;
        new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
        if (new_fd == -1) {
            perror("accept");
            continue;
        }
        //std::cout << "Username: " << std::endl;

        inet_ntop(their_addr.ss_family,
            get_in_addr((struct sockaddr *)&their_addr), s, sizeof s);
        //std::cout << "server: got connection from \n" << s << std::endl;

        connected_client[i++] = new_fd;

        pthread_t sniffer_thread;
        int *new_sock = (int*) malloc(sizeof (int));
        *new_sock = new_fd;

        if( pthread_create( &sniffer_thread , NULL ,
          connection_handler , (void*) new_sock) < 0)
        {
            perror("could not create thread");
            return 1;
        }
        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( sniffer_thread , NULL);
        std::cout << "Handler assigned" << std::endl;
      }

    return 0;
}

/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socket_desc) {
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size, j,k,p,len;
    char *message, client_message[2000], nickname[666], *kanaliChar;
    string clanovi;
    char *clanoviChar;
    char *message2 = "General";
    string imeKanala;
    Korisnik *user;
    OPCIJE opcije;

    //Send some messages to the client
    message = "Unesite vas username: \n";
    write(sock , message , strlen(message));
    recv(sock, nickname, 666, 0);
    //user->setUsername(nickname);
    user = new Korisnik(sock, nickname);
    cout << "Korisnikov socket: " << user->getSocket() << endl;
    cout << "Korisnikov username: " << user->getUsername() << endl;
    string skanali = "Unesite broj ili ime zeljenog kanala\n";
    svi_kanali(*user);

    user->prosiriUsername();
    char disconnect[2666];
    char poruka[2666];

//umesto connected_client staviti kanali[izbor].getKorisnik()[i]

    //std::cout << "Username: " << username << std::endl;
    while( (read_size = recv(sock, client_message , 2000 , 0)) > 0 ) {

        client_message[read_size] = '\0';
        //TODO ove gledamo sta je korisnik hteo?
        if(prvo_slovo(client_message) == '/') {
          opcije = prva_rec(client_message);
          izbor_kanala(opcije, &*user);

        }
        //Send the message back to client
        for (j = 0; j < i; j++) {
          //write(sock, username, strlen(username));
          user->konvStrUChar(nickname);
          strcpy(poruka, nickname);
          strcat(poruka, client_message);
          if(prvo_slovo(client_message) != '/' && user->getKorisnikovKanal() != -1) {
            write(kanali[user->getKorisnikovKanal()].getKorisnici()[j].getSocket() , poruka , strlen(poruka));
          }
          if(user->getKorisnikovKanal() == -1) {
            write(user->getSocket() , "Nisi ni u jednom kanalu" , 25);
          }
        }
    }

    if(read_size == 0)
    {
        std::cout << "Client disconnected" << std::endl;
        for (j = 0; j < i-1; j++) {
          strcpy(disconnect, nickname);
          strcat(disconnect, " has disconnected!");
          write(connected_client[j], disconnect, strlen(disconnect));
        }
        napusti_sve_kanale(kanali, *user);
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }

    for (j = 0; j < i-1; j++) {
      if (connected_client[j] == sock) {
        connected_client[j] = connected_client[i-1];
        break;
      }
    }
    i--;

    //Free the socket pointer
    free(socket_desc);
    return 0;
}
