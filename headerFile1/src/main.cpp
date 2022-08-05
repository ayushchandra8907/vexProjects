/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Ayush                                            */
/*    Created:      Fri Aug 05 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RFM                  motor         1               
// LFM                  motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----


//INCLUDE/IMPORT FILES================================
#include "vex.h"
//drive subsystem
#include "drive.h"

//namespaces
using namespace vex;
using namespace std;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while(true){
    
    //drive command
    powerDriveMotors();


    wait(20, msec);
  }
  
}
