#ifndef PID_H
#define PID_H

#include "main.h"
#include "globals.h"

class PID {
public:
    PID(double p, double i, double d);
    void moveForward(double target);
private:
    double kP;
    double kI;
    double kD;

    double error;
    double lastError;

};


#endif