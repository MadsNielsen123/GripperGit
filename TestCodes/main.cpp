#include <QCoreApplication>
#include <iostream>
#include <server.h>
#include <GripperController.h>
#include <Db.h>

int main()
{
    //Test Connection ------------------------------------------------------------------------------
    /*
    Server server;
    server.waitConnection();

    if(server.isUR())
    {
        std::cout << "UR Connected!" << std::endl;
    }
    else
    {
        std::cout << "PC Connected!" << std::endl;
    }
    server.terminate();
    */

    //Test Switches -------------------------------------------------------------------------------

    /*
    #define DIR0_PIN 17
    #define DIR1_PIN 27
    #define ENA_PIN 22
    #define HOME_SW_PIN 6
    #define LIMIT_SW_PIN 5
    DCMotor motor(DIR0_PIN, DIR1_PIN, ENA_PIN);
    motor.setupHomeSwitch(HOME_SW_PIN);
    motor.setupLimitSwitch(LIMIT_SW_PIN);



    while(true)
    {
        if(motor.limitSWPressed())
        {
            std::cout << "Limit Switch Pressed" << std::endl;
            break;
        }

        if(motor.homeSWPressed())
        {
            std::cout << "Home Switch Pressed" << std::endl;
            break;
        }

    }

    */


    //Test Motor ---------------------------------------------------------------------------------

    GripperController gripper;
    gripper.open();
    sleep(2);
    gripper.grip();


    return 0;
}
