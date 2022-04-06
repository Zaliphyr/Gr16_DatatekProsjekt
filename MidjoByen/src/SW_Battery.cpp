#include "SW_Battery.h"
#include <Arduino.h>
#include <Wire.h>
#include <Zumo32U4.h>
#include "common.h"

int carController::getCarDistance()
{
    int rightDistance = encoders.getCountsRight();
    int leftDistance = encoders.getCountsLeft();
    leftDistance = leftDistance / 81;
    rightDistance = rightDistance / 81;
    int distance = (leftDistance + rightDistance) / 2;
    return distance;
}

void carController::resetCarDistance()
{
    encoders.getCountsAndResetLeft();
    encoders.getCountsAndResetRight();
}

int carController::calculatePowerConsumption(int carSpeed)

{
    int powerConsumption = 10 + 2 * carSpeed;
    int batteryChargeLeft = powerConsumption / 1200;
    return batteryChargeLeft;
}

void carController::updateDisplayInformation(String displayText, int displayTime)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(String(displayText));
    delay(displayTime);
}
