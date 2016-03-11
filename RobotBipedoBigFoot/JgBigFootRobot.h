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
    void init(int pinFootRight, int pinFootLeft, int pinHipRight, int pinHipLeft, int pinEyes);
    void calibrate(int degFootRight, int degFootLeft, int degHipRight, int degHipLeft, int degEyes);
    void stepFirstLeft();
    void stepLeft();
    void stepRight();
    void stepLastRight();
    void turnInPlace();
    void animateEyes();
  private:
    void animateServos(float offsetFootRight, float offsetHipRight, float offsetFootLeft, 
          float offsetHipLeft, int loopIncrement, int loopDelay);
    void animateServo(Servo servo, float startDegree, float offsetAngle, int percent);
};

#endif
