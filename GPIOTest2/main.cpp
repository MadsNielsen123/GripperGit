#include <QCoreApplication>
#include <exception>
#include <iostream>
#include "DCMotor.h" //GPIO/MotorControl Class - SemesterProjekt

//Aliases for the raspberry pi pinout (Change accordingly)
#define DIR0_PIN 17
#define DIR1_PIN 27
#define ENA_PIN 22

#define HOME_SW_PIN 6
#define LIMIT_SW_PIN 5

int main()
{

    std::cout << "Testing... " << std::endl;
    //MOTOR SETUP
    DCMotor motor(DIR0_PIN, DIR1_PIN, ENA_PIN);
    motor.setupLimitSwitch(LIMIT_SW_PIN);
    motor.setupHomeSwitch(HOME_SW_PIN);

    motor.run();
    motor.setDir(0);


    /*
    unsigned int count = 0;
    while(count < 20)
    {
        if(motor.homeSWPressed())
        {

            motor.setDir(CLOSE);
            motor.run();
            //count++;
            std::cout << "Home pressed" << std::endl;
            while(motor.homeSWPressed())
            {
                //Do nothing
            }
            motor.stop();
        }

        if(motor.limitSWPressed())
        {
            motor.setDir(OPEN);
            motor.run();
            //count++;
            std::cout << "LimitSwitch Pressed" << std::endl;
            while(motor.limitSWPressed())
            {
                //Do nothing
            }
            break;
        }      
    }
    motor.stop();
    */
    usleep(5000000);
    motor.stop();
    std::cout << "Done" << std::endl;
    return 0;
}
