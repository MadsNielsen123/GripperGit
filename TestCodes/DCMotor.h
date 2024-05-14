#ifndef DCMOTOR_H
#define DCMOTOR_H
#include <pigpio.h>
#include <unistd.h> // For sleep functions usleep and nanosleep)
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

    void stop();
    void run(unsigned int speed = 100); //Default Full Speed
    void setDir(bool dir);
    void changeDir();

    bool homeSWPressed() const;
    bool limitSWPressed() const;

private:
    static void homeSwitchStateChange(int gpio, int level, uint32_t tick);
    static void limitSwitchStateChange(int gpio, int level, uint32_t tick);
    bool mDir = 0; //Default direction
    bool mMotorRunning = false;
    unsigned int mGpioPinDir0, mGpioPinDir1 , mGpioPinEna;
    static std::chrono::steady_clock::time_point mLast_isr_time_homesw, mLast_isr_time_limitsw;
    static bool mHomeSWHit, mLimitSWHit;
};

#endif // DCMOTOR_H
