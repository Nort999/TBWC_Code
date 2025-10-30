#include <Servo.h>
Servo servo;
int angle = 10;
int in1 = 8;
int in2 = 7;

void setup() {
  // put your setup code here, to run once:
servo.attach(4);
servo.write(angle);
 // Set pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  int state = 0;
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
  angle = 0;
  servo.write(angle);
 delay(2);
 angle = 180;
 servo.write(angle);
 delay(2);
 }
 else
    state = 0;
}