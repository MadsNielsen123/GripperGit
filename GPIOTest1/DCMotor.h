#ifndef DCMOTOR_H
#define DCMOTOR_H
#include <pigpio.h>
#include <unistd.h> // For sleep functions usleep and nanosleep)

#define MRIGHT 0
#define MLEFT 1

class DCMotor
{
public:

    DCMotor(unsigned int gpioPinDir0, unsigned int gpioPinDir1, unsigned gpioPinEna);
    ~DCMotor()
    {
        stopMotor();
        gpioWrite(mGpioPinDir0, 0);
        gpioWrite(mGpioPinDir1, 0);
        usleep(100000);    // Wait for 100 milliseconds for gpioTerminate to be ready
        gpioTerminate(); //Reset gpio, ram ect. after program done
    }

    void setupHomeSwitch(unsigned int gpioPinHomeSW); //Switch to stop motor
    void setupLimitSwitch(unsigned int gpioPinLimitSW); //Switch to stop motor
    void stop();
    void run(unsigned int speed = 100); //Default Full Speed
    void setDir(bool dir);
    void changeDir();

    bool homeSWPressed() const;
    bool limitSWPressed() const;

private:
    bool mDir = 0; //Default direction
    unsigned int mGpioPinDir0, mGpioPinDir1 , mGpioPinEna;
    bool mHomeSWHit, mLimitSWHit, mMotorRunning = false;
};

#endif // DCMOTOR_H
