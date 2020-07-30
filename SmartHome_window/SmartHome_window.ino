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
//sensor: 740, humid:65%
void loop() {
  sensor();
  temhumi();
  Serial.println("============================");
  if(sens > 740 && humi > 70){
    for(int i=0;i<181;i=i+10){
      servo.write(i);
      delay(100);
    }
  }
  else{
    for(int i=180;i>=0;i=i-10){
      servo.write(i);
      delay(100);
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
  delay(2000);
  Serial.print("temperature: ");
  Serial.println(temp);
  Serial.print("Humidity: ");
  Serial.println(humi);
}
