#ifndef DRIVE_H
#define DRIVE_H

#include "globals.h"

//drive functions
void setDriveMotors();

//helper functions
void setDrive(double left, double right);
void setDrive(double RF, double RB, double LF, double LB);
void clearDriveMotors();
double calcDeadzone(double t);

//auton functions
void translateY(double units, double voltage);


#endif