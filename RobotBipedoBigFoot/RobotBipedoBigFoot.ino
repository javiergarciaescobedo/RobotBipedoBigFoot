#include "JgBigFootRobot.h"

JgBigFootRobot jgBigFootRobot;

int stepCounter;
boolean walking = true;
const int STEPS = 2;

void setup() {
  jgBigFootRobot.init(9, 11, 10, 12);
  jgBigFootRobot.calibrate(100, 100, 85, 90);
  jgBigFootRobot.stepFirst();
}

void loop() {
  if(walking) {
    if(stepCounter < STEPS) {
      jgBigFootRobot.stepLeft();
      jgBigFootRobot.stepRight();
      stepCounter++;
    } else {
      jgBigFootRobot.stepLast();    
      walking = false;
    }
  }
}
