#include "pid.h"

pros::ADIEncoder rightTrack('A', 'B');
pros::ADIEncoder centTrack('C', 'D');
pros::ADIEncoder leftTrack('E', 'F');

PID::PID(double p, double i, double d){
    kP = p;
    kI = i;
    kD = d;
}

void PID::moveForward(double target){
    leftTrack.reset();
    rightTrack.reset();

    double leftPos = leftTrack.get_value();
    double rightPos = rightTrack.get_value();
    double pos = (leftPos + rightPos)/2.0;

    double error = target - pos;
    double lastError = 0;
    double totalError = 0;
    double derivative;

    double P;
    double D;

    //PD loop only
    while(true){
        derivative = error - lastError;
        P = error*kP;
        D = derivative*kD;

        double motPow = P+D;

        RFM = motPow;
        LFM = motPow;

        lastError = error;

        pros::delay(20);
    }

}