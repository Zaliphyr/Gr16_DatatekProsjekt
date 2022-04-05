#include <Arduino.h>
#include <zumo32U4.h>

Zumo32U4ButtonA buttonA;
Zumo32U4Motors motors;
Zumo32U4Encoders encoders;
Zumo32U4LCD lcd;
Zumo32U4LineSensors lineSensor;
Zumo32U4Buzzer buzzer;

void turnAngle(int Angle);

void setup()
{
  // put your setup code here, to run once:
}

void loop()
{
  // put your main code here, to run repeatedly:
  buttonA.waitForButton();
  turnAngle(180);
}

void turnAngle(int angle)
{
  // turn the robot by angle degrees
  int leftStartAngle = encoders.getCountsLeft();
  int rightStartAngle = encoders.getCountsRight();

  motors.setSpeeds(0, 0);
  delay(250);

  if (angle > 0)
  {
    while (angle > (encoders.getCountsLeft() - leftStartAngle) / 7.5)
    {
      motors.setSpeeds(200, -200);
    }
  }
  else if (angle < 0)
  {
    while (abs(angle) > (encoders.getCountsRight() - rightStartAngle) / 7.5)
    {
      motors.setSpeeds(-200, 200);
    }
  }
  motors.setSpeeds(0, 0);
}