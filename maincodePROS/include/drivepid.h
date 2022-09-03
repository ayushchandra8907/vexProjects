#ifndef DRIVEPID_H
#define DRIVEPID_H

#include "main.h"
#include "globals.h"
#include "subsystemHeaders/drive.h"

//movement
void pidTranslateY(double units);

//helper functions
double getAverageEncoderPos();
double clearEncoders();

#endif