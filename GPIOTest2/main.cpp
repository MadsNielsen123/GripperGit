#include <QCoreApplication>
#include <iostream>
#include "DCMotor.h" //GPIO/MotorControl Class - SemesterProjekt

//Aliases for the raspberry pi pinout (Change accordingly)
#define DIR_0_PIN 23
#define DIR_1_PIN 24
#define ENA_PIN 25

#define HOME_SW_PIN 17
#define LIMIT_SW_PIN 27

int main(int argc, char *argv[])
{
    //MOTOR SETUP
    DCMotor motor(DIR_0_PIN, DIR_1_PIN, ENA_PIN);
    motor.setupLimitSwitch(LIMIT_SW_PIN);
    motor.setupHomeSwitch(HOME_SW_PIN);

    std::string line;
    std::getline(std::cin, line);

    std::cout << "limit Status " << motor.limitSWPressed() << std::endl;
    std::cout << "home status " << motor.homeSWPressed() << std::endl;

    return 0;
}
