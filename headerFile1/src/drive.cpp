#include "drive.h"

//FUNCTION DECLARATIONS==========================
void setDriveMotors(double left, double right){
  LFM.spin(forward, left, percent);
  RFM.spin(forward, right, percent);
}

void powerDriveMotors(){
  setDriveMotors(Controller1.Axis3.position(), Controller1.Axis2.position());
}