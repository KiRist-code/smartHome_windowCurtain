#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(6);
}

void loop() {
  servo.write(180); //or if motor goes to different way, set 180 degrees
  delay(1200);
}
