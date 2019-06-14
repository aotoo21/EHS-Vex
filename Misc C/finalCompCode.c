#pragma config(Motor, port10, leftMotor, tmotorNormal, openLoop)
#pragma config(Motor, port1, rightMotor, tmotorNormal, openLoop, reversed)
#pragma config(Motor, port2, armMotor1, tmotorNormal, openLoop, reversed)
#pragma config(Motor, port3, armMotor2, tmotorNormal, openLoop)
#pragma config(Motor, port9, forkLiftL, tmotorNormal, openLoop)
#pragma config(Motor, port8, forkLiftR, tmotorNormal, openLoop, reversed)

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
	//forward until fence
	//unfold forklift
	//lift arm
  motor[leftMotor] = 127;
	motor[rightMotor] = 127;
	delay(1400);
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	motor[forkLiftL] = -30;
	motor[forkLiftR] = -30;
	delay(750);
	motor[forkLiftL] = 0;
	motor[forkLiftR] = 0;
	motor[armMotor1] = 100;
	motor[armMotor2] = 100;
	delay(1100);
	motor[armMotor1] = 0;
	motor[armMotor2] = 0;
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

  while (true)
  {
    //Controlling wheel motors
		motor[leftMotor] = vexRT[Ch3];
		motor[rightMotor] = vexRT[Ch2];

		if(vexRT[Btn7D] == 1) {
			motor[armMotor1] = 100;
			motor[armMotor2] = 100;
			delay(1100);
		}

		//Button to be pressed that keeps arm up
		if (vexRT[Btn8R]==1) {
			motor[armMotor1] = 25;
			motor[armMotor2] = 25;
		}

		//Controlls Arm
		//Power of motor subject to change
		if (vexRT[Btn6U]==1) {
			motor[armMotor1] = 100;
			motor[armMotor2] = 100;
		}
		else if ( vexRT[Btn6D] == 1 ) {
			motor[armMotor1] = -100;
			motor[armMotor2] = -100;
		}
		else {
			motor[armMotor1] = 0;
			motor[armMotor2] = 0;
		}

		//Controlls forklift
		//buttons subject to change
		//power of motor subject to change
		if (vexRT[Btn5U]==1) {
			motor[forkLiftL] = 40;
			motor[forkLiftR] = 40;
		}
		else if (vexRT[Btn5D]==1) {
			motor[forkLiftL] = -30;
			motor[forkLiftR] = -30;
		}
		else {
			motor[forkLiftL] = 0;
			motor[forkLiftR] = 0;
		}
  }
}
