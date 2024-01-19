#include "main.h"
ASSET(wingstart_txt);

void cata_pulldown(){
	while((abs(abs(cur_pos)-target)) > error){
		cur_pos=rot_sensor.get_position();
		cata = -127;
		pros::delay(10);
	}
	cata =0;
}

void testing(){
	// Winpoint uncomment later
	// chassis.moveToPose(-22, -17, 90, 3000, {.forwards=false, .minSpeed=65});
	// pros::delay(700);
	// chassis.moveToPose(-10, -12, 45, 3000, {.forwards=true});
	// chassis.turnTo(-22, -17, 3000, true, 127, false);
	// flapLeftPiston.set_value(true);
	// chassis.moveToPose(-3.5, 0, 180, 3000, {.forwards=false, .lead=0.4}, false);
	// flapLeftPiston.set_value(false);
	// chassis.moveToPose(2, 31, 180, 5000, {.forwards=false});
	//Disrupt Elims
	flapLeftPiston.set_value(true);
	intake = 127;
	chassis.moveToPose(12, 37, 0, 3000, {.forwards=true, .minSpeed=65});
	pros::delay(300);
	flapLeftPiston.set_value(false);
	chassis.moveToPose(6, 32.5, 90, 3000, {.forwards=false});
	flapLeftPiston.set_value(true);
	flapRightPiston.set_value(true);
	chassis.moveToPose(27, 34, 90, 3000, {.forwards=true, .minSpeed=40}, false);
	intake = -127;u
	pros::delay(3000);
	flapLeftPiston.set_value(false);
	flapRightPiston.set_value(false);

}

void ram(int time){
	leftMotors = -127;
	rightMotors = -127;
	pros::delay(time);
	leftMotors=0;
	rightMotors=0;
}

void skills(){
	target=3000;
	// blocker.set_value(true);
	flapRightPiston.set_value(true);
	// chassis.turnTo(0, -10, 3000);
	pros::delay(400);
	// blocker.set_value(false);
	flapRightPiston.set_value(false);
	chassis.moveToPose(-14.5, 9.5, -106.5, 2000, {.forwards=true, .lead=0.45});
	cata=-127;
	pros::delay(30500);
	chassis.setPose(-14.5, 9.5, -105);
	pros::delay(200);
	// flapRightPiston.set_value(false);
	chassis.moveToPose(10.5, -6.5, -90, 3000, {.forwards=false, .lead=0.6});
	cata_pulldown();
	chassis.moveToPose(83.4, -6.5, -90, 3000, {.forwards=false});
	chassis.waitUntil(50);
	flapRightPiston.set_value(true);
	chassis.turnTo(106.5, 20.5, 3000, false);
	chassis.moveToPose(101.5, 13, -160, 3000, {.forwards=false, .lead = -0.3}, false);
	ram(1000);
	chassis.moveToPose(101.5, 13, -160, 3000, {.forwards=true, .lead = 0.3}, false);
	flapRightPiston.set_value(false);
	ram(1000);
	pros::delay(700);
	chassis.setPose(0, 0, 0);
	pros::delay(200);
	chassis.moveToPose(17.5, 16.5, 55, 3000);
	chassis.turnTo(50, -10, 700);
	// chassis.follow(wingstart_txt, 15, 3000);
	flapRightPiston.set_value(false);
	//fix this tmw for DEC 29
	chassis.moveToPose(53, -12, 180, 2000, {.lead = 0.43}, false);
	chassis.moveToPose(20, -17.5, 90, 2000, {.forwards=false, .lead=-0.4});
	// chassis.turnTo(83, -14, 700, true, 127, false);
	flapLeftPiston.set_value(true);
	ram(700);
	flapLeftPiston.set_value(false);
	chassis.moveToPose(54, -58, 180, 2000);
	chassis.turnTo(81, -79, 700);
		flapLeftPiston.set_value(true);
	flapRightPiston.set_value(true);
	chassis.moveToPoint(27, -34.5, 3000, false, 64, false);
	flapLeftPiston.set_value(false);
	flapRightPiston.set_value(false);
	chassis.moveToPose(56, -30, 90, 3000, {.forwards=true}, false);
	flapLeftPiston.set_value(true);
	flapRightPiston.set_value(true);
	ram(1300);
		flapLeftPiston.set_value(false);
	flapRightPiston.set_value(false);
	// chassis.moveToPose(45.5, -44, 215, 3000, {.forwards=true});
	chassis.moveToPoint(54, -28, 3000);
	intake=-127;
	// flapLeftPiston.set_value(false);
	// flapRightPiston.set_value(false);




	// chassis.moveToPose(53, -60, 245, 2000);
	// flapLeftPiston.set_value(true);
	// 	flapRightPiston.set_value(true);

	// chassis.moveToPose(100, 5, -165, 3000, {.forwards=false}, false);
	// chassis.moveToPose(90, 0, -150, 3000, {}, false);
	// ram(3000);
	// chassis.moveToPose(90, 0, -150, 3000, {}, false);
	// chassis.turnTo(106, 27, 1000, false);
	// chassis.moveToPose(103, 20, -180, 3000, {.forwards = false, .lead=0.5});



	// blocker.set_value(true);
	// flapLeftPiston.set_value(true);
	// pros::delay(600);
	// flapLeftPiston.set_value(false);
	// blocker.set_value(false);
	// // chassis.moveToPose(0, 0, 100, 4000, false, true, 0, 0.6, 20, false);
	// chassis.turnTo(6, -16.3, 3000);
	// cata=-127;
	// // 26500
	// pros::delay(26500);

	// // cata=0;
	// // chassis.turnTo(-28, -5, 3000, true);
	// // chassis.turnTo(-24, 5, 3000);
	// // flapLeftPiston.set_value(true);
	// // chassis.turnTo(13, 5, 4000);
	// flapLeftPiston.set_value(true);
	// chassis.moveToPose(-28, -3, 90, 4000, false, false, 4, 0.6, 127);
	// flapLeftPiston.set_value(false);
	// chassis.setPose(chassis.getPose().x, chassis.getPose().y, 90);
	// intake = -127;
	// int error=500;
	// int cur_pos=0;
	// int target= 3900;
	// while (abs(abs(cur_pos)-target) > error){
	// 	cur_pos=rot_sensor.get_position();
	// 	cata = -127;
	// }
	// cata = 0;
	// // cata=-127;
	// chassis.moveToPose(-2, 25, 0, 3000, false, true, 4, 0.5, 127);
	// chassis.moveToPose(-2, 95, 0, 3000);
	// cata=0;
	// chassis.moveToPose(-20, 85, 180, 3000, false, true, 4, 0.65, 63);
	// chassis.moveToPose(-69, 70, -90, 3000, false, true, 4, 0.85, 63);
	// // intake=0;
	// // pros::delay(500);
	// // chassis.turnTo(chassis.getPose().x, -100, 3000, 63);

	// flapLeftPiston.set_value(true);
	// flapRightPiston.set_value(true);

	// chassis.moveToPose(chassis.getPose().x, 100, 180, 3000, false, false, 6, 0, 127);
	// chassis.setPose(chassis.getPose().x, chassis.getPose().y, 180);
	// flapLeftPiston.set_value(false);
	// flapRightPiston.set_value(false);
	// chassis.moveToPose(-83, 73, 200, 3000, false, true, 4, -0.8, 127);
	// flapLeftPiston.set_value(true);
	// flapRightPiston.set_value(true);
	// chassis.moveToPose(-68, 100, 220, 3000, false, false, 4, 0, 127);
	// flapLeftPiston.set_value(false);
	// flapRightPiston.set_value(false);
	// chassis.moveToPose(-41.5, 80, 150, 3000, false, true, 4, -0.8, 127);
	// flapLeftPiston.set_value(true);
	// flapRightPiston.set_value(true);
	// chassis.moveToPose(-40, 100, 150, 3000, false,false, 4, 0, 127);
	// flapLeftPiston.set_value(false);
	// flapRightPiston.set_value(false);
	// chassis.moveToPose(-38, 80, 150, 3000, false, true, 4, -0.8, 127);
	// flapLeftPiston.set_value(true);
	// flapRightPiston.set_value(true);
	// chassis.moveToPose(-40, 100, 150, 3000, false,false, 4, 0, 127);
	// flapLeftPiston.set_value(false);
	// flapRightPiston.set_value(false);
	// chassis.moveToPose(-38, 80, 150, 3000, false, true, 4, -0.8, 127);
	// chassis.moveToPose(-4, 110, 150, 3000, false, false, 4, 0.9, 127);
}