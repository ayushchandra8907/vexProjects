#include "drive.h"

//FUNCTION DECLARATIONS==========================
void setDriveMotors(double LF, double RF, double LB, double RB){
  LFM.spin(forward, LF, percent);
  RFM.spin(forward, RF, percent);
  LBM.spin(forward, LB, percent);
  RBM.spin(forward, RB, percent);
}

void powerDriveMotors(){ // motor called in main method
  Xdrive::setPositionInfo(); //gets info
  Xdrive::calculatePower(); //powers using info
}

//CLASS DECLARATIONS============================
//constructor - initilizes variables for use *test if actually needed
Xdrive::Xdrive(){
  pi = M_PI;
  fwdDir = 1;

  xJoy = 0;
  yJoy = 0;
  turnJoy = 0;
  theta = 0;

  pw = 0;
  s = 0;
  c = 0;
  mx = 0;
}

//set position info - takes joystick vals and converts into motor information
void Xdrive::setPositionInfo(){
  xJoy = (fwdDir)*Controller1.Axis4.position(); // x position of joystick (inverted if fwdDir = -1)
  yJoy = (-1*fwdDir)*Controller1.Axis3.position(); // y position of joystick
  turnJoy = 1*(Controller1.Axis1.position()); // turn value

  //information for motors
  theta = atan2(yJoy, xJoy); // angle from origin to (x, y)
  pw = hypot(xJoy, yJoy); // power sent to motors, based off distance from origin to (x, y)

  calcDeadzone(); //snaps joystick to absolute direction if within 15 degrees 
}

//calculate deadzone - calculates neccesary deadzone so you don't have to be completetly precise
void Xdrive::calcDeadzone(){
  if(theta > (-1*pi)/12 && theta < (pi/12)){
    theta = 0;
  } else if(theta > (-7*pi)/12 && theta < (-5*pi)/12){
    theta = -1*(pi)/2;
  } else if(theta > (5*pi)/12 && theta < 7*(pi/12)){
    theta = pi/2;
  } else if((theta > (11*pi)/12 && theta < (pi)) || (theta > (-1*pi)/12 && theta < (-11*pi/12))){
    theta = pi;
  } else {
    theta = theta;
  }
}

//calculate power - takes all previous information and converts it into actual power for the motors to spin
void Xdrive::calculatePower(){
  leftFront = pw * s/mx + turnJoy;
  rightFront = pw * c/mx - turnJoy;
  leftBack = pw * c/mx + turnJoy;
  rightBack = pw * s/mx - turnJoy;

  setDriveMotors(leftFront, rightFront, leftBack, rightBack); // calls method for sending power to motors
}