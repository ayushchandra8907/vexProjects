#include "drive.h"
#include "globals.h"
#include "cmath"

//variables
int fwdDir = 1;
double pi = M_PI;

//functions
void powerDriveMotors(double RF, double RB, double LF, double LB){
    RFM = RF;
    RBM = RB;
    LFM = LF;
    LBM = LB;
}

void setDriveMotors(){
    //variables
    double x;
    double y;
    double turn;
    double theta;

    double pw;
    double s;
    double c;
    double mx;
    
    double leftFront;
    double rightFront;
    double leftBack;
    double rightBack;

    x = (fwdDir)*Controller1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X); // x position of joystick (inverted if fwdDir = -1)
    y = (-1*fwdDir)*Controller1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y); // y position of joystick
    turn = 1*(Controller1.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)); // turn value

    //information for motors
    theta = atan2(y, x); // angle from origin to (x, y)
    pw = hypot(x, y); // power sent to motors, based off distance from origin to (x, y)
 
    theta = calcDeadzone(theta); //snaps joystick to absolute direction if within 15 degrees  
  
    //math for sending power into motors
    s = sin(theta - pi/4); // sin value for motors
    c = cos(theta - pi/4); // cos value for motors
    mx = std::fmax(std::abs(s), std::abs(c)); // reaches max motor value if in absolute direction

    //assigns power to vars for motors
    leftFront = pw * s/mx + turn;
    rightFront = pw * c/mx - turn;
    leftBack = pw * c/mx + turn;
    rightBack = pw * s/mx - turn;
    
    powerDriveMotors(rightFront, rightBack, leftFront, leftBack);
}

double calcDeadzone(double t){ //calculates deadzone of joystick for less need of precision
  double theta = t;

  if(theta > (-1*pi)/12 && theta < (pi/12)){
    theta = 0;
  } else if(theta > (-7*pi)/12 && theta < (-5*pi)/12){
    theta = -1*(pi)/2;
  } else if(theta > (5*pi)/12 && theta < 7*(pi/12)){
    theta = pi/2;
  } else if((theta > (11*pi)/12 && theta < (pi)) || (theta > (-1*pi)/12 && theta < (-11*pi/12))){
    theta = pi;
  } else {
    return theta;
  }

  return theta;
}

//BUTTON MACROS
void eBrake(){
    
}

void reverseDrive(){

}