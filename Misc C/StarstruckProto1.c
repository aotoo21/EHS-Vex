#pragma config(Motor, port1, leftMotor, tmotorNormal, openLoop, reversed)
#pragma config(Motor, port10, rightMotor, tmotorNormal, openLoop)
#pragma config(Motor, port2, forkLift, tmotorNormal, openLoop)

task main()
{
	while(true) {
		//Controlling wheel motors
		motor[leftMotor] = vexRT[Ch3];
		motor[rightMotor] = vexRT[Ch2];

		/*
		if should statements reduce the problem of joysticks not centering but causes more complications
		if (vexRT[Ch3]>=10||vexRT[Ch3]<=-10) {
			motor[leftMotor] = vexRT[Ch3];
			motor[rightMotor] = vexRT[Ch2];
		}
		if (vexRT[Ch2]>=10||vexRT[Ch2]<=-10) {
			motor[rightMotor] = vexRT[Ch2];
			motor[leftMotor] = vexRT[Ch3];
		}
		*/

		/*
		Version of controlling forklift with bumpers
		Values of the power is subject to change
		if(vexRT[Btn6U]==1) {
			motor[forkLift] = 127;
		}
		else if(vexRT[Btn5U]==1) {
			motor[forkLift] = -127;
		}
		*/

		/*
		Possibly use joystick from a second controller to control the forklift/catapult
		most likely to be used for final version
		motor[forkLift] = vexRT[Ch3Xmtr2];
		*/
	}
}
