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

using namespace std;

#define PORT "34510" // the port client will be connecting to
#define IP_ADRESS "192.168.0.151"
#define BACKLOG 10     // how many pending connections queue will hold

int connected_client[100];
int i = 0;
string ispis;
enum OPCIJE {
  LISTA_KANALA,
  GENERAL,
  PROGRAMMING,
  SEX,
  KOLACI,
  ERROR
};

class Korisnik;

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

  //Korisnik getUserUKanalu(Korisnik &user) {
  //  return korisnici.user;
  //}
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

class Korisnik {
private:
  int sock;
  string username;
  int korisnikovKanal = -1;
public:
  Korisnik() {}
  Korisnik(int sock, char *username) {
    setSocket(sock);
    setUsername(username);
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

ostream& operator<<(ostream &out, Korisnik &user) {
  //probajte ovo
  out << user.getUsername() << endl;
  return out;
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
//void *user() {
//
//}

void napusti_kanal(vector<Kanal> kanali, Korisnik &user) {
  for(int j = 0; j < i; j++) {
    for(int k = 0; k < i; k++)
    if(kanali[j].getKorisnici()[k].getSocket() == user.getSocket()) {
      kanali[j].getKorisnici().erase(kanali[j].getKorisnici().begin() + k);
      cout << "Korisnik: " << kanali[j].getKorisnici()[k].getUsername() <<
       " je napustio " << kanali[j] << endl;
    }
  }
}




char prvo_slovo(char *message) {
  return message[0];
}

OPCIJE prva_rec(char *message) {
  string str1 = message;
  size_t pos = str1.find(" ");
  string str2 = str1.substr(0, pos);
  if(str2 == "/lista") {
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
  kanaliChar[len] = '\0';
  //cout << kanaliChar << endl;
  write(user.getSocket(), kanaliChar, strlen(kanaliChar));
}

void izbor_kanala(OPCIJE opcije, Korisnik *user) {
  int j, izbor;
  cout << "Izbor: " << opcije << endl;
  switch(opcije) {
    case LISTA_KANALA:
      svi_kanali(*user);
    break;
    case GENERAL:
    izbor = 0;
    if (user->getKorisnikovKanal() != -1 ) {
      //for(j = 0; j < i; j++) {
    //    if(!(kanali[j].getKorisnici().empty())) {
          cout << "U kanalu_General :  " << endl;
          napusti_kanal(kanali, *user);
            cout << "Napustio kanal General :  " << endl;

        //  cout << kanali[0].getKorisnici()[j].getUsername() << endl;
        //}
      }
      user->setKorisnikovKanal(izbor);

      kanali[0].dodajKorisnika(user);
      cout << "Kanal: " << kanali[0] << endl;
      for (j = 0; j < i; j++) {
        cout << "Upisao se: " << kanali[0].getKorisnici()[j].getUsername() << endl;
      }
    break;
    case PROGRAMMING:
    izbor = 1;
      if (user->getKorisnikovKanal() != -1 ) {
  //  for(j = 0; j < i; j++) {
  //    if(!(kanali[j].getKorisnici().empty())) {
      cout << "U kanalu Programing :  " << endl;
        napusti_kanal(kanali, *user);
        cout << "Napustio kanal Programing :  " << endl;
      }
      user->setKorisnikovKanal(izbor);
  //  }
    kanali[1].dodajKorisnika(user);
    cout << "Kanal: " << kanali[1] << endl;
    for (j = 0; j < i; j++) {
      cout << "Upisao se: " << kanali[1].getKorisnici()[j].getUsername() << endl;
    }
    break;
    case SEX:
    izbor = 2;
    for(j = 0; j < i; j++) {
      if(!(kanali[j].getKorisnici().empty())) {
        napusti_kanal(kanali, *user);
      }
    }
    kanali[2].dodajKorisnika(user);
    cout << "Kanal: " << kanali[2] << endl;
    for (j = 0; j < i; j++) {
      cout << "Upisao se: " << kanali[2].getKorisnici()[j].getUsername() << endl;
    }
    break;
    case KOLACI:
    izbor = 3;
    for(j = 0; j < i; j++) {
      if(!(kanali[j].getKorisnici().empty())) {
        napusti_kanal(kanali, *user);
      }
    }
    kanali[3].dodajKorisnika(user);
    cout << "Kanal: " << kanali[3] << endl;
    for (j = 0; j < i; j++) {
      cout << "Upisao se: " << kanali[3].getKorisnici()[j].getUsername() << endl;
    }
    break;
    case ERROR:
      write(user->getSocket(), "Pogresna opcija", 15);
      svi_kanali(*user);
    break;
    default:
      write(user->getSocket(), "Ne znam sta si hteo", 19);
      svi_kanali(*user);
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
    //string disconnect, poruka;

//umesto connected_client staviti kanali[izbor].getKorisnik()[i]

    //std::cout << "Username: " << username << std::endl;
    while( (read_size = recv(sock, client_message , 2000 , 0)) > 0 ) {

        client_message[read_size] = '\0';
        //TODO ove gledamo sta je korisnik hteo?
        if(prvo_slovo(client_message) == '/') {
          opcije = prva_rec(client_message);
          izbor_kanala(opcije, &*user);
        }

          //client_message[0] = "";
          //recv(sock, client_message, 2000, 0);
          //client_message[read_size] = '\0'
        /*
        // izdvoj prvu rec, pronadjem prvu prazninu, substrin(0, prve beline)
        if (prva_rec == "/lista_kanala") {
          posalji_klientu_sve_kanale();
        } else if (prva_rec == /udji_u_kanal) {
         // izdvoj drugu rec u recenici /udji_u_kanal sex
         for (int i=0; i < kanali.length(); i++) {
           if (kanali[i].imeKanala == druga_rec) {
             korisnikovKanal = &kanali[i];
             dodaj korisnika u kanal i to je to
         }
         // nema tog kanala, onda prijavljujem gresku
       } else {
       for (int i = 0; i < kanali.length(); i++) {
          for (int j = 0; j < kanali[i].korisnici.length(); j++) {
            if (kanali[i].korisnici[j].sock == sock) {
              //pronasao sam kanal u kome je korisnki
              kanal = korisnikKanal;
          }
        }
        for (int i =0; *korisnikKanal->getKorisniki().length(); i++) {

      }
     }
     }
         //
      }

        */
        //Send the message back to client
        for (j = 0; j < i; j++) {
          //write(sock, username, strlen(username));
          user->konvStrUChar(nickname);
          strcpy(poruka, nickname);
          strcat(poruka, client_message);
          write(connected_client[j] , poruka , strlen(poruka));
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
