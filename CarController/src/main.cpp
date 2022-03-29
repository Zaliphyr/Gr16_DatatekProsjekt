
//! Untested
// Untested code to calculate the powerconsumption of the car
// and distance it has traveled.

#include "carController.h"
#include <Arduino.h>
#include <Zumo32U4.h>

unsigned long time = millis();

int movementSpeed = 200;
Zumo32U4Motors motors;

carController cc;

void setup()
{
  // put your setup code here, to run once:
}

void loop()
{

  motors.setRightSpeed(200);
  motors.setLeftSpeed(200);
  int distance = cc.findCarDistance();
  int carSpeed = distance / millis() - time;

  int batteryChargeLeft = cc.calculatePowerConsumption(carSpeed);
  cc.updateDisplayInformation(String(batteryChargeLeft), 100);
  // updateDisplayInformation(String(powerConsumption), 100);
  time = millis();
  motors.setRightSpeed(0);
  motors.setLeftSpeed(0);
  delay(1000);
}