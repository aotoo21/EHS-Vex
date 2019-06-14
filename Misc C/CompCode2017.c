#pragma config(Motor,  port1,           r1,            tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           r2,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           lift1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           lift2,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           pick2,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           pick1,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           l1,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          l2,            tmotorVex393_HBridge, openLoop)
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

task autonomous()
{
	//Autonomous code goes here
		motor[r1] = 90;
	motor[r2] = 90;
	motor[l1] = 127;
	motor[l2] = 127;
	delay(2600);
	motor[r1] = 127;
	motor[r2] = 127;
	motor[l1] = -127;
	motor[l2] = -127;
	delay(700);
	motor[r1] = 127;
	motor[r2] = 127;
	motor[l1] = 127;
	motor[l2] = 127;
	delay(900);
	motor[r1] = 127;
	motor[r2] = 127;
	motor[l1] = -127;
	motor[l2] = -127;
	delay(800);
	motor[r1] = 127;
	motor[r2] = 127;
	motor[l1] = 127;
	motor[l2] = 127;
	delay(5000);
	motor[r1] = 0;
	motor[r2] = 0;
	motor[l1] = 0;
	motor[l2] = 0;
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
  // User control code here, inside the loop
 while(true){
		motor[r1] = vexRT[Ch2];
		motor[r2] = vexRT[Ch2];
		motor[l1] = vexRT[Ch3];
		motor[l2] = vexRT[Ch3];
		while(vexRT[Btn5U]){
			motor[lift1] = 270;
			motor[lift2] = 270;
		}
		while(vexRT[Btn5D]){
			motor[lift1] = -80;
			motor[lift2] = -80;
		}
		while(vexRT[Btn8U]) {
			motor[r1] = 270;
			motor[r2] = 270;
			motor[l1] = 270;
			motor[l2] = 270;
		}
		while (vexRT[Btn8D]) {
			motor[r1] = -270;
			motor[r2] = -270;
			motor[l1] = -270;
			motor[l2] = -270;
		}
		while (vexRT[Btn8R]) {
			motor[r1] = -270;
			motor[r2] = -270;
			motor[l1] = 270;
			motor[l2] = 270;
		}
		while (vexRT[Btn8L]) {
			motor[r1] = 270;
			motor[r2] = 270;
			motor[l1] = -270;
			motor[l2] = -270;
		}
		while (vexRT[Btn7U]) {
			motor[pick1] = 40;
			while (vexRT[Btn6U]) {
				motor[pick2] = 127;
			}
		}
		while (vexRT[Btn7D]) {
			motor[pick1] = -40;
		}
		while (vexRT[Btn6U]) {
			motor[pick2] = 127;
			while (vexRT[Btn7U]) {
				motor[pick1] = 40;
			}
		}
		while (vexRT[Btn6D]) {
			motor[pick2] = -100;
		}
		motor[pick2] = 0;
		motor[pick1] = 0;
		motor[lift1] = 0;
		motor[lift2] = 0;
	}
}
