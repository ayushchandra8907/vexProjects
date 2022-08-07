#ifndef DRIVE_H
#define DRIVE_H

//driving functions
void powerDriveMotors(double RF, double RB, double LF, double LB); // method for actually sending power to motors
void setDriveMotors(); // method to be called in main to tell drive to move, as well as calculates needed speed for base

//button macros
void eBrake();
void reverseDrive();

//helper functions
double calcDeadzone(double t);

#endif