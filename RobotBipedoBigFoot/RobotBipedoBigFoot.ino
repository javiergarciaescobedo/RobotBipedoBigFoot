#include "JgBigFootRobot.h"

JgBigFootRobot jgBigFootRobot;

int stepCounter;
boolean walking = true;
const int STEPS = 5;

void setup() {
  jgBigFootRobot.init(9, 11, 10, 12, 8);
  jgBigFootRobot.calibrate(100, 110, 85, 85, 112);
  delay(1000);
  jgBigFootRobot.turnInPlace();
//  jgBigFootRobot.stepFirstLeft(); 
//  for(int i = 0; i < STEPS; i++) {
//      jgBigFootRobot.stepRight();
//      jgBigFootRobot.stepLeft();      
//  }
//  jgBigFootRobot.stepLastRight();
}

void loop() {
  
//  for(int i = 0; i < 15; i++) {
//      jgBigFootRobot.turnInPlace();
//  }
//  jgBigFootRobot.stepFirstLeft(); 
//  for(int i = 0; i < STEPS; i++) {
//      jgBigFootRobot.stepRight();
//      jgBigFootRobot.stepLeft();
//  }
//  jgBigFootRobot.stepLastRight();
//  for(int i = 0; i < 15; i++) {
//      jgBigFootRobot.turnInPlace();
//  }
//  jgBigFootRobot.stepFirstLeft(); 

}
