#include <Zumo32U4.h>       // importerar bibliotek
#include <Wire.h>


Zumo32U4ButtonA buttonA;
Zumo32U4Motors motors;     // gir beskivande namn
Zumo32U4Encoders encoders;
Zumo32U4LCD lcd;
Zumo32U4LineSensors lineSensor;
Zumo32U4Buzzer buzzer;



int pos;
unsigned int linesensorValues[5];
int error;
const int wantedValue = 2000;
float Kp = 0.8;
float Td = 1.5;
int lastError = 0;
int time77 = 0;


void setup() {
  lineSensor.initFiveSensors();
  Serial.begin(9600);
  lineSensor.initFiveSensors();
  lcd.init();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press A Button");

  buttonA.waitForButton();
  lcd.clear();
  cal();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Calb");
  lcd.setCursor(0,1);
  lcd.print("Done");
  delay(1000);
  buzzer.playFrequency(440, 500, 8);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Currently");
  lcd.setCursor(0,1);
  lcd.print("driving");
  
}

void loop() {

  if ((millis() - time77) > 10){
    time77 = millis();
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

  pos = lineSensor.readLine(linesensorValues);
  error = pos - wantedValue;
  int speedDifference = (error * Kp) + Td * (error - lastError);
  int leftSpeed = 400 + speedDifference;
  leftSpeed = constrain(leftSpeed, 0, 30);
  int rightSpeed = 400 - speedDifference;
  rightSpeed = constrain(rightSpeed, 0, 30);
  motors.setSpeeds(leftSpeed, rightSpeed);

  lastError = error;
}


// Calibration function
// Turns car left and right while calibrating the linesensor
void cal(){
  delay(1000);
  for (int i = 0; i <= 120; i++){
    if (i > 30 && i <= 90){
      motors.setSpeeds(-150, 150);
    } else {
      motors.setSpeeds(150, -150);
    }
    lineSensor.calibrate();
  }
  motors.setSpeeds(0, 0);
}
