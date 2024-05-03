#include "GripperController.h"

GripperController::GripperController() : mMotor(DCMotor(DIR0_PIN, DIR1_PIN, ENA_PIN))
{
    mMotor.setupHomeSwitch(HOME_SW_PIN);
    mMotor.setupLimitSwitch(LIMIT_SW_PIN);
}

void GripperController::grip()
{
    if(mMotor.limitSWPressed())
        return;

    mMotor.setDir(0);
    mMotor.run();
    while(!mMotor.limitSWPressed())
    {
        //Keep running motor
    }
    mMotor.stop();
}

void GripperController::open()
{
    if(mMotor.homeSWPressed())
        return;

    mMotor.setDir(1);
    mMotor.run();
    while(!mMotor.homeSWPressed())
    {
        //Keep running motor
    }
    mMotor.stop();
}
