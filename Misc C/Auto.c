#pragma config(Motor, port10, leftMotor, tmotorNormal, openLoop)
#pragma config(Motor, port1, rightMotor, tmotorNormal, openLoop, reversed)
#pragma config(Motor, port2, armMotor1, tmotorNormal, openLoop, reversed)
#pragma config(Motor, port3, armMotor2, tmotorNormal, openLoop)
#pragma config(Motor, port9, forkLiftL, tmotorNormal, openLoop)
#pragma config(Motor, port8, forkLiftR, tmotorNormal, openLoop, reversed)

task main()
{
	motor[leftMotor] = 127;
	motor[rightMotor] = 127;
	delay(1500);
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
	motor[armMotor1] = 25;
	motor[armMotor2] = 25;
}
