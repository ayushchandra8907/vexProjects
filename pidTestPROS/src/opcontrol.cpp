#include "main.h"
#include "globals.h"
#include "pid.h"

void opcontrol() {
    PID drivepid = PID(1, 1, 1);

    drivepid.moveForward(500);
}