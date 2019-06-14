#pragma config(Motor, port1, leftMotor, tmotorNormal, openLoop, reversed)
#pragma config(Motor, port10, rightMotor, tmotorNormal, openLoop)
#pragma config(Motor, port2, forkLift, tmotorNormal, openLoop)

task main()
{
	while(true) {
		//Controlling wheel motors
		motor[leftMotor] = vexRT[Ch3];
		motor[rightMotor] = vexRT[Ch2];
	}
}
