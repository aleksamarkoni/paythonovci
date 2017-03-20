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

#define PORT "34503" // the port client will be connecting to
#define IP_ADRESS "192.168.0.151"
#define BACKLOG 10     // how many pending connections queue will hold

int connected_client[100];
int i = 0;
string ispis;
vector<Kanal> kanali;

class Korisnik {
private:
  int sock;
  char username[666];
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
      strcpy(this->username, username);
  }
  int getSocket() {
    return sock;
  }
  char getUsername() {
    return *username;
  }
  string printUsername() {
    //string ispis(username)
    for (int p = 0; p < strlen(username); p++) {
      ispis += username[p];
    }
    return ispis;
  }
  friend ostream& operator<<(ostream &out, const Korisnik &user);
};

ostream& operator<<(ostream &out, Korisnik &user) {
  //probajte ovo
  out << user.username << endl;
  return out;
}

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
  void dodajKorisnika(Korisnik &user) {
    korisnici.push_back(user);
  }
  string getImeKanala() {
    return this->ime;
  }
  vector<Korisnik> getKorisnik() {
    return this->korisnici;
  }

  friend ostream& operator<<(ostream &out, Kanal &kanal);
};

ostream& operator<<(ostream &out, Kanal &kanal) {
  //TODO
  out << kanal.imeKanala << endl;
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
void *user() {

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
    int read_size, j;
    char *message , client_message[2000], username[666];
    string imeKanala;
    Korisnik *user;
    Kanal *korisnikovKanal = NULL;
    Kanal general("General");
    Kanal Programming("Programming");
    Kanal Sex("Sex");
    Kanal Kolaci("Kolaci");

    //Send some messages to the client
    message = "Unesite vas username: \n";
    write(sock , message , strlen(message));
    recv(sock, username, 666, 0);
    user = new Korisnik(sock, username);
    cout << "Korisnikov socket: " << user->getSocket() << endl;
    cout << "Korisnikov username: " << user->printUsername() << endl;
    string skanali;
    for (int i = 0; i < kanali; i++) {
      skanali += kanali[i].imeKanala;
    }
    int len = skanali.length();
    write(sock, skanali.c_str(), strlen(message));
    recv(sock, client_message, 2000, 0);
    int izbor = atoi(client_message);
    cout << "Izbor: " << izbor << endl;
    switch(izbor) {
      case 1:
        kanali.push_back(general);
        kanali[0].dodajKorisnika(*user);
        cout << "Kanal: " << kanali[0] << endl;
        for (j = 0; j < i; j++) {
          cout << kanali[0].getKorisnik()[i].printUsername() << endl;
        }
      break;
      case 2:
        kanali.push_back(Programming);
        kanali[1].dodajKorisnika(*user);
        cout << "Kanal: " << kanali[1] << endl;
        for (j = 0; j < i; j++) {
          cout << kanali[1].getKorisnik()[i].printUsername() << endl;
        }
      break;
      case 3:
        //kanali.push_back(Sex);
        //kanali[2].dodajKorisnika(*user);
      break;
      case 4:
        //kanali.push_back(Kolaci);
        //kanali[3].dodajKorisnika(*user);
      break;

    }
    strcat(username, ":");
    strcat(username, " ");
    char disconnect[2666];
    char poruka[2666];

//umesto connected_client staviti kanali[izbor].getKorisnik()[i]

    //std::cout << "Username: " << username << std::endl;
    while( (read_size = recv(sock, client_message , 2000 , 0)) > 0 ) {

        client_message[read_size] = '\0';
        //TODO ove gledamo sta je korisnik hteo?
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
          strcpy(poruka, username);
          strcat(poruka, client_message);
          write(connected_client[j] , poruka , strlen(poruka));
        }
    }

    if(read_size == 0)
    {
        std::cout << "Client disconnected" << std::endl;
        for (j = 0; j < i-1; j++) {
          strcpy(disconnect, username);
          strcat(disconnect, "disconnected!");
          write(connected_client[j], disconnect, strlen(disconnect));
          delete user;
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
