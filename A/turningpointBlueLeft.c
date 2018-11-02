#pragma config(Motor,  port2,           leftMotor2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightMotor2,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rightMotor1,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
// CLIMBING THE RAMP DOESN'T WORK
task main()
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
	delay (250);
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
