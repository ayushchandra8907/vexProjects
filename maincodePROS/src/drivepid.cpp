#include "drivepid.h"
#include "globals.h"
#include "subsystemHeaders/drive.h"

void pidTranslateY(double units) {
    //clear encoders
    clearEncoders();

    //variables
    double kP = 1;
    double kI = 1;
    double kD = 1;

    double error = units- getAverageEncoderPos();
    double lastError = error;
    double derivative;

    double pow;

    while(true) {
        //P
        error = units - getAverageEncoderPos();
        double P = error * kP;

        //D
        derivative = lastError - error;
        double D = derivative * kD;



        lastError = error;

        //give power to motors
        pow = P + D;
        setDrive(pow, pow);
        
        //delay
        pros::delay(20);
    }
}

//helper functions=============================
double getAverageEncoderPos() {
    return (rightTrack.get_value() + leftTrack.get_value()) / 2.0;
}

double clearEncoders() {
    rightTrack.reset();
    leftTrack.reset();
    centTrack.reset();
}
