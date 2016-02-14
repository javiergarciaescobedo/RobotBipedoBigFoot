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

const int TUMBLE = 30;  // Tumble right
const int TURN = 25;    // Trun Right
const int DELAY = 10;
const int SPEED = 2;

/* indicate pin numbers for each servo */
void JgBigFootRobot::init(int pinFootRight, int pinHipRight, int pinFootLeft, int pinHipLeft, int pinEyes) {
  servoFootRight.attach(pinFootRight);
  servoHipRight.attach(pinHipRight);
  servoFootLeft.attach(pinFootLeft);
  servoHipLeft.attach(pinHipLeft);
  servoEyes.attach(pinEyes);
}

/* Starting angles for each servo 
degHipRight:  increase = <-   decrease = ->
degHipLeft:   increase = <-   decrease = ->
*/
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
  animateServos(TUMBLE*0.75, -15, TUMBLE*0.75, 10, SPEED, DELAY);
  animateServos(-TUMBLE*0.75, -10, -TUMBLE*0.75, -35, SPEED, DELAY);
}

void JgBigFootRobot::stepRight() {
  animateServos(-TUMBLE, TURN, -TUMBLE, TURN, SPEED, DELAY);
  animateServos(TUMBLE, TURN, TUMBLE, TURN, SPEED, DELAY);
}

void JgBigFootRobot::stepLeft() {
  animateServos(TUMBLE, -TURN, TUMBLE, -TURN, SPEED, DELAY);
  animateServos(-TUMBLE, -TURN, -TUMBLE, -TURN, SPEED, DELAY);
}

void JgBigFootRobot::stepLastRight() {
  animateServos(-TUMBLE, TURN, -TUMBLE, TURN, SPEED, DELAY);
  animateServos(TUMBLE, 0, TUMBLE, 0, SPEED, DELAY);
}

void JgBigFootRobot::turnInPlace() {
  animateServos(-0, -TURN, -TUMBLE, -TURN/2, SPEED, DELAY);
  animateServos(-0, 0, TUMBLE, 0, SPEED, DELAY);
//  animateServos(-TUMBLE, TURN, -TUMBLE, TURN, SPEED, DELAY);
//  animateServos(TUMBLE, 0, TUMBLE, TURN, SPEED, DELAY);
//  animateServos(TUMBLE, -TURN, TUMBLE, -TURN, SPEED, DELAY);
//  animateServos(-TUMBLE, 0, -TUMBLE, -TURN, SPEED, DELAY);
//  animateServos(-20, 20, -20, 5, 2, 5);
//  animateServos(20, 0, 20, 0, 2, 5);
//  animateServos(0, 0, 20, 0, 5, 5);
//  animateServos(40, 0, 10, 0, 1, 5);
//  animateServos(0, -20, 0, -5, 2, 5);
//  animateServos(-40, 0, -30, 0, 1, 5);
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


