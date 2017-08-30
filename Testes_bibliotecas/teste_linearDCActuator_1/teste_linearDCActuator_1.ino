#include "Thread.h"
#include "ThreadController.h"
#include "SwitchSensor.h"
#include "LinearDCActuator.h"

const int m1=12;
const int m2=13;
const int swAv=38;
const int swRec=39;
int fo = 0;
int fu = 0;

ThreadController cpu;
Thread leituraDeSensores;

LinearDCActuator atuador(m1, m2, swAv, swRec);

void leitura(){
   atuador.linearDCActuatorControl();
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


   
      atuador.goBackward();
    
    
    

  

   Serial.print("avanço: ");
   Serial.print(av);
   Serial.println(" ");
   
   Serial.print("recuo: ");
   Serial.print(rec);
   Serial.println(" ");

}
