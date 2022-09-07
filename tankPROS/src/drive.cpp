#include "subsystemHeaders/drive.h"
#include "globals.h"
#include "pros/rtos.hpp"

//drive functions
void setDriveMotors() {
    double right = controller1.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    double left = controller1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);

    setDrive(left, right);
}

//auton functions
void translate(double units, double voltage) {
    //get direction
    int dir = fabs(units)/units;

    //reset encoders
    clearDriveMotors();

    //go forward
    while(fabs(getMotorPosition()) < fabs(units)){
        setDrive(dir * voltage, dir * voltage);
        pros::delay(20);
    }

    //end
    setDrive(dir * -10, dir * -10);
    pros::delay(50);

    setDrive(0, 0);
}

//helper functions
void setDrive(double left, double right) {
    rfm = right;
    rbm = right;
    lfm = left;
    lbm = left;
}

void clearDriveMotors() {
    rfm.tare_position();
    rbm.tare_position();
    lfm.tare_position();
    lbm.tare_position();
}

double getMotorPosition() {
    double sumPos = rfm.get_position() + rbm.get_position() + lfm.get_position() + lbm.get_position();

    return sumPos/4.0;
}