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

float _degFootRight;
float _degFootLeft;
float _degHipRight;
float _degHipLeft;

void JgBigFootRobot::init(int pinFootRight, int pinHipRight, int pinFootLeft, int pinHipLeft) {
  servoFootRight.attach(pinFootRight);
  servoHipRight.attach(pinHipRight);
  servoFootLeft.attach(pinFootLeft);
  servoHipLeft.attach(pinHipLeft);
}

void JgBigFootRobot::calibrate(int degFootRight, int degHipRight, int degFootLeft, int degHipLeft) {
  servoFootRight.write(degFootRight);
  _degFootRight = degFootRight;
  servoHipRight.write(degHipRight);
  _degHipRight = degHipRight;
  servoFootLeft.write(degFootLeft);
  _degFootLeft = degFootLeft;
  servoHipLeft.write(degHipLeft);
  _degHipLeft = degHipLeft;
}

void JgBigFootRobot::step() {
  animateServos(0, 40, 0, 30);
  animateServos(20, 0, 20, 0);  
  animateServos(20, -40, 0, -30);  
  //animateServos(0, 0, 0, 0);  // Bueno pero al revés
  //animateServos(40, 0, -20, 20);  // Bueno pero al revés
  //animateServos(0, 40, 20, 0);
}

void JgBigFootRobot::animateServos(float offsetFootRight, float offsetHipRight, float offsetFootLeft, float offsetHipLeft) {
  for(int i=0; i<100; i++) {
    animateServo(servoFootRight, _degFootRight, offsetFootRight, i);
    animateServo(servoHipRight, _degHipRight, offsetHipRight, i);
    animateServo(servoFootLeft, _degFootLeft, offsetFootLeft, i);
    animateServo(servoHipLeft, _degHipLeft, offsetHipLeft, i);
    delay(10);
  }  
  _degFootRight += offsetFootRight;
  _degHipRight += offsetHipRight;
  _degFootLeft += offsetFootLeft;
  _degHipLeft += offsetHipLeft;
}

void JgBigFootRobot::animateServo(Servo servo, float startDegree, float offsetAngle, int percent) {
  float angle = startDegree + (offsetAngle * (percent / 100.0));
  servo.write(angle);
}


