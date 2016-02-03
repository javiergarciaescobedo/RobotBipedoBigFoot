#include <Servo.h>
 
Servo myservoPieDerecho;
Servo myservoPieIzquierdo;
Servo myservoCaderaDerecho;
Servo myservoCaderaIzquierdo;
 
int pos = 0;    // variable to store the servo position
int PIN_PIE_DERECHO = 9;
int PIN_PIE_IZQUIERDO = 10;
int PIN_CADERA_DERECHO = 11;
int PIN_CADERA_IQUIERDO = 12;

int PIE_DERECHO_PLANO = 100;
int PIE_IZQUIERDO_PLANO = 100;
int CADERA_DERECHO_CENTRO = 105;
int CADERA_IZQUIERDO_CENTRO = 105;

const int PIE_DERECHO = 0;
const int PIE_IZQUIERDO = 1;
const int CADERA_DERECHO = 2;
const int CADERA_IZQUIERDO = 3;

const int FUERA = 0;
const int CENTRO = 1;
const int DENTRO = 2;
const int PLANO = 3;
const int LEVANTA = 4;

const int RETARDO = 100;
const int RETARDO2 = 500;

int andando = true;
int contador = 0;
 
void setup()
{
  myservoPieDerecho.attach(PIN_PIE_DERECHO);
  myservoPieIzquierdo.attach(PIN_PIE_IZQUIERDO);
  myservoCaderaDerecho.attach(PIN_CADERA_DERECHO);
  myservoCaderaIzquierdo.attach(PIN_CADERA_IQUIERDO);

  firme();
  paso1();
}
 
 
void loop() {  
  if(andando) {
    paso2();
    paso3();
    contador++;
    if(contador >= 5) {
      andando = false;
      firme();
    }
  }
}

void firme() {
  mover(PIE_DERECHO, 0);
  mover(PIE_IZQUIERDO, 0);
  mover(CADERA_DERECHO, 0);
  mover(CADERA_IZQUIERDO, 0);
}

void paso1() {
  mover(CADERA_DERECHO, -35); // dentro
  delay(RETARDO);
  mover(PIE_DERECHO, 10); // Levanta un poco
  delay(RETARDO);
  mover(PIE_IZQUIERDO, 35);  // Levanta
  delay(RETARDO);
  mover(PIE_DERECHO, 35); // Levanta todo
  delay(RETARDO);
  mover(CADERA_IZQUIERDO, -35); // fuera
  delay(RETARDO);

  mover(PIE_IZQUIERDO, 0);
  delay(RETARDO);
  mover(PIE_DERECHO, 0);
  delay(RETARDO);
}

void paso2() {
  mover(PIE_IZQUIERDO, -20); // LEvanta un poco
  delay(RETARDO);
  mover(PIE_DERECHO, -30); // Dobla fuera para empujar
  delay(RETARDO);  
  mover(PIE_IZQUIERDO, -40); // LEvanta un poco
  delay(RETARDO);
  mover(PIE_DERECHO, 0); 
  delay(RETARDO);  
  mover(CADERA_IZQUIERDO, 0); // 
  delay(RETARDO);
  mover(CADERA_DERECHO, 0); // 
  delay(RETARDO);
  mover(CADERA_IZQUIERDO, 40); // 
  delay(RETARDO);
  mover(CADERA_DERECHO, 40); // 
  delay(RETARDO);
  mover(PIE_IZQUIERDO, 0); 
  delay(RETARDO);
}

void paso3() {
  mover(PIE_DERECHO, 20); // LEvanta un poco
  delay(RETARDO);
  mover(PIE_IZQUIERDO, 30); // Dobla fuera para empujar
  delay(RETARDO);  
  mover(PIE_DERECHO, 40); // LEvanta un poco
  delay(RETARDO);
  mover(PIE_IZQUIERDO, 0); 
  delay(RETARDO);  
  mover(CADERA_DERECHO, 0); // 
  delay(RETARDO);
  mover(CADERA_IZQUIERDO, 0); // 
  delay(RETARDO);
  mover(CADERA_DERECHO, -40); // 
  delay(RETARDO);
  mover(CADERA_IZQUIERDO, -40); // 
  delay(RETARDO);
  mover(PIE_DERECHO, 0); 
  delay(RETARDO);
}


void mover(int motor, int giro) {
  switch(motor) {
    case PIE_DERECHO:
      myservoPieDerecho.write(PIE_DERECHO_PLANO + giro);
      break;
    case PIE_IZQUIERDO:
      myservoPieIzquierdo.write(PIE_IZQUIERDO_PLANO + giro);
      break;
    case CADERA_DERECHO:
      myservoCaderaDerecho.write(CADERA_DERECHO_CENTRO + giro);
      break;
    case CADERA_IZQUIERDO:
      myservoCaderaIzquierdo.write(CADERA_IZQUIERDO_CENTRO + giro);
      break;
  }
}


