#include "Thread.h"
#include "ThreadController.h"
#include "SwitchSensor.h"
#include "Stepper.h"
#include "LinearStepActuator.h"

const int m1=16;
const int m2=17;
const int m3=18;
const int m4=19;
const int swAv=42;
const int swRec=43;


ThreadController cpu;
Thread leituraDeSensores;

LinearStepActuator atuador(m1, m2, m3, m4, swAv, swRec);

void leitura(){
   atuador.linearStepActuatorControl();
}

void setup() {
  Serial.begin(9600);
  atuador.setSpeed(60);
  //atuador.stepModeOn();

  leituraDeSensores.setInterval(50);
  leituraDeSensores.onRun(leitura);

  cpu.add(&leituraDeSensores);
}

void loop() {
  cpu.run();
  bool av = atuador.isItForward();
  bool rec = atuador.isItBackward();
  int cu = 0;

    atuador.goForward();
    //atuador.goBackward();
    

  

   Serial.print("avanço: ");
   Serial.print(av);
   Serial.println(" ");
   
   Serial.print("recuo: ");
   Serial.print(rec);
   Serial.println(" ");

}
