#include "main.h"
#include "lemlib/api.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);
// drive motors
pros::Motor lF(-19, pros::E_MOTOR_GEARSET_18); // left front motor. port 3, reversed
pros::Motor lM(-9, pros::E_MOTOR_GEARSET_18); // left middle motor. port 14, reversed
pros::Motor lB(-7, pros::E_MOTOR_GEARSET_18); // left back motor. port 12, reversed
pros::Motor rF(11, pros::E_MOTOR_GEARSET_18); // right front motor. port 19
pros::Motor rM(2, pros::E_MOTOR_GEARSET_18); // right middle motor. port 20
pros::Motor rB(1, pros::E_MOTOR_GEARSET_18); // right back motor. port 1

pros::Rotation rot_sensor(6);

// pros::Rotation horizontalEnc(15, true);
// lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_275, -3.7);

pros::MotorGroup leftMotors({lF, lM, lB}); // left motor group
pros::MotorGroup rightMotors({rF, rM, rB});

pros::Motor intake(17, pros::E_MOTOR_GEARSET_06);
pros::Motor cata(18, pros::E_MOTOR_GEARSET_06);

pros::ADIDigitalOut flapLeftPiston('H'); // ************FIX W/ ADI EXPANDER
pros::ADIDigitalOut flapRightPiston('F');
pros::ADIDigitalOut hang('E');


pros::Imu inertial_sensor(16);

lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                              &rightMotors, // right motor group
                              11.25, // 10 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
                              360, // drivetrain rpm is 360
                              8 // chase power is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings linearController(20, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            45, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            0 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             20, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &inertial_sensor // inertial sensor
);
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);