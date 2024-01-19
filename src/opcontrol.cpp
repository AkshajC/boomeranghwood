#include "main.h"


int exp_curves(int joystickValue){
	return abs(joystickValue)/joystickValue * (1.2*pow(1.0356, abs(joystickValue)) - 1.2 + 0.2*abs(joystickValue));
}

void controllerControl() {
	int left = master.get_analog(ANALOG_LEFT_Y);
	int right = master.get_analog(ANALOG_RIGHT_Y);
	rightMotors =  exp_curves(right*(127/100));
	leftMotors = exp_curves(left*(127/100));
}

char intakeControlState = 'N';
void intakeControl(){
	if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
		if(intakeControlState == 'N' || intakeControlState == 'R'){
			intake = 127;
			intakeControlState = 'F';
		} else { 
			intake = 0;
			intakeControlState = 'N';
		}
		pros::delay(180);
	}
	if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
		if(intakeControlState == 'N' || intakeControlState == 'F'){
			intake = -127;
			intakeControlState = 'R';
		} else {
			intake = 0;
			intakeControlState = 'N';
		}
		pros::delay(180);
	}
}

bool flapControlFlag = false;
void flapControl() {
	if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
		flapControlFlag = !flapControlFlag;
		if(flapControlFlag){
			flapLeftPiston.set_value(true);
			flapRightPiston.set_value(true);
			pros::delay(200);
	    } else {
			flapLeftPiston.set_value(false);
			flapRightPiston.set_value(false);
			pros::delay(200);
		}
	}
}

// bool blockerFlag = false;
// void blockerControl() {
// if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
// 		blockerFlag = !blockerFlag;
// 		if(blockerFlag){
// 			blocker.set_value(true);
// 			pros::delay(200);
// 	    } else {
// 			blocker.set_value(false);
// 			pros::delay(200);
// 		}
// 	}
// }
bool cataControlFlag = false;
void cataControl() {
	if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
		cataControlFlag = !cataControlFlag;
		if(cataControlFlag){
			cata = -127;
			pros::delay(160);
		} else {
			cata = 0;
			pros::delay(160);
		}
	}
}


int target=0;
int error=400;
int cur_pos=0;
bool taskActive = false;
void cataTask(){
	while(true){
		cur_pos=rot_sensor.get_position();
	// if((((abs(cur_pos))-(abs(cur_pos)/pos)*3100 > error) || cur_pos==0) && !cataControlFlag){
	if((abs(abs(cur_pos)-target)) > error && !cataControlFlag && !taskActive){
		cata = -127;
	} else if(cataControlFlag && !taskActive){
		cata = -127;
	} else {
		cata=0;
	} 
	pros::delay(20);
	}
}

bool hangPistonControlFlag = false;

bool hangFlag = false;
void hangControl() {
if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
		hangFlag = !hangFlag;
		if(hangFlag){
			hang.set_value(false);
			
			// taskActive=true;
			pros::delay(500);
		} else {
			hang.set_value(true);
			taskActive = false;
			pros::delay(500);
		}
	}
}
bool hangFireControlFlag = false;
void hangFireControl(){
	if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
		hangFireControlFlag = !hangFireControlFlag;
		if(hangFireControlFlag){
			hang.set_value(false);
			cata=-127;
			pros::delay(200);
		} else {
			hang.set_value(true);
			cata = -127;
			pros::delay(200);
		}
	}
}
// void hangPistonControl(){
// 	if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
// 		hangPistonControlFlag = !hangPistonControlFlag;
// 		if(hangPistonControlFlag){
// 			hang.set_value(true);
// 			target=3800;
// 			pros::delay(200);
// 		} else {
// 			hang.set_value(false);
// 			target = 0;
// 			pros::delay(200);
// 		}
// 	}
// }