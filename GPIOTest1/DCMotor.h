#ifndef DCMOTOR_H
#define DCMOTOR_H
#include <pigpio.h>
#include <chrono>

#define MRIGHT 0
#define MLEFT 1

class DCMotor
{
public:

    DCMotor(unsigned int gpioPinDir0, unsigned int gpioPinDir1, unsigned gpioPinEna);
    ~DCMotor();

    void setupHomeSwitch(unsigned int gpioPinHomeSW); //Switch to stop motor
    void setupLimitSwitch(unsigned int gpioPinLimitSW); //Switch to stop motor
    void homeSwitchStateChange(int gpio, int level, uint32_t tick);
    void limitSwitchStateChange(int gpio, int level, uint32_t tick);
    void stop();
    void run(unsigned int speed = 100); //Default Full Speed
    void setDir(bool dir);
    void changeDir();

    bool homeSWPressed() const;
    bool limitSWPressed() const;

private:
    bool mDir = 0; //Default direction
    unsigned int mGpioPinDir0, mGpioPinDir1 , mGpioPinEna;
    bool mHomeSWHit = false, mLimitSWHit = false, mMotorRunning = false;
    std::chrono::steady_clock::time_point mLast_isr_time_homesw, mLast_isr_time_limitsw;

    void limitSwitchHit();
    void homeSwitchHit();
};

#endif // DCMOTOR_H
