#include "drive.h"


void setMotors(){
  RFM.spin(forward, Controller1.Axis3.position(), percent);
  LFM.spin(forward, Controller1.Axis2.position(), percent);
}

