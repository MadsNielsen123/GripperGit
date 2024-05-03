#include <QCoreApplication>
#include "GripperController.h"
#include <iostream>

int main()
{
    std::cout << "Grip 10 times" << std::endl;
    GripperController gripper;
    for(int i = 0; i< 10; i++)
    {
        gripper.grip();
        usleep(1000000);
        gripper.open();
        usleep(1000000);
    }
    std::cout << "Done" << std::endl;

    return 0;
}
