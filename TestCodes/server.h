#ifndef SERVER_H
#define SERVER_H

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

enum Command
{
    GRIPPER_INIT,
    GRIPPER_EXIT,
    GRIPPER_OPEN,    
    GRIPPER_GRIP

    //PC-TODO
};

class Server
{
public:
    Server();
    void terminate();
    void URContinue();
    void waitConnection();
    void waitCommand();
    bool isConnected() const;
    bool isUR() const;
    Command getCommand() const;

private:
    std::string clientRead();
    void clientWrite(std::string msg);

    char buff[MAX];
    int sockfd, connfd;
    socklen_t len;
    struct sockaddr_in servaddr, cli;
    Command mCommand;

    bool mIsConnected;
    bool mIsUR;

};

#endif // SERVER_H
