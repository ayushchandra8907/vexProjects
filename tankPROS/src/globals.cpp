#include "main.h"
#include "globals.h"
#include "pros/misc.h"
#include "pros/misc.hpp"

pros::Controller controller1(pros::E_CONTROLLER_MASTER);

pros::Motor rfm(1, pros::E_MOTOR_GEARSET_18, false);
pros::Motor rbm(2, pros::E_MOTOR_GEARSET_18, false);
pros::Motor lfm(3, pros::E_MOTOR_GEARSET_18, true);
pros::Motor lbm(4, pros::E_MOTOR_GEARSET_18, true);
