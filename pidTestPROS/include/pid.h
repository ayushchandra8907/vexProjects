#ifndef PID_H
#define PID_H

#include "main.h"

class PID {
public:
    void moveTo(double target);
private:
    double kP;
    double kI;
    double kD;

    double error;
    double lastError;

};


#endif