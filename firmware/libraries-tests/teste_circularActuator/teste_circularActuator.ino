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
  

  leituraDeSensores.setInterval(50);
  leituraDeSensores.onRun(leitura);
  

  cpu.add(&leituraDeSensores);

}

void loop() {
  cpu.run();
  int flag1 = 0;
  int flag2 = 0;
  int flag3 = 0; 
   if (Serial.available())
  {
    int pos = Serial.parseInt();

    if(pos == 1 and flag1 == 0){
      mesa.goToPosition1();
      flag1 = 1;
      flag2 = 0;
      flag3 = 0;
    }
    if(pos == 2 and flag2 == 0){
      mesa.goToPosition2();
      flag1 = 0;
      flag2 = 1;
      flag3 = 0;
    }
    if(pos == 3 and flag3 == 0){
      mesa.goToPosition3();
      flag1 = 0;
      flag2 = 0;
      flag3 = 1;
    }
  }
  

}
