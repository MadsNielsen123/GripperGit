#ifndef URTCP_H
#define URTCP_H
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

enum Command
{
    GRIPPER_CLOSE,
    GRIPPER_OPEN,
    GRIPPER_SET,
    GRIPPER_EXIT,
    GRIPPER_GRIP

    //todo with PC commands
};

class URTCP
{
public:
    URTCP();
    void URTerminate();
    void URContinue();
    void waitConnection();

    void waitCommand();
    unsigned int getOpenAmount() const;
    bool isConnected() const;
    bool isGripper() const;
    Command getCommand() const;

private:
    std::string URRead();
    void URWrite(std::string msg);
    char buff[MAX];
    int sockfd, connfd;
    socklen_t len;
    struct sockaddr_in servaddr, cli;

    unsigned int mOpenAmount;
    bool mIsConnected;
    bool gripperMode;
    Command mCommand;

};

#endif // URTCP_H
