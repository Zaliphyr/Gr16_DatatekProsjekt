#include "common.h"
#include "cc.h"

cc cc;

void setup() {
  Serial.begin(115200);
  cc.init();
  lcd.clear();
}

void loop() {
  cc.loop();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(cc.cc_state);
  lcd.setCursor(0, 1);
  lcd.print(cc.step);
}
