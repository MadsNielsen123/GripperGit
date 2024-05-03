#ifndef GRIPPERCONTROLLER_H
#define GRIPPERCONTROLLER_H

#include "DCMotor.h"

//PIN-outs for H-BRIDGE SHIELD
#define DIR0_PIN 17
#define DIR1_PIN 27
#define ENA_PIN 22
#define HOME_SW_PIN 6
#define LIMIT_SW_PIN 5

class GripperController
{
public:
    GripperController();
    void grip();
    void open();

private:
    DCMotor mMotor;

};

#endif // GRIPPERCONTROLLER_H
