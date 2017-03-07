/*
** client.c -- a stream socket client demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#define PORT "34567" // the port client will be connecting to
#define IP_ADRESS "92.244.137.93"

#define MAXDATASIZE 1000 // max number of bytes we can get at once

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[])
{
    int sockfd, numbytes;
    char message[MAXDATASIZE], server_reply[MAXDATASIZE];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(IP_ADRESS, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
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
    printf("client: connecting to %s\n", s);

    freeaddrinfo(servinfo); // all done with this structure

    //greatings message
    int r = recv(sockfd , server_reply , MAXDATASIZE-1 , 0);
    if (r < 0) {
        puts("recv failed");
    }

    server_reply[r] = '\0';

    puts(server_reply);


    //now type something message
    r = recv(sockfd , server_reply , MAXDATASIZE-1 , 0);
    if (r < 0) {
        puts("recv failed");
    }

    server_reply[r] = '\0';

    puts(server_reply);


    while(1)
    {
        printf("Enter message : ");
        scanf("%s" , message);
        printf("Saljemo na server: %s\n", message);

        //Send some data
        if( send(sockfd , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }

        //Receive a reply from the server
        r = recv(sockfd , server_reply , MAXDATASIZE-1 , 0);
        if (r < 0) {
            puts("recv failed");
            break;
        }

        server_reply[r] = '\0';

        puts("Server reply :");
        puts(server_reply);
    }

    close(sockfd);

    return 0;
}
