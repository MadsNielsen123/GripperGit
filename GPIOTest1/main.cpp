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

    // -----------------  Motor control without switches ----------------

    // RUNNING MOTOR
    motor.run();
    usleep(500000);    // Wait for 0,5s
    motor.stop();

    // MOTOR DIRECTION
    motor.setDir(1); // Set motor direction [0 / 1] Default:0
    motor.setDir(MLEFT); // Alternative [MRIGHT / MLEFT]
    motor.changeDir(); //changes direction

    // MOTOR CAN CHANGE DIRECTION WHILE RUNNING. IT WILL COME TO FULL STOP SHORTLY AND THEN CONTINUE IN OTHER DIRECTION
    motor.run();
    usleep(500000);
    motor.changeDir();
    usleep(500000);
    motor.stop();

    //REDUCED SPEED
    motor.run(60); //Runs motor at ~60% speed (60% duty cycle) -Default:100%
    usleep(500000);    // Wait for 0,5s
    motor.stop();


    // -----------------  Motor control with micro switches ----------------
    //*** Still normal motor control, but switches will stop the motor automatically ***

    //SETUP
    motor.setupHomeSwitch(HOME_SW_PIN);
    motor.setupLimitSwitch(LIMIT_SW_PIN);

    //WAIT FOR SWITCH PRESSED (MOTOR STOPS AUTOMATICALLY)
    motor.run();
    while(!motor.homeSWPressed() || !motor.limitSWPressed())
    {
        //Wait til home switch or limit switch is pressed.
    }

    //MOTOR RUN RIGHT AFTER SWITCH PRESS;
    motor.run(); //Motor direction will automatically change before running


    return 0;
}
