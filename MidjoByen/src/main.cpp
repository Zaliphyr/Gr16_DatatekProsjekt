#include <Wire.h>
#include "LineFollower.h"

LineFollower ln;

void setup()
{
  ln.startUpSequence();
}

void loop()
{
  ln.lineFollower(ln.checkForTurn(0, 1, 3), ln.checkForTurn(3, 4, 1));
  ln.endOfLine();
}