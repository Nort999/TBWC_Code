#include <Servo.h>
//global values
Servo servo;
int angle = 10;
int buttonstate = 0;
int buttonstate2 = 0;
//pins
const int servopin = 6;
const int in1 = 8;
const int in2 = 7;
const int buttonpin = 2;
const int buttonpin2 = 3;
//global time library
//State 1 timing
//State 2 timing
const int Ltaction = 2000, Ltlaunch = 3000, Ltdrive = 4000, Ltstartup = 3000;

void setup() {
  // put your setup code here, to run once:
servo.attach(servopin);
servo.write(angle);
 // Set pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(buttonpin, INPUT)
  pinMode(buttonpin2, INPUT)
}

void loop() {
  int state = 0;
  //state control
buttonstate = digitalRead(buttonPin);
buttonstate2 = digitalRead(buttonPin2);
if(buttonstate == HIGH){
  state = 1 ;
}
if(buttonstate2 == HIGH){
  state = 2 ;
}

 if(state == 0){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
 }
// STATE 1 DRIVING FUNCTION
else if(state == 1){
    // ---- Forward ----
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(3000); // run 3 seconds

  // ---- Stop ----
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000); // pause 1 second

  // ---- Reverse ----
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(3000); // run 3 seconds

  // ---- Stop ----
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(2000); // pause 2 seconds
}
//STATE 2 CATAPULT FUNCTION
 else if(state == 2){
 //start up
 delay(Ltstartup)
 //drive forward
 digitalWrite(in1, HIGH);
 delay(Ltdrive);
digitalWrite(in1, LOW);
 delay(Ltlaunch);
  //trigger mousetrap
  angle = 360;
  servo.write(angle);
 delay(Ltaction);
 angle = 10;
 servo.write(angle);
 delay(Ltaction);
 state = 0;
 }
 else
    state = 0;
}