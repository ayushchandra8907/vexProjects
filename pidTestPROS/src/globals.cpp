#include "globals.h"
#include "pros/adi.hpp"

//controller
pros::Controller Controller1(pros::E_CONTROLLER_MASTER);

//motors
pros::Motor RFM(2, pros::E_MOTOR_GEARSET_18, false);
pros::Motor LFM(3, pros::E_MOTOR_GEARSET_18, true);

//sensors
