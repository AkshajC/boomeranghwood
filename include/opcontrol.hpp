#pragma once
#include "main.h"
int exp_curves(int joystickValue);
void controllerControl();
void intakeControl();
void flapControl();
// void blockerControl();
void cataControl();
void cataTask();
// void hangPistonControl();
void hangControl();

extern bool slipPulled;
// extern bool hangPistonControlFlag;
extern char intakeControlState;
extern bool flapControlFlag;
extern bool blockerFlag;
extern bool cataControlFlag;
extern int target;
extern int error;
extern int cur_pos; 
extern bool hangFlag;
