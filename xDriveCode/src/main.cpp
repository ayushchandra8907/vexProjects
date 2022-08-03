// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// RFM                  motor         1               
// RBM                  motor         2               
// LFM                  motor         3               
// LBM                  motor         5               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Ayush                                            */
/*    Created:      Wed Aug 03 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// RFM                  motor         1               
// RBM                  motor         2               
// LFM                  motor         3               
// LBM                  motor         4               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "cmath"
using namespace vex;
using namespace std;

//other varibles===================================================
//constant for pi
double pi = M_PI;

//varibles in code
//drive----
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

//functions======================================================================
//Helper Functions
void calcDeadzone(){ //calculates deadzone of joystick for less need of precision
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

//Button Functions 
int fwdDir = 1;
void switchDir(){ //inverts forward and backward for orientations
  fwdDir *= -1;
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //Buttons used in driver control
  Controller1.ButtonA.pressed(switchDir);

  while(true){

    //HIDDEN PROCESSES===================================================================================
    //DRIVE PROCESS------------------------------------------
    //positions for joystick values
    x = (fwdDir)*Controller1.Axis4.position(); // x position of joystick (inverted if fwdDir = -1)
    y = (-1*fwdDir)*Controller1.Axis3.position(); // y position of joystick
    turn = 1*(Controller1.Axis1.position()); // turn value

    //information for motors
    theta = atan2(y, x); // angle from origin to (x, y)
    pw = hypot(x, y); // power sent to motors, based off distance from origin to (x, y)
 
    calcDeadzone(); //snaps joystick to absolute direction if within 15 degrees  
  
    //math for sending power into motors
    s = sin(theta - pi/4); // sin value for motors
    c = cos(theta - pi/4); // cos value for motors
    mx = std::fmax(abs(s), abs(c)); // reaches max motor value if in absolute direction

    //assigns power to vars for motors
    leftFront = pw * s/mx + turn;
    rightFront = pw * c/mx - turn;
    leftBack = pw * c/mx + turn;
    rightBack = pw * s/mx - turn;

    //spins motors
    RFM.spin(vex::forward, rightFront, vex::percent);
    LFM.spin(vex::forward, leftFront, vex::percent);
    RBM.spin(vex::forward, rightBack, vex::percent);
    LBM.spin(vex::forward, leftBack, vex::percent);

    //DRIVER CONTROL====================================================================================
    
    /* 

      Add buttons here for controlling other motors

    */




    wait(20, msec);
  }
}
