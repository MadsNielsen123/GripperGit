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
}

void URTCP::waitConnection()
{
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
    if(URRead() == "UR")
        gripperMode = 1;//read what device is connected. send info regarding which device is connected upon device connection.

}

std::string URTCP::URRead()
{
    bzero(buff, MAX); //Clear buffer

    // read the message from client and copy it in buffer
    read(connfd, buff, sizeof(buff));

    std::string msg(buff);
    return msg;
}

unsigned int URTCP::getOpenAmount() const {return mOpenAmount;}

void URTCP::URWrite(std::string msg)
{
    msg += "\n";
    std::cout << msg << std::endl;
    char const* out = msg.c_str();
    write(connfd, out, sizeof(out));
}

void URTCP::URContinue()
{
    char out[2];
    out[0]='h';
    out[1]='\n';
    write(connfd, out, sizeof(out));
    //URWrite("continue");
}

void URTCP::URTerminate()
{
    close(connfd);
    close(sockfd);
}

bool URTCP::isConnected() const
{
    return mIsConnected;
}

bool URTCP::isGripper() const
{
    return gripperMode;
}

Command URTCP::getCommand() const
{
    return mCommand;
}

void URTCP::waitCommand()
{
    std::string command = URRead();
    std::cout << command << std::endl;

    //todo with PC commands
    if(command == "exit")
    {
        mIsConnected = false;
        URTerminate();
        mCommand = GRIPPER_EXIT;
        return;
    }

    if(command == "grip")
    {
        mCommand = GRIPPER_GRIP;
        return;
    }


    //Else Command must be a set-value (integer)
    if(std::stoi(command) > 99)
    {
        mCommand = GRIPPER_OPEN;
        return;
    }

    //Further Implementations ...
}
