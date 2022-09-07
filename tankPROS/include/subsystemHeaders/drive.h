#ifndef DRIVE_H
#define DRIVE_H

#include "globals.h"

//drive functions
void setDriveMotors();

//auton functions
void translate(double units, double voltage);

//helper functions
void setDrive(double left, double right);
void clearDriveMotors();
double getMotorPosition();


#endif