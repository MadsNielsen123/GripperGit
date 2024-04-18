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
#include "errno.h"

#define MAX 80
#define PORT 2024
#define SA struct sockaddr

//static int opt = 1;

URTCP::URTCP()
{
    std::cout << "debug msg" << std::endl;
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cout << "socket creation failed...\n";
        exit(1);
    }
    else
        std::cout << "Socket successfully created.." << std::endl;
    bzero(&servaddr, sizeof(servaddr)); //Reset address before assigning

    /*// Forcefully attaching socket to the port 2024
    if (setsockopt(sockfd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }*/
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    int a = bind(sockfd, (SA*)&servaddr, sizeof(servaddr));
    if(a<0)
    {
        perror("bind");
        std::cout << "\n\n" << errno << '\n';
        std::cout << sockfd << '\n';
        std::cout << servaddr.sin_addr.s_addr << '\n';
        std::cout << sizeof(servaddr) << "\n\n";
    }


    // Binding newly created socket to given IP and verification
    if (a != 0) {
        std::cout << "socket bind failed..." << std::endl;
        exit(1);
    }
    else
        std::cout << "Socket successfully binded.." << std::endl;

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        std::cout << "Listen failed..." << std::endl;
        exit(1);
    }
    else
        std::cout << "Server listening.." << std::endl;

    len = sizeof(cli);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        std::cout << "server accept failed..." << std::endl;
        exit(0);
    }
    else
        std::cout << "server accept the client..." << std::endl;

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
    std::cout << msg << std::endl;
    char const* out = msg.c_str();
    write(connfd, out, sizeof(out));
}

void URTCP::gripperContinue()
{
    //gripperWrite("continue");
    char out[2];
    out[0]='a';
    out[1]='\n';
    write(connfd, out, 2);
}

void URTCP::gripperTerminate()
{
    close(connfd);
    close(sockfd);
}
