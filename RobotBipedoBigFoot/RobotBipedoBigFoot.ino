#include "JgBigFootRobot.h"

JgBigFootRobot jgBigFootRobot;

int stepCounter;
boolean walking = true;
const int STEPS = 10;

boolean andando = false;

void setup() {
  jgBigFootRobot.init(9, 11, 10, 12, 8);
  jgBigFootRobot.calibrate(105, 102, 85, 93, 112);
  delay(2000);

  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, INPUT);
//  jgBigFootRobot.stepFirstLeft(); 
//  for(int i = 0; i < STEPS; i++) {
//      jgBigFootRobot.stepRight();
//      jgBigFootRobot.stepLeft();      
//  }
//  jgBigFootRobot.stepLastRight();
}

void loop() {
//  digitalWrite(7,LOW);
//  delayMicroseconds(5);
//  digitalWrite(7, HIGH);
//  delayMicroseconds(10);
//  long tiempo=pulseIn(6, HIGH);
//  long distancia= int(0.017*tiempo);
//  Serial.println("Distancia ");
//  Serial.println(distancia);
//  Serial.println(" cm");
//  delay(100);

  long distancia = getDistance();
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");
  delay(100);

  if(!andando && distancia > 0 && distancia < 30) {
    andando = true;
    jgBigFootRobot.stepFirstLeft(); 
  }
  if(andando) {
    jgBigFootRobot.stepRight();
    jgBigFootRobot.stepLeft();  
  } else {
    jgBigFootRobot.animateEyes();
  }
  if(andando && distancia > 30) {
    andando = false;
    jgBigFootRobot.stepLastRight();
  }

}


int getDistance() {
    long pulseDuration;
    long distance;
    int tries = 0;
    int echoPort = 6;
    digitalWrite(7, LOW); 
    delayMicroseconds(10);
    // Envío del pulso ultrasónico
    digitalWrite(7, HIGH); 
    delayMicroseconds(10);
    do {
        pulseDuration = pulseIn( echoPort, HIGH, 10000);
        distance = 0.034 * pulseDuration / 2;
        if (pulseDuration == 0) {
            delay(100);
            pinMode(echoPort, OUTPUT);
            digitalWrite(echoPort, LOW);
            delay(100);
            pinMode(echoPort, INPUT);
        }
    } while (pulseDuration == 0 && ++tries < 1);
    if (pulseDuration == 0)
      return -1;
    else
      return int(distance);
}
