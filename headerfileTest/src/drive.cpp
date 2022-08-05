#include "drive.h"

//variables
double rightPow;
double leftPow;

void setMotors(double left, double right){
  RFM.spin(forward, right, percent);
  LFM.spin(forward, left, percent);
}
