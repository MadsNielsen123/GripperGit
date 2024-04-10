#include <QCoreApplication>
#include <iostream>
#include "URTCP.h"

int main()
{
    URTCP robot;
    while (1)
    {
        robot.gripperContinue();
        std::cout << robot.gripperRead();
    }

}
