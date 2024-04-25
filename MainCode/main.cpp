#include <QCoreApplication>
#include <iostream>
#include <iostream>
#include <URTCP.h>
#include <DCMotor.h>

#define DIR_0_PIN 24
#define DIR_1_PIN 25
#define ENA_PIN 23
#define HOME_SW_PIN 17
#define LIMIT_SW_PIN 27

int main()
{
    URTCP UR;
    DCMotor motor(DIR_0_PIN, DIR_1_PIN, ENA_PIN);
    motor.setupHomeSwitch(HOME_SW_PIN);
    motor.setupLimitSwitch(LIMIT_SW_PIN);

    while(true)
    {
        if(motor.limitSWPressed())
                break;
    }

    std::cout << "limit pressed" << std::endl;

    return 0;
}
