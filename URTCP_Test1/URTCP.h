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


class URTCP
{
    public:
        URTCP();
        void gripperTerminate();
        std::string gripperRead();
        void gripperContinue();
    private:
        void gripperWrite(std::string msg);
};

#endif // URTCP_H
