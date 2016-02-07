/*
  JgBigFootRobot.cpp - Library for servo motors.
  Created by Javier García Escobedo, February 2, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "JgBigFootRobot.h"
#include "Servo.h"

Servo servoFootRight;
Servo servoFootLeft;
Servo servoHipRight;
Servo servoHipLeft;
Servo servoEyes;

float _degFootRight;  // Current angle for right foot
float _degFootLeft;   // Current angle for left foot
float _degHipRight;   // Current angle for right hip
float _degHipLeft;    // Current angle for left hip
float _degEyes;       // Current angle for eyes

/* indicate pin numbers for each servo */
void JgBigFootRobot::init(int pinFootRight, int pinHipRight, int pinFootLeft, int pinHipLeft, int pinEyes) {
  servoFootRight.attach(pinFootRight);
  servoHipRight.attach(pinHipRight);
  servoFootLeft.attach(pinFootLeft);
  servoHipLeft.attach(pinHipLeft);
  servoEyes.attach(pinEyes);
}

/* Starting angles for each servo */
void JgBigFootRobot::calibrate(int degFootRight, int degHipRight, int degFootLeft, int degHipLeft, int degEyes) {
  servoFootRight.write(degFootRight);
  _degFootRight = degFootRight;
  servoHipRight.write(degHipRight);
  _degHipRight = degHipRight;
  servoFootLeft.write(degFootLeft);
  _degFootLeft = degFootLeft;
  servoHipLeft.write(degHipLeft);
  _degHipLeft = degHipLeft;
  servoEyes.write(degEyes);
  _degEyes = degEyes;
}

void JgBigFootRobot::stepFirstLeft() {
  animateServos(20, 0, 40, 0, 1, 5);
  animateServos(20, -15, 0, -15, 1, 5);
  animateServos(0, -15, 0, -15, 1, 5);
  animateServos(-40, 0, -40, 0, 1, 5);
}

void JgBigFootRobot::stepRight() {
  animateServos(-40, 30, -40, 30, 1, 5);
  animateServos(40, 30, 40, 30, 1, 5);
}

void JgBigFootRobot::stepLeft() {
  animateServos(40, -30, 40, -30, 1, 5);
  animateServos(-40, -30, -40, -30, 1, 5);
}

void JgBigFootRobot::stepLastRight() {
  animateServos(-40, 30, -40, 30, 1, 5);
  animateServos(40, 0, 40, 0, 1, 5);
}

void JgBigFootRobot::turnInPlace() {
  animateServos(-20, 20, -20, 5, 2, 5);
  animateServos(20, 0, 20, 0, 2, 5);
  animateServos(0, 0, 20, 0, 5, 5);
  animateServos(40, 0, 10, 0, 1, 5);
  animateServos(0, -20, 0, -5, 2, 5);
  animateServos(-40, 0, -30, 0, 1, 5);
}

/* Rotate the 4 servos with the increment o decrement angle specified in parameters */
void JgBigFootRobot::animateServos(float offsetFootRight, float offsetHipRight, 
      float offsetFootLeft, float offsetHipLeft, int loopIncrement, int loopDelay) {
  for(int i = 0; i < 100; i += loopIncrement) {
    animateServo(servoFootRight, _degFootRight, offsetFootRight, i);
    animateServo(servoHipRight, _degHipRight, offsetHipRight, i);
    animateServo(servoFootLeft, _degFootLeft, offsetFootLeft, i);
    animateServo(servoHipLeft, _degHipLeft, offsetHipLeft, i);
    delay(loopDelay);
  }  
  _degFootRight += offsetFootRight;
  _degHipRight += offsetHipRight;
  _degFootLeft += offsetFootLeft;
  _degHipLeft += offsetHipLeft;
}

/* Rotate a servo starting from startDegree angle and it will be rotated with the increment
or decrement specified in offsetAngle, considering the percentage value to complete that rotation */
void JgBigFootRobot::animateServo(Servo servo, float startDegree, float offsetAngle, int percent) {
  float angle = startDegree + (offsetAngle * (percent / 100.0));
  servo.write(angle);
}


