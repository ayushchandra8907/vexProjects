#include "globals.h"
#include "pros/adi.hpp"

//controller
pros::Controller Controller1(pros::E_CONTROLLER_MASTER);

//motors
pros::Motor RFM(1, pros::E_MOTOR_GEARSET_18, false);
pros::Motor RBM(2, pros::E_MOTOR_GEARSET_18, false);
pros::Motor LFM(3, pros::E_MOTOR_GEARSET_18, true);
pros::Motor LBM(4, pros::E_MOTOR_GEARSET_18, true);

//encoders
extern pros::ADIEncoder rightTrack('A', 'B');
extern pros::ADIEncoder centTrack('C', 'D');
extern pros::ADIEncoder leftTrack('E', 'F');