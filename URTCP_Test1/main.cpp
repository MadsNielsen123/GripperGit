#include <QCoreApplication>
#include <iostream>
#include "URTCP.h"
#include <string>
#include <unistd.h>

int main()
{

    URTCP Server;
    Server.waitConnection();
    while(Server.isGripper())
    {
        Server.waitCommand();
        switch(Server.getCommand())
        {
        case GRIPPER_SET: //set command received
            std::cout << "Set Gripper to: " << Server.getOpenAmount() << std::endl;
            sleep(2);
            Server.URContinue();
            break;

        case GRIPPER_OPEN: //set command received
            std::cout << "Gripper Opens "<< std::endl;
            sleep(2);
            Server.URContinue();
            break;

        case GRIPPER_GRIP: //set command received
            std::cout << "Gripper Grips" << std::endl;
            sleep(3);
            Server.URContinue();
            break;

        default:
            std::cout << "Wrong Command "<< std::endl;
            break;
        }
    }

    while(!Server.isGripper())
    {
        switch(Server.getCommand())
        {
        //todo with PC commands


        }
    }
}
