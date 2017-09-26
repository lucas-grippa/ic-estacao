#include "Thread.h"
#include "ThreadController.h"
#include "ConveyorBelt.h"

const int m1=2;
const int m2=3;
const int m3=4;
const int m4=5;

ThreadController cpu;
Thread leituraDeSensores;

ConveyorBelt esteira(m1, m2, m3, m4);

void leitura(){
   esteira.conveyorBeltControl();
}


void setup() {
  Serial.begin(9600);


  esteira.setDirectionToRight();
  esteira.setSpeed(40);
  leituraDeSensores.setInterval(0);
  leituraDeSensores.onRun(leitura);

  cpu.add(&leituraDeSensores);

}

void loop() {
  cpu.run();

   if (Serial.available())
  {
    int belt = Serial.parseInt();

    if(belt == 1){
      esteira.turnOn();
    }   
    if(belt == 2){
      esteira.turnOff();
    }
  
  }

  

}
