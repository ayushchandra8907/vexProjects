//header guard
#ifndef DRIVE_H
#define DRIVE_H

//vex library
#include "vex.h"

//FUNCTION DECLARATIONS==========================
void setDriveMotors(double LF, double RF, double LB, double RB); //sets the motors to their values
void powerDriveMotors(); //method called in main method to automatically set motors

//CLASS DECLARATIONS=============================
class Xdrive {
public:
  //constructor
  Xdrive();

  //PI
  static double pi;

  //instance fields
  static int fwdDir;

  static double xJoy;
  static double yJoy;
  static double turnJoy;
  static double theta;

  static double pw;
  static double s;
  static double c;
  static double mx;

  static double leftFront;
  static double rightFront;
  static double leftBack;
  static double rightBack;
  
  //methods
  static void setPositionInfo();
  static void calcDeadzone();
  static void calculatePower();
  static void switchDir();
};


//end
#endif