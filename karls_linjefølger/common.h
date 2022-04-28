#pragma once
#define common_h

#include <Arduino.h>
#include <Zumo32U4.h>
#include <wire.h>

static Zumo32U4ButtonB buttonB;
static Zumo32U4Motors motors;
static Zumo32U4LCD lcd;
static Zumo32U4LineSensors lineSensor;
static Zumo32U4Buzzer buzzer;
static Zumo32U4Encoders encoders;

static int speedValue = 400;
/*  Map items:
    0: House
    1: Post office
    2: Charger
*/
static int map_layout[] = {0, 1, 0, 2};
static int map_size = 4;