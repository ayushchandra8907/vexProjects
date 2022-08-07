#include "drive.h"

//variables
int driveFwd = 1;

//FUNCTION DECLARATIONS==========================
void setDriveMotors(double LF, double RF, double LB, double RB){
  LFM.spin(forward, LF, percent);
  RFM.spin(forward, RF, percent);
  LBM.spin(forward, LB, percent);
  RBM.spin(forward, RB, percent);
}



//does x drive math - takes joystick vals and converts into motor information
void powerDriveMotors(){
  double pi = M_PI;

  double xJoy = (driveFwd)*Controller1.Axis4.position(); // x position of joystick (inverted if fwdDir = -1)
  double yJoy = (-1*driveFwd)*Controller1.Axis3.position(); // y position of joystick
  double turnJoy = 1*(Controller1.Axis1.position()); // turn value

  //information for motors
  double theta = atan2(yJoy, xJoy); // angle from origin to (x, y)
  double pw = hypot(xJoy, yJoy); // power sent to motors, based off distance from origin to (x, y)

  theta = calcDeadzone(theta); //snaps joystick to absolute direction if within 15 degrees 

  double s = sin(theta - pi/4); // sin value for motors
  double c = cos(theta - pi/4); // cos value for motors
  double mx = fmax(abs(s), abs(c)); // reaches max motor value if in absolute direction

  double leftFront = pw * s/mx + turnJoy;
  double rightFront = pw * c/mx - turnJoy;
  double leftBack = pw * c/mx + turnJoy;
  double rightBack = pw * s/mx - turnJoy;

  setDriveMotors(leftFront, rightFront, leftBack, rightBack);
}

//calculate deadzone - calculates neccesary deadzone so you don't have to be completetly precise
double calcDeadzone(double t){
  double pi = M_PI;

  if(t > (-1*pi)/12 && t < (pi/12)){
    t = 0;
  } else if(t > (-7*pi)/12 && t < (-5*pi)/12){
    t = -1*(pi)/2;
  } else if(t > (5*pi)/12 && t < 7*(pi/12)){
    t = pi/2;
  } else if((t > (11*pi)/12 && t < (pi)) || (t > (-1*pi)/12 && t < (-11*pi/12))){
    t = pi;
  } else {
    return t;
  }

  return t;
}

//switches direction of drive
void switchDir(){
  driveFwd *= -1;
}

