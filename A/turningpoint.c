#pragma config(Motor,  port2,           leftMotor2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightMotor2,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rightMotor1,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
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
		// Blue right autonomous (doesn't work)
		if (vexRT[Btn7D]) {
			motor[leftMotor1] = 255;
			motor[leftMotor2] = 255;
			motor[rightMotor1] = 255;
			motor[rightMotor2] = 255;
			delay (1000);
			motor[leftLift] = 255;
			motor[rightLift] = 255;
			delay (1300);
			motor[leftLift] = 0;
			motor[rightLift] = 0;
			motor[leftMotor1] = -255;
			motor[leftMotor2] = -255;
			motor[rightMotor1] = -255;
			motor[rightMotor2] = -255;
			delay(1000);
			motor[rightMotor1] = 255;
			motor[rightMotor2] = 255;
			delay(700);
			motor[leftMotor1] = 255;
			motor[leftMotor2] = 255;
			motor[rightMotor1] = 255;
			motor[rightMotor2] = 255;
			delay(1500);
			motor[leftMotor1] = 0;
			motor[leftMotor2] = 0;
			motor[rightMotor1] = 0;
			motor[rightMotor2] = 0;
			motor[leftLift] = -255;
			motor[rightLift] = -255;
			delay (1300);
			motor[leftLift] = 0;
			motor[rightLift] = 0;
			motor[leftMotor1] = 255;
			motor[leftMotor2] = 255;
			motor[rightMotor1] = 255;
			motor[rightMotor2] = 255;
			delay (1250);
			motor[leftMotor1] = 0;
			motor[leftMotor2] = 0;
			motor[rightMotor1] = 0;
			motor[rightMotor2] = 0;
		}
	}
}
