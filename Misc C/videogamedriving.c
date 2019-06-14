#pragma config(Motor,  port1,           r1,            tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           r2,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           l1,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          l2,            tmotorVex393_HBridge, openLoop)
task main()
{
	/* Option 1
	while (true){
		if (vexRT[Ch1]<25 && vexRT[Ch1]>-25){
			motor[r1] = vexRT[Ch2];
			motor[r2] = vexRT[Ch2];
			motor[l1] = vexRT[Ch2];
			motor[l2] = vexRT[Ch2];
		}
		else if (vexRT[Ch1]>25 && vexRT[Ch2] > 0) {
			motor[l1] = vexRT[Ch2];
			motor[l2] = vexRT[Ch2];
			motor[r1] = -vexRT[Ch1];
			motor[r2] = -vexRT[Ch1];
		}
		else if (vexRT[Ch1]<-25 && vexRT[Ch2] > 0) {
			motor[r1] = vexRT[Ch2];
			motor[r2] = vexRT[Ch2];
			motor[l1] = vexRT[Ch1];
			motor[l2] = vexRT[Ch1];
		}
		else if (vexRT[Ch1]>25 && vexRT[Ch2] < 0) {
			motor[l1] = vexRT[Ch2];
			motor[l2] = vexRT[Ch2];
			motor[r1] = vexRT[Ch1];
			motor[r2] = vexRT[Ch1];
		}
		else if (vexRT[Ch1]<-25 && vexRT[Ch2] < 0) {
			motor[r1] = vexRT[Ch2];
			motor[r2] = vexRT[Ch2];
			motor[l1] = -vexRT[Ch1];
			motor[l2] = -vexRT[Ch1];
		}
		else {
			motor[r1] = 0;
			motor[r2] = 0;
			motor[l1] = 0;
			motor[l2] = 0;
		}
	}*/
	//Option 2
	while (true) {
		while (vexRT[Btn6D]==1){
			if (vexRT[Ch1]>10) {
				motor[l1] = -127;
				motor[l2] = -127;
				motor[r1] = -(127-vexRT[Ch1]);
				motor[r2] = -(127-vexRT[Ch1]);
			}
			else {
				motor[r1] = -127;
				motor[r2] = -127;
				motor[l1] = -(127+vexRT[Ch1]);
				motor[l2] = -(127+vexRT[Ch1]);
			}
		}
		while (vexRT[Btn6U]==1){
			if (vexRT[Ch1]>10) {
				motor[l1] = 127;
				motor[l2] = 127;
				motor[r1] = 127-vexRT[Ch1];
				motor[r2] = 127-vexRT[Ch1];
			}
			else {
				motor[r1] = 127;
				motor[r2] = 127;
				motor[l1] = 127+vexRT[Ch1];
				motor[l2] = 127+vexRT[Ch1];
			}
		}
		motor[r1] = 0;
		motor[r2] = 0;
		motor[l1] = 0;
		motor[l2] = 0;
	}
}
