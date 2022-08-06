#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor RFM = motor(PORT2, ratio18_1, true);
motor RBM = motor(PORT3, ratio18_1, true);
motor LFM = motor(PORT4, ratio18_1, false);
motor LBM = motor(PORT5, ratio18_1, false);
encoder rightEnc = encoder(Brain.ThreeWirePort.A);
encoder centEnc = encoder(Brain.ThreeWirePort.C);
encoder leftEnc = encoder(Brain.ThreeWirePort.G);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}