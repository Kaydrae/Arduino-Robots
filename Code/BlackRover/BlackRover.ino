/*
 Name:		BlackRover.ino
 Created:	9/19/2015 10:45:32 AM
 Author:	Ke'Ondrae
*/

#include <Servo.h>

int MotorPin1 = 0; 
int MotorPin2 = 1;
int MotorPin3 = 2; 
int MotorPin4 = 3;
int RedF = 10;
int RedB = 13;
int GreenF = 9; 
int GreenB = 12;
int BlueF = 8;
int BlueB= 11; 
int ServoNeck = 7; 
int ServoClaw = 6; 
int trigger = 5;
int echo = 6;
int distance = 0;// distance away from object
int duration = 0;// how long it takes to receive echo
int angle = 0;

Servo servoNeck;
Servo servoClaw;

// the setup function runs once when you press reset or power the board
void setup() {

	pinMode(MotorPin1, OUTPUT); //Backwards Right
	pinMode(MotorPin2, OUTPUT); //Forward Right
	pinMode(MotorPin3, OUTPUT); //Forward Left
	pinMode(MotorPin4, OUTPUT); //Backwards Left
	pinMode(RedF, OUTPUT);
	pinMode(RedB, OUTPUT);
	pinMode(GreenF, OUTPUT);
	pinMode(GreenB, OUTPUT);
	pinMode(BlueF, OUTPUT);
	servoNeck.attach(ServoNeck);
	servoClaw.attach(ServoClaw);
	pinMode(trigger, OUTPUT);
	pinMode(echo, INPUT);

}

// the loop function runs over and over again until power down or reset
void loop() {

	ColorShow();

	ClawServo();

	NeckServo();

	ColorShow();

	Forward();
	delay(3000);

	Stop();
	delay(100);

	RightTurn();
	delay(500);

	Stop();
	delay(100);

	Backward();
	delay(1000);

	Stop();
	delay(100);

}


void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
	red = 255 - red;
	green = 255 - green;
	blue = 255 - blue;
#endif

	//Front RGB's
	analogWrite(RedF, red);
	analogWrite(GreenF, green);
	analogWrite(BlueF, blue);

	//Back RGB's
	analogWrite(RedB, red);
	analogWrite(GreenB, green);
	analogWrite(BlueB, blue);
}

void Forward() {

	digitalWrite(MotorPin2, HIGH);//Right
	digitalWrite(MotorPin3, HIGH);//Left

}

void Stop() {

	digitalWrite(MotorPin1, LOW);//Right
	digitalWrite(MotorPin2, LOW);//Right
	digitalWrite(MotorPin3, LOW);//Left
	digitalWrite(MotorPin4, LOW);//Left

}

void Backward() {

	digitalWrite(MotorPin1, HIGH);//Right
	digitalWrite(MotorPin4, HIGH);//Left


}

void RightTurn() {

	digitalWrite(MotorPin1, HIGH);//RightForward
	digitalWrite(MotorPin3, HIGH);//LeftBack
}

void LeftTurn() {
	
	digitalWrite(MotorPin2, HIGH);//RightForward
	digitalWrite(MotorPin4, HIGH);//LeftBack

}

void ColorShow() {
	//Color Show
	setColor(255, 0, 0);  // red
	delay(500);
	setColor(0, 255, 0);  // green
	delay(500);
	setColor(0, 0, 255);  // blue
	delay(500);
	setColor(255, 255, 0);  // yellow
	delay(500);
	setColor(80, 0, 80);  // purple
	delay(500);
	setColor(0, 255, 255);  // aqua
	delay(500);
}

void NeckServo() {
	// scan from 0 to 180 degrees
	for (angle = 0; angle < 180; angle++)
	{
		servoNeck.write(angle);
		delay(15);
	}
	// now scan back from 180 to 0 degrees
	for (angle = 180; angle > 0; angle--)
	{
		servoNeck.write(angle);
		delay(15);
	}
}

void ClawServo() {
	// scan from 0 to 180 degrees
	for (angle = 0; angle < 180; angle++)
	{
		servoClaw.write(angle);
		delay(15);
	}
	// now scan back from 180 to 0 degrees
	for (angle = 180; angle > 0; angle--)
	{
		servoClaw.write(angle);
		delay(15);
	}
}