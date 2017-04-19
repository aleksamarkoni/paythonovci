/*
** client.c -- a stream socket client demo
*/

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <FL/Fl.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <string>
#include <iostream>
#include <fstream>

#define PORT "34512" // the port client will be connecting to
#define IP_ADRESS "92.244.137.93"


#define MAXDATASIZE 1000 // max number of bytes we can get at once

int sockfd;
Fl_Multiline_Output *messagesTextView;

void *cekam_korisnikov_unos(void *);
void *cekam_podatke_sa_server(void *);

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

void posaljiOvoNaServer(const char* text) {
  pthread_t tastatura_thread;
  if( pthread_create( &tastatura_thread , NULL ,  cekam_korisnikov_unos , (void*) text) < 0)
  {
      perror("could not create thread");
  }
}

void send_cb(Fl_Widget* dugme, void*) {
	Fl_Return_Button* b = (Fl_Return_Button*)dugme;
	Fl_Input* in = (Fl_Input*)b->parent()->child(1);
	const char* inText = in->value();
	posaljiOvoNaServer(inText);
  in->value("");
}

void kreirajProzor() {
  Fl_Window * win = new Fl_Window(600, 800, "Chat Client 2.0");
	win->begin();
		Fl_Return_Button *send = new Fl_Return_Button(520, 760, 70, 30, "&Send");
		Fl_Input *inp = new Fl_Input(10, 760, 500, 30, "");
		messagesTextView = new Fl_Multiline_Output(10, 10, 580, 740, "");
	win->end();
	send->callback(send_cb);
	messagesTextView->value("");
	win->show();
}

int main(int argc, char *argv[])
{
    int numbytes;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char *port;
    char s[INET6_ADDRSTRLEN];

    if (argc == 2) {
       port = argv[1];
    } else if (argc == 1) {
       port = PORT;
    } else {
      std::cout << "Imas vise od 2 argumenta komandne linije, to ne valja"
      << std::endl;
      exit(1);
    }

    Fl::lock();
    kreirajProzor();

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(IP_ADRESS, port, &hints, &servinfo)) != 0) {
        std::cout << stderr << "getaddrinfo: \n" << gai_strerror(rv)
        << std::endl;
        return 1;
    }

    // loop through all the results and connect to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("client: connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        return 2;
    }

    inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
            s, sizeof s);
    std::cout << "client: connecting to \n" << s << std::endl;

    freeaddrinfo(servinfo); // all done with this structure

    // ovde smo konektovani na server

    pthread_t server_thread;
    int *new_sock = (int*) malloc(sizeof (int));
    *new_sock = sockfd;

    if( pthread_create( &server_thread , NULL ,  cekam_podatke_sa_server , (void*) new_sock) < 0)
    {
        perror("could not create thread");
        return 1;
    }

    int result = Fl::run();

    //TODO ubi tredove koje smo kreirali

    close(sockfd);

    return result;
}

void *cekam_korisnikov_unos(void *text) {
  const char* poruka = (const char *) text;
  std::cout << "Saljemo poruku na server\n" << std::endl;
  //Send text to the server
  if( send(sockfd , poruka , strlen(poruka) , 0) < 0) {
      puts("Send failed");
    }
}

void *cekam_podatke_sa_server(void *socket_desc) {
  //Get the socket descriptor
  int sock = *(int*)socket_desc;
  int r;
  char server_replay[MAXDATASIZE];

  while(1)
  {
      //Receive a reply from the server
      r = recv(sock , server_replay , MAXDATASIZE-1 , 0);
      if (r < 0) {
          puts("recv failed");
          break;
      }

      server_replay[r] = '\0';

      Fl::lock();
      const char* messagesText = messagesTextView->value();
    	std::cout << server_replay << std::endl;
    	std::string inString(server_replay);
    	std::string messagesTextString(messagesText);
    	messagesTextView->value((messagesTextString + "\n" + inString).c_str());
      Fl::unlock();
      Fl::awake();
  }
}
