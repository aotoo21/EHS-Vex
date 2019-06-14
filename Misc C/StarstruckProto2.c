#pragma config(Motor, port10, leftMotor, tmotorNormal, openLoop)
#pragma config(Motor, port1, rightMotor, tmotorNormal, openLoop, reversed)
#pragma config(Motor, port2, armMotor1, tmotorNormal, openLoop, reversed)
#pragma config(Motor, port3, armMotor2, tmotorNormal, openLoop)
#pragma config(Motor, port9, forkLiftL, tmotorNormal, openLoop)
#pragma config(Motor, port8, forkLiftR, tmotorNormal, openLoop, reversed)

task main()
{
	while(true) {
		//Controlling wheel motors
		motor[leftMotor] = vexRT[Ch3];
		motor[rightMotor] = vexRT[Ch2];

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
		else if ( vexRT[Btn5U] == 1 ) {
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
		if (vexRT[Btn6D]==1) {
			motor[forkLiftL] = 30;
			motor[forkLiftR] = 30;
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
