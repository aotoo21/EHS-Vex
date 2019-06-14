#pragma config(Motor, port10, leftMotor, tmotorNormal, openLoop)
#pragma config(Motor, port1, rightMotor, tmotorNormal, openLoop, reversed)
#pragma config(Motor, port2, armMotor, tmotorNormal, openLoop)

task main()
{
	while(true) {
		//Controlling wheel motors
		motor[leftMotor] = vexRT[Ch3];
		motor[rightMotor] = vexRT[Ch2];

		//Controlls Arm
		//Power of motor subject to change
		if (vexRT[Btn6U]==1) {
			motor[armMotor] = 100;
		}
		else if ( vexRT[Btn5U] == 1 ) {
			motor[armMotor] = -127;
		}
		else {
			motor[armMotor] = 0;
		}
	}
}
