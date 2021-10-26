#include <runtimer.h> //not in use rn

const int photoSensor = A0;
const int LED_Pin = 9;
int photoValue = 0;
int LEDvalue = 0;

intervalTimer writeOutputTimer(200U);
intervalTimer readInputTimer(50U);
intervalTimer displayValuesTimer(1000U);

void setup() {
  //delay(2000U);
  pinMode(photoSensor,INPUT);
  pinMode( LED_Pin, OUTPUT );
  Serial.begin(9600);
}

void loop() {
  if (readInputTimer.expired()){
  photoValue = analogRead(photoSensor);
  Serial.println(photoValue);
  LEDvalue = map(photoValue, 0, 200, 20, 0);
  //int lightValue = constrain(LEDvalue, 0,255);//the contain output values within 0-255 range
  //analogWrite(LED_Pin, lightValue);  
  //delay (500);
  }
  if (writeOutputTimer.expired()){
  photoValue = constrain(LEDvalue, 0,255);//the contain output values within 0-255 range
  analogWrite(LED_Pin, photoValue);  
  //delay (500);
  }
}
