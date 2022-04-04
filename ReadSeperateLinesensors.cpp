#include <Arduino.h>
#include <Zumo32U4.h>

Zumo32U4LineSensors lineSensor;
unsigned int linesensorValues[5];

void setup() {
  lineSensor.initFiveSensors();
  Serial.begin(9600);
}

void loop() {
    lineSensor.read(linesensorValues);
    Serial.print(linesensorValues[0]);
    Serial.print(" ");
    Serial.print(linesensorValues[1]);
    Serial.print(" ");
    Serial.print(linesensorValues[2]);
    Serial.print(" ");
    Serial.print(linesensorValues[3]);
    Serial.print(" ");
    Serial.print(linesensorValues[4]);
    Serial.println(" ");
}
