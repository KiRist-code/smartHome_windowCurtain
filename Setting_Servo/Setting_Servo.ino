#include <Servo.h>
Servo servo;

void setup() {
  pinMode(6,OUTPUT);
}

void loop() {
  servo.write(0);
  delay(1200);  
}
