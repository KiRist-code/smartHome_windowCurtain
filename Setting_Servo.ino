#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(6); //setting pin and set 90 degrees
}

void loop() {
  servo.write(180); //or if motor goes to different way, set 0 degrees
  delay(1200);
}
