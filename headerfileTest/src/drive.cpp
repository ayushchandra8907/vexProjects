#include "drive.h"

//varibles

void setMotors(double left, double right){
  RFM.spin(forward, right, percent);
  LFM.spin(forward, left, percent);
}

