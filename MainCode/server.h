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
#include <vector>


#define MAX 80
#define PORT 2024
#define SA struct sockaddr

enum Command
{
    GRIPPER_INIT,
    GRIPPER_EXIT,
    GRIPPER_OPEN,    
    GRIPPER_GRIP,

    PC_EXIT,
    GET_LAST_GRIPS,
    GET_LAST_SESSIONS,
    GET_AVERAGE_SIZE,
    GET_AVERAGE_SESSION_DURATION,
    GET_AVERAGE_GRIP_DURATION
};

class Server
{
public:
    Server();
    void terminate();
    void clientContinue();
    void waitConnection();
    void waitCommand();
    bool isConnected() const;
    bool isUR() const;
    Command getCommand() const;
    void sendData(std::vector<std::string>& data);

private:
    std::string clientRead();
    void clientWrite(const std::string& msg);

    char buff[MAX];
    int sockfd, connfd;
    socklen_t len;
    struct sockaddr_in servaddr, cli;
    Command mCommand;

    bool mIsConnected = 0;
    bool mIsUR = 0;

};

#endif // SERVER_H
