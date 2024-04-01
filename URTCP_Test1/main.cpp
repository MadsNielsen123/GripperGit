#include <QCoreApplication>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()
#include <iostream>

#define MAX 80
#define PORT 2024
#define SA struct sockaddr

int main(int argc, char *argv[])
{
    int sockfd, connfd;
    socklen_t len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(1);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr)); //Reset address before assigning

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(1);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(1);
    }
    else
        printf("Server listening..\n");

    len = sizeof(cli);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");

    char buff[MAX];

    // infinite loop for chat
    while(true) {
        bzero(buff, MAX); //Clear buffer

        // read the message from client and copy it in buffer
        read(connfd, buff, sizeof(buff));

        std::string str(buff);
        std::cout << str << std::endl;

        bzero(buff, MAX); //Clear buffer
        // and send that buffer to client
        buff[0] = 'u';
        buff[1] = 'p';
        buff[2] = '\n';

        write(connfd, buff, sizeof(buff));
        close(connfd);
        break;
    }

    // After chatting close the socket
    close(sockfd);

    return 0;
}
