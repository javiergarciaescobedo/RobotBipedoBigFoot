/*
  JgBigFootRobot.h - Library for servo motors.
  Created by Javier García Escobedo, February 2, 2016.
  Released into the public domain.
*/
#ifndef JgBigFootRobot_h
#define JgBigFootRobot_h

#include "Arduino.h"
#include "Servo.h"

class JgBigFootRobot
{
  public:
    void init(int pinFootRight, int pinFootLeft, int pinHipRight, int pinHipLeft);
    void calibrate(int degFootRight, int degFootLeft, int degHipRight, int degHipLeft);
    void stepFirst();
    void stepLeft();
    void stepRight();
    void stepLast();
  private:
    void animateServos(float offsetFootRight, float offsetHipRight, float offsetFootLeft, float offsetHipLeft);
    void animateServo(Servo servo, float startDegree, float offsetAngle, int percent);
};

#endif
