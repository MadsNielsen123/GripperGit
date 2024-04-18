#include <QCoreApplication>
#include <iostream>
#include "URTCP.h"
#include <string>
#include <unistd.h>

int main()
{
    std::string mesg;
    URTCP robot;
    while (1)
    {
        std::string temp = robot.gripperRead();
        if(temp != "")
        {
            mesg = temp;
        }
        if(mesg == "100")
        {
            std::cout << "working" << std::endl;
            std::cout << mesg << std::endl;
            sleep(5);
            robot.gripperContinue();
        }
        std::cout << mesg << std::endl;


        /*msg = robot.gripperRead();
        if(msg != "")
            robot.gripperContinue();

        std::cout << msg;
        msg = "";*/
    }

}
