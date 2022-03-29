#include "carController.h"
#include <Arduino.h>
#include <Zumo32U4.h>

Zumo32U4OLED display;
Zumo32U4Encoders encoder;

carController::carController() {}

int carController::findCarDistance()
{
    int rightDistance = encoder.getCountsAndResetRight();
    int leftDistance = encoder.getCountsAndResetLeft();
    leftDistance = leftDistance / 81;
    rightDistance = rightDistance / 81;
    int distance = (leftDistance + rightDistance) / 2;
    return distance;
}

int carController::calculatePowerConsumption(int carSpeed)

{
    int powerConsumption = 10 + 2 * carSpeed;
    int batteryChargeLeft = powerConsumption / 1200;
    return batteryChargeLeft;
}

void carController::updateDisplayInformation(String displayText, int displayTime)
{
    display.clear();
    display.gotoXY(0, 0);
    display.print(String(displayText));
    delay(displayTime);
}
