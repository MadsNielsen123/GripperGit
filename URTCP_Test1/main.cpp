#include <QCoreApplication>
#include <iostream>
#include "URTCP.h"
#include <string>
#include <unistd.h>

int main()
{
    URTCP UR;
    while(1)
    {
        UR.waitCommand();
        switch(UR.getCommand())
        {
        case GRIPPER_SET: //set command received
            std::cout << "Set Gripper to: " << UR.getOpenAmount() << std::endl;
            sleep(2);
            UR.URContinue();
            break;

        case GRIPPER_OPEN: //set command received
            std::cout << "Gripper Opens "<< std::endl;
            sleep(2);
            UR.URContinue();
            break;

        case GRIPPER_GRIP: //set command received
            std::cout << "Gripper Grips" << std::endl;
            sleep(3);
            UR.URContinue();
            break;

        default:
            std::cout << "Wrong Command "<< std::endl;
            break;
        }
    }

}
