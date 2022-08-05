#include "drive.h"

void getMotorValues(){
  rightPow = Controller1.Axis2.position();
  leftPow = Controller1.Axis3.position();
}

void setMotors(){
  RFM.spin(forward, rightPow, percent);
  LFM.spin(forward, leftPow, percent);
}

