//#include <QCoreApplication>
#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()
#include <iostream>
#define MAX 80
#define PORT 2024
#define SA struct sockaddr

void serverWrite(int sockfd)
{
    char buff[MAX];
    char ack[MAX];
    ack[0] = 'a'; ack[1]='c'; ack[2]='k';
    bzero(buff, sizeof(buff));
    int n;
    buff[0] = 'P'; buff[1] = 'C';
    write(sockfd,buff,sizeof(buff));
    std::cout << "What would you like to query?\n\
    exit(exit)\n\
    Get last 10 sessions(getSessions)\n\
    Get last 10 grips(getGrips)\n\
    Get average object size(getSize)\n\
    Get average grip duration(getGripDuration)\n\
    Get average session duration(getSessionDuration)" << std::endl;
    bzero(buff, sizeof(buff));
    printf("Enter the string : ");
    n = 0;
    char temp;

    while ((temp = getchar()) != '\n')
    {
        buff[n++] = temp;
    }
    write(sockfd, buff, sizeof(buff));
    for (;;)
    {
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s", buff);
        if(!strncmp(buff,"invalid command",15) || !strncmp(buff,"done",4))
        {
            std::cout << "\nWhat would you like to query?\n\
            exit(exit)\n\
            Get last 10 sessions(getSessions)\n\
            Get last 10 grips(getGrips)\n\
            Get average object size(getSize)\n\
            Get average grip duration(getGripDuration)\n\
            Get average session duration(getSessionDuration)" << std::endl;
            bzero(buff, sizeof(buff));
            n=0;
            temp = '\0';
            while ((temp = getchar()) != '\n')
            {
                buff[n++] = temp;
            }
            write(sockfd, buff, sizeof(buff));
            continue;
        }

        if (!strncmp(buff, "exit", 4))
        {
            printf("Client Exit...\n");
            break;
        }

        bzero(buff, sizeof(buff));
        write(sockfd,ack,sizeof(ack));
    }
}

int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //servaddr.sin_addr.s_addr = inet_addr("192.168.1.69");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)))
    {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");

    // function for chat
    serverWrite(sockfd);

    // close the socket
    close(sockfd);

}
