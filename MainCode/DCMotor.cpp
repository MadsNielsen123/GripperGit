#include "DCMotor.h"
#include <iostream>

bool DCMotor::mHomeSWHit = false;
bool DCMotor::mLimitSWHit = false;
std::chrono::steady_clock::time_point DCMotor::mLast_isr_time_homesw;
std::chrono::steady_clock::time_point DCMotor::mLast_isr_time_limitsw;

DCMotor::DCMotor(unsigned int gpioPinDir0, unsigned int gpioPinDir1, unsigned gpioPinEna)
{
    gpioInitialise();
    mGpioPinDir0 = gpioPinDir0;
    mGpioPinDir1 = gpioPinDir1;
    mGpioPinEna = gpioPinEna;
    gpioSetMode(gpioPinDir0, PI_OUTPUT);
    gpioSetMode(gpioPinDir1, PI_OUTPUT);
    gpioSetMode(gpioPinEna, PI_OUTPUT);
    gpioSetPWMrange(gpioPinEna, 100); //0-100%
    gpioSetPWMfrequency(gpioPinEna, 500); //500Hz
    gpioWrite(mGpioPinDir0, mDir); //Set dir
    gpioWrite(mGpioPinDir1, !mDir); //Set dir
    mHomeSWHit = false;
    mLimitSWHit = false;
    mMotorRunning = false;
}

DCMotor::~DCMotor()
{
    stop();
    std::cout << "GPIO END" << std::endl;
    gpioWrite(mGpioPinDir0, 0);
    gpioWrite(mGpioPinDir1, 0);
    gpioWrite(mGpioPinEna, 0);
    usleep(100000);    // Wait for 100 milliseconds for gpioTerminate to be ready
    gpioTerminate(); //Reset gpio, ram ect. after program done
}

void DCMotor::homeSwitchStateChange(int gpio, int level, uint32_t tick) {
    // Get the current time
    auto current_time = std::chrono::steady_clock::now();

    // Calculate the time elapsed since the last ISR trigger
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - mLast_isr_time_homesw).count();

    // Ignore the ISR trigger if less than 50ms has elapsed since the last trigger
    if (elapsed_time < 50) {
        return;
    }

    // Update the last ISR trigger time
    mLast_isr_time_homesw = current_time;

    // Process the ISR trigger
    mHomeSWHit = (level == 1);
}

void DCMotor::limitSwitchStateChange(int gpio, int level, uint32_t tick) {

    // Get the current time
    auto current_time = std::chrono::steady_clock::now();

    // Calculate the time elapsed since the last ISR trigger
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - mLast_isr_time_limitsw).count();

    // Ignore the ISR trigger if less than 50ms has elapsed since the last trigger
    if (elapsed_time < 50) {
        return;
    }

    // Update the last ISR trigger time
    mLast_isr_time_limitsw = current_time;

    // Process the ISR trigger
    mLimitSWHit = (level == 1);
}

void DCMotor::setupHomeSwitch(unsigned int gpioPinHomeSW)
{
    // Set GPIO pin mode
    if (gpioSetMode(gpioPinHomeSW, PI_INPUT) != 0) {
        std::cerr << "Unable to set GPIO homeSW to input" << std::endl;
        gpioTerminate();
    }
    gpioSetPullUpDown(gpioPinHomeSW, PI_PUD_DOWN);
    // Set alert function for falling edge
    if (gpioSetAlertFunc(gpioPinHomeSW, homeSwitchStateChange) != 0) {
        std::cerr << "Failed to set homeswitch alert" << std::endl;
        gpioTerminate();
    }

    mHomeSWHit = gpioRead(gpioPinHomeSW);
}

void DCMotor::setupLimitSwitch(unsigned int gpioPinLimitSW)
{
    // Set GPIO pin mode
    if (gpioSetMode(gpioPinLimitSW, PI_INPUT) != 0) {
        std::cerr << "Unable to set GPIO limitSW to input" << std::endl;
        gpioTerminate();
    }
    gpioSetPullUpDown(gpioPinLimitSW, PI_PUD_DOWN);
    // Set alert function for falling edge
    if (gpioSetAlertFunc(gpioPinLimitSW, limitSwitchStateChange) != 0) {
        std::cerr << "Failed to set limitswitch alert" << std::endl;
        gpioTerminate();
    }

    mLimitSWHit = gpioRead(gpioPinLimitSW);
}

void DCMotor::stop()
{
    mMotorRunning = false;

    //Break
    changeDir();
    usleep(10000); //Break for 10ms

    //Stop
    gpioPWM(mGpioPinEna, 0); //Resets PWM if enabled
    gpioWrite(mGpioPinEna, 0); //Set pin to 0
    changeDir();  //Change back again
}

void DCMotor::run(unsigned int speed)
{   
    mMotorRunning = true;

    if(speed > 100)
        speed = 100;

    if(speed == 100)
        gpioWrite(mGpioPinEna, 1); //Full speed
    else
        gpioPWM(mGpioPinEna, speed); //Use PWM
}

void DCMotor::setDir(bool dir)
{
    if(dir == mDir)
        return; //Already that direction
    mDir = dir; //Change dir

    if(mMotorRunning) //Stop first
    {
        stop();
        mMotorRunning = true; //Run again after
        usleep(200000); // Wait 0.2 seconds to stop rotate
    }

    //Change direction
    gpioWrite(mGpioPinDir0, mDir);
    gpioWrite(mGpioPinDir1, !mDir);

    if(mMotorRunning)
        run(); //Start motor again
}

void DCMotor::changeDir()
{
    setDir(!mDir);
}

bool DCMotor::homeSWPressed() const
{
    return mHomeSWHit;
}

bool DCMotor::limitSWPressed() const
{
    return mLimitSWHit;
}





