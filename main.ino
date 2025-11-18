#include <Servo.h>
//global values
#define enA 6
#define in1 9
#define in2 8
Servo servo;
int angle = 360;
int buttonstate = 0;
int buttonstate2 = 0;
//pins
const int servopin = 7;
const int buttonpin = 2;
const int buttonpin2 = 3;
//global time library
//State 1 timing
const int Dtstop = 500, Dtstartup = 2000, Dtrevdrive = 6000, Dtfwddrive = 4750;
//State 2 timing
const int Ltreset = 2000, Ltlaunch = 3000, Ltdrive = 3500, Ltstartup = 2000;
void setup() {
  // put your setup code here, to run once:
servo.attach(servopin);
servo.write(angle);
 // Set pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP);
  pinMode(buttonpin2, INPUT_PULLUP);
//start off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(enA, HIGH);
}

void loop() {
  //state control
buttonstate = digitalRead(buttonpin);
buttonstate2 = digitalRead(buttonpin2);
if(buttonstate == LOW){
  delay(Dtstartup);
// ---- Forward ----
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(Dtfwddrive); 

  // ---- Stop ----
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(Dtstop); 

  // ---- Reverse ----
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(Dtrevdrive); 

  // ---- Stop ----
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(Dtstop); 
}
if(buttonstate2 == LOW){
//start up
 delay(Ltstartup);
 //drive forward
 digitalWrite(in2, HIGH);
 delay(Ltdrive);
digitalWrite(in2, LOW);
 delay(500);
 digitalWrite(in2, HIGH);
 delay(Ltdrive);
 digitalWrite(in2, LOW);
 delay(Ltlaunch);
  //trigger mousetrap
  angle = 360;
  servo.write(angle);
 delay(Ltreset);
 angle = 300;
 servo.write(angle);
 delay(1000);
}

}
