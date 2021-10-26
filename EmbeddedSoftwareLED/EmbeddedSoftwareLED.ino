#include <runtimer.h>

const int photoSensor = A0;
const int LED_Pin = 9;
int photoValue = 0;
int LEDvalue = 0;

void setup() {
  pinMode(photoSensor,INPUT);
  pinMode( LED_Pin, OUTPUT );
  Serial.begin(9600);

}

void loop() {
  photoValue = analogRead(photoSensor);
  Serial.println(photoValue);
  LEDvalue = map(photoValue, 0, 200, 20, 0);
  int lightValue = constrain(LEDvalue, 0,255);//the contain output values within 0-255 range
  analogWrite(LED_Pin, lightValue);  
  delay (500);

}
