#include "main.h"
#include "globals.h"
#include "drive.h"

void opcontrol() {
	while (true) {
		//runs code for driving base
		setDriveMotors();


		pros::delay(20);
	}
}
