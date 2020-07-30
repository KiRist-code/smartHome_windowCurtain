#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(6);
}

void loop() {
  servo.write(0);
  delay(1200);
}
