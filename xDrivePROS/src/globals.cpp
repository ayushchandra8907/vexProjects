#include "globals.h"

//controller
pros::Controller Controller1(pros::E_CONTROLLER_MASTER);

//motor
pros::Motor RFM(2, pros::E_MOTOR_GEARSET_18, false);
pros::Motor LFM(3, pros::E_MOTOR_GEARSET_18, true);
pros::Motor RBM(4, pros::E_MOTOR_GEARSET_18, false);
pros::Motor LBM(5, pros::E_MOTOR_GEARSET_18, true);