#pragma config(Motor,  port2,           leftMotor2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightMotor2,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rightMotor1,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

//Blue Left AUTO
task autonomous()
{
	motor[leftMotor1] = 255;
	motor[leftMotor2] = 255;
	motor[rightMotor1] = 255;
	motor[rightMotor2] = 255;
	delay (1800);
	motor[leftMotor1] = -255;
	motor[leftMotor2] = -255;
	motor[rightMotor1] = -255;
	motor[rightMotor2] = -255;
	delay (500);
	motor[leftMotor1] = 255;
	motor[leftMotor2] = 255;
	motor[rightMotor1] = -255;
	motor[rightMotor2] = -255;
	delay(400);
	motor[leftMotor1] = 255;
	motor[leftMotor2] = 255;
	motor[rightMotor1] = 255;
	motor[rightMotor2] = 255;
	delay (150);
	motor[leftMotor1] = 0;
	motor[leftMotor2] = 0;
	motor[rightMotor1] = 0;
	motor[rightMotor2] = 0;
	motor[leftLift] = -255;
	motor[rightLift] = -255;
	delay (1000);
	motor[leftLift] = 0;
	motor[rightLift] = 0;
	motor[leftMotor1] = 255;
	motor[leftMotor2] = 255;
	motor[rightMotor1] = 255;
	motor[rightMotor2] = 255;
	delay (1200);
	motor[leftMotor1] = 0;
	motor[leftMotor2] = 0;
	motor[rightMotor1] = 0;
	motor[rightMotor2] = 0;
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  while (true) {
		motor[leftMotor1] = vexRT[Ch3];
		motor[leftMotor2] = vexRT[Ch3];
		motor[rightMotor1] = vexRT[Ch2];
		motor[rightMotor2] = vexRT[Ch2];
		if (((vexRT[Btn5U] && vexRT[Btn6U]) || vexRT[Btn8U]) && ! (vexRT[Btn8D])) {
			motor[leftLift] = 255;
			motor[rightLift] = 255;
		}
		else if ((vexRT[Btn5U] && vexRT[Btn6U]) || vexRT[Btn8D]) {
			motor[leftLift] = -255;
			motor[rightLift] = -255;
		}
		else if (vexRT[Btn5U]) {
			motor[leftLift] = 255;
			motor[rightLift] = 0;
		}
		else if (vexRT[Btn5D]) {
			motor[leftLift] = -255;
			motor[rightLift] = 0;
		}
		else if (vexRT[Btn6U]) {
			motor[rightLift] = 255;
			motor[leftLift] = 0;
		}
		else if (vexRT[Btn6D]) {
			motor[rightLift] = -255;
			motor[leftLift] = 0;
		}
		else {
			motor[leftLift] = 0;
			motor[rightLift] = 0;
		}
		//flip cap
		if (vexRT[Btn7U]) {
			motor[leftMotor1] = 255;
			motor[leftMotor2] = 255;
			motor[rightMotor1] = 255;
			motor[rightMotor2] = 255;
			motor[leftLift] = 255;
			motor[rightLift] = 255;
			delay (1300);
			motor[leftLift] = 0;
			motor[leftLift] = 0;
			motor[leftMotor1] = 0;
			motor[leftMotor2] = 0;
			motor[rightMotor1] = 0;
			motor[rightMotor2] = 0;
		}
		// climb platform
		if (vexRT[Btn7L]) {
			motor[leftMotor1] = 0;
			motor[leftMotor2] = 0;
			motor[rightMotor1] = 0;
			motor[rightMotor2] = 0;
			motor[leftLift] = -255;
			motor[rightLift] = -255;
			delay(750);
			motor[leftMotor1] = 255;
			motor[leftMotor2] = 255;
			motor[rightMotor1] = 255;
			motor[rightMotor2] = 255;
			motor[leftLift] = 0;
			motor[rightLift] = 0;
			delay(1250);
			motor[leftMotor1] = 0;
			motor[leftMotor2] = 0;
			motor[rightMotor1] = 0;
			motor[rightMotor2] = 0;
		}
	}
}
