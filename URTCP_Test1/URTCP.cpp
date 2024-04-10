#include "URTCP.h"
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
char buff[MAX];
int sockfd, connfd;
socklen_t len;
struct sockaddr_in servaddr, cli;

URTCP::URTCP()
{
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cout << "socket creation failed...\n";
        exit(1);
    }
    else
        std::cout << "Socket successfully created..\n";
    bzero(&servaddr, sizeof(servaddr)); //Reset address before assigning

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        std::cout << "socket bind failed...\n";
        exit(1);
    }
    else
        std::cout << "Socket successfully binded..\n";

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        std::cout << "Listen failed...\n";
        exit(1);
    }
    else
        std::cout << "Server listening..\n";

    len = sizeof(cli);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        std::cout << "server accept failed...\n";
        exit(0);
    }
    else
        std::cout << "server accept the client...\n";

}

std::string URTCP::gripperRead()
{
    bzero(buff, MAX); //Clear buffer

    // read the message from client and copy it in buffer
    read(connfd, buff, sizeof(buff));

    std::string msg(buff);
    return msg;
}

void URTCP::gripperWrite(std::string msg)
{
    char const* out = msg.c_str();
    write(connfd, out, sizeof(out));
}

void URTCP::gripperContinue()
{
    gripperWrite("continue");
}

void URTCP::gripperTerminate()
{
    close(connfd);
    close(sockfd);
}