#include "DCMotor.h"

DCMotor::DCMotor(unsigned int gpioPinDir0, unsigned int gpioPinDir1, unsigned gpioPinEna)
{
    mGpioPinDir0 = gpioPinDir0;
    mGpioPinDir1 = gpioPinDir1;
    mGpioPinEna = gpioPinEna;
    gpioSetMode(gpioPinDir1, PI_OUTPUT);
    gpioSetMode(gpioPinDir2, PI_OUTPUT);
    gpioSetMode(gpioPinEna, PI_OUTPUT);
    gpioSetPWMrange(gpioPinEna, 100); //0-100%
    gpioWrite(mGpioPinDir0, 1); //Default direction
}

void DCMotor::setupHomeSwitch(unsigned int gpioPinHomeSW)
{
    gpioSetISRFunc(gpioPinHomeSW, RISING_EDGE,-1, stop());
    mHomeSWHit = true;
    mLimitSWHit = false;
}

void DCMotor::setupLimitSwitch(unsigned int gpioPinLimitSW)
{
    gpioSetISRFunc(gpioPinLimitSW, RISING_EDGE,-1, stop());
    mHomeSWHit = false;
    mLimitSWHit = true;
}

void DCMotor::stop()
{
    gpioPWM(mGpioPinEna, 0); //Resets PWM if enabled
    gpioWrite(mGpioPinEna, 0); //Set pin to 0
}

void DCMotor::run(unsigned int speed)
{
    //Change direction if running into SW (Motor and switch safty)
    if(mHomeSWHit && !mDir || mLimitSWHit && mDir)
        changeDir(); //Change direction

    //Not hitting any switches
    mHomeSWHit = false;
    mLimitSWHit = false;

    mMotorRunning = true;

    if(speed > 100)
        speed = 100;
    else if(speed == 100)
        gpioWrite(mGpioPinEna, 1); //Full speed
    else
        gpioPWM(mGpioPinEna, speed); //Use PWM
}

void DCMotor::setDir(bool dir)
{
    if(dir == mDir)
        return; //Already that direction

    if(mMotorRunning) //Stop first
    {
        stop();
        usleep(300000); // Wait 0.3 seconds to stop rotate
    }

    //Change direction
    if(mDir)
    {
      gpioWrite(mGpioPinDir0, 0´);
      gpioWrite(mGpioPinDir1, 1);
      mDir = !mDir;
    }
    else
    {
        gpioWrite(mGpioPinDir1, 1);
        gpioWrite(mGpioPinDir0, 1);
        mDir = !mDir;
    }

    if(mMotorRunning)
        run(); //Start motor again
}

void DCMotor::changeDir()
{
    setMotorDir(!mDir);
}

bool DCMotor::homeSWPressed() const
{
    return mHomeSWHit;
}

bool DCMotor::limitSWPressed() const
{
    return mLimitSWHit;
}





