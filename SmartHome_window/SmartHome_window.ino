#include <Servo.h>
#include <DHT11.h>
Servo servo;
DHT11 dht(7);

float temp,humi;
int sens;
int temperhumid;

void setup() {
  servo.attach(6);
  Serial.begin(9600);
  pinMode(A0,INPUT);
}
//In this building,bright sensor is usually 740,and humid is 65%
void loop() {
  sensor();
  temhumi();
  delay(2000);
  Serial.println("============================");
  if(sens < 740){
    if(humi < 70) {
      servo.write(0);
    }
    else{
      servo.write(180);
    }
  }
  else{
    if(humi < 70) {
      servo.write(135); 
    }
    else{
      servo.write(180);
    }
  }
}

void sensor() {
  sens = analogRead(A0);
  Serial.print("sensor value: ");
  Serial.println(sens);
}

void temhumi() {
  temperhumid = dht.read(humi,temp);
  Serial.print("temperature: ");
  Serial.println(temp);
  Serial.print("Humidity: ");
  Serial.println(humi);
}
