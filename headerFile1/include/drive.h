//header guard
#ifndef DRIVE_H
#define DRIVE_H

//vex library
#include "vex.h"

//FUNCTION DECLARATIONS==========================
void setDriveMotors(double LF, double RF, double LB, double RB); //sets the motors to their values
void powerDriveMotors(); //method called in main method to automatically set motors
double calcDeadzone(double t); //deadzone method for joystick angle
void switchDir(); //switches drive direction



//end
#endif