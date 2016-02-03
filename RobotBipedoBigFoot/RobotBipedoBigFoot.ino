#include "JgBigFootRobot.h"

JgBigFootRobot jgBigFootRobot;

void setup() {
  // put your setup code here, to run once:
//Serial.begin(9600);
  jgBigFootRobot.init(9, 11, 10, 12);
  jgBigFootRobot.calibrate(100, 95, 105, 110);
  jgBigFootRobot.step();
}

void loop() {
  //Serial.println("test");
  //jgBigFootRobot.rotateTo(90);
//  servo1.write(60);
//  delay(1000);
}
