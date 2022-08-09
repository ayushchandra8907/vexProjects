#include "subsystemHeaders/drive.h"
#include "globals.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

//variables
double pi = M_PI;
int fwdDir = 1;

//driver control function===========
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
    
    setDrive(rightFront, rightBack, leftFront, leftBack);
}

//helper methods====================
//set motors
void setDrive(double left, double right){ //sets drive motors to right and left powers
    RFM = right;
    RBM = right;
    LFM = left;
    LBM = left;
}

void setDrive(double RF, double RB, double LF, double LB){
    RFM = RF;
    RBM = RB;
    LFM = LF;
    LBM = LB;
}

//clear IMEs
void clearDriveMotors(){ //clears encoders in the drive motors
    RFM.tare_position();
    RBM.tare_position();
    LFM.tare_position();
    LBM.tare_position();
}

//motor pos
double getAverageMotorPos(){
    double sum = RFM.get_position() + RBM.get_position() + LFM.get_position() + LBM.get_position();
    return sum/4.0;
}

//deadzone
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



//Auton functions===================
//forward/backward
void translateY(double units, double voltage){ //goes forward or backward a certain distance at a certain speed
    //get direction
    int direction = fabs(units)/(units); //1 if units is positive, -1 otherwise.

    //reset motors
    clearDriveMotors();
    gyro1.reset();

    //drive until all units are reached
    while(fabs(getAverageMotorPos())<fabs(units)){
        setDrive(direction*voltage + gyro1.get_value(), direction*voltage - gyro1.get_value()); //sets power to drive and uses gyro to fix
        pros::delay(20);
    }

    //brake
    setDrive(-10 * direction, -10 * direction);
    pros::delay(50);

    //set motors neutral
    setDrive(0, 0);
}



