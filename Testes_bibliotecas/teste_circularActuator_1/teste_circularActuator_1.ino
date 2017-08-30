#include "Thread.h"
#include "ThreadController.h"
#include "SwitchSensor.h"
#include "CircularActuator.h"

const int m1 = 6;
const int m2 = 7;
const int m3 = 8;
const int m4 = 9;
const int pos1=44;
const int pos2=47;
const int pos3=46;

ThreadController cpu;
Thread leituraDeSensores;

CircularActuator mesa(m1, m2, m3, m4, pos1, pos2, pos3);

void leitura(){
   mesa.circularActuatorControl();
}


void setup() {
  Serial.begin(9600);
  mesa.setSpeed(40);
  mesa.goToPosition3();

  leituraDeSensores.setInterval(50);
  leituraDeSensores.onRun(leitura);
  

  cpu.add(&leituraDeSensores);

}

void loop() {
  cpu.run();
  bool um = mesa.isItInPosition1();
  bool dois = mesa.isItInPosition2();
  bool tres = mesa.isItInPosition3();
  
  Serial.print("Pos 1: ");
  Serial.print(um);
  Serial.println(" ");

  Serial.print("Pos 2: ");
  Serial.print(dois);
  Serial.println(" ");

  Serial.print("Pos 3: ");
  Serial.print(tres);
  Serial.println(" ");

}
