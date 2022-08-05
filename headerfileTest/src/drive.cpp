#include "drive.h"

<<<<<<< HEAD

void setMotors(){
  RFM.spin(forward, Controller1.Axis3.position(), percent);
  LFM.spin(forward, Controller1.Axis2.position(), percent);
=======
//varibles

void setMotors(double left, double right){
  RFM.spin(forward, right, percent);
  LFM.spin(forward, left, percent);
>>>>>>> parent of de518ae (asdf)
}

