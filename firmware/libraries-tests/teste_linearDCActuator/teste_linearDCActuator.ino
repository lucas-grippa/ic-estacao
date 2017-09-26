#include "Thread.h"
#include "ThreadController.h"
#include "SwitchSensor.h"                                           '   
#include "LinearDCActuator.h"

const int m1=12;
const int m2=13;
const int swAv=38;
const int swRec=39;
const int m3=10;
const int m4=11;
const int swAv2=40;
const int swRec2=41;
int fo = 0;
int fu = 0;

ThreadController cpu;
Thread leituraDeSensores;

LinearDCActuator atuador(m1, m2, swAv, swRec);
LinearDCActuator atuador2(m3, m4, swAv2, swRec2);

void leitura(){
   atuador.linearDCActuatorControl();
   atuador2.linearDCActuatorControl();
}


void setup() {
 Serial.begin(9600);
  //atuador.goForward();

  leituraDeSensores.setInterval(50);
  leituraDeSensores.onRun(leitura);

  cpu.add(&leituraDeSensores);

}

void loop() {
   cpu.run();
   bool av = atuador.isItForward();
   bool rec = atuador.isItBackward();



   if (Serial.available())
  {
    int steps = Serial.parseInt();

    if(steps == 1){
      atuador.goForward();
    }
    if(steps == 2){
      atuador.goBackward();
    }
    if(steps == 3){
      atuador2.goForward();
    }
    if(steps == 4){
      atuador2.goBackward();
    }
  }

    
}
