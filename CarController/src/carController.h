#pragma once
#define carController_h
#include <Arduino.h>

//* Controls the car:
// Finds the distance between.
// Calculates the power consmuption of the car.
// Updates the car's display to show information.
class carController
{
public:
    carController();

    int findCarDistance();

    //* This function finds the distance the car has moved:
    // By using steps and the known gearRatio of the car,
    // We can find the speed of the car in Cm per second.

    int calculatePowerConsumption(int carSpeed);

    //* This function calculates the power consumption:
    // By using the speed of the car and the formula 10 + 2x,
    // where x is cm/s, the mA used is calculated.

    void updateDisplayInformation(String displayText, int displayTime);

    //* This function updates the display with information about the car:
    // It takes in the information you want to display and shows it,
    // you can control the time of how long the text should be displayed.
};