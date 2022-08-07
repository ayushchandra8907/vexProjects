#include "drive.h"



void setMotors(double left, double right){
    RFM = right;
}

void driveMotors(){
    double left = controller1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
    double right = controller1.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    setMotors(left, right);
}