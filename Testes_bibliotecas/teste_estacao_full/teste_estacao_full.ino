#include "Thread.h"
#include "ThreadController.h"
#include "BarrierSensor.h"
#include "SwitchSensor.h"
#include "LinearDCActuator.h"
#include "UltrasonicSensor.h"
#include "ConveyorBelt.h"


int highOrLow = -1;

//Flags
int temPeca = 0;
int pecaMedida = 0;
int lastExecuteTime = -1;
int passouBarreira1 = 0;
int passouBarreira2 = 0;
int passouBarreira3 = 0;
int passouBarreira4 = 0;
const int time1 = 5000;

//Sensor ultrassoico
const int trigPin = 20;
const int echoPin = 21;

//Sensores de barreira
const int ldr1Pin = 0;
const int laser1Pin = 22;
const int ldr2Pin = 1;
const int laser2Pin = 23;
const int ldr3Pin = 2;
const int laser3Pin = 24;
const int ldr4Pin = 3;
const int laser4Pin = 25;
const int ldr5Pin = 4;
const int laser5Pin = 26;

//Atuador linear DC 1
const int at1_m1=12;
const int at1_m2=13;
const int swAv1=38;
const int swRec1=39;

//Esteira
const int belt_m1=2;
const int belt_m2=3;
const int belt_m3=4;
const int belt_m4=5;

ThreadController cpu;
Thread leituraDeSensores;
Thread controleDeAtuadores;
Thread controleDeEsteira;
Thread controleDaEstacao;

BarrierSensor sensorDeBarreira1(ldr1Pin, laser1Pin);
BarrierSensor sensorDeBarreira2(ldr2Pin, laser2Pin);
BarrierSensor sensorDeBarreira3(ldr3Pin, laser3Pin);
BarrierSensor sensorDeBarreira4(ldr4Pin, laser4Pin);
BarrierSensor sensorDeBarreira5(ldr5Pin, laser5Pin);

LinearDCActuator atuador1(at1_m1, at1_m2, swAv1, swRec1);

UltrasonicSensor ultra(trigPin, echoPin);

ConveyorBelt esteira(belt_m1, belt_m2, belt_m3, belt_m4);

bool tempo(int t){
  if(millis() - lastExecuteTime >= t){
    lastExecuteTime = millis();
    return true; 
  }else{
    return false;
  }
  
}

void monitoramento(){
  sensorDeBarreira1.readLdrValue();
  sensorDeBarreira2.readLdrValue();
  sensorDeBarreira3.readLdrValue();
  sensorDeBarreira4.readLdrValue();
  sensorDeBarreira5.readLdrValue();

  ultra.readDistance();
}

void controle(){
  atuador1.linearDCActuatorControl();
}

void esteiraControle(){
  esteira.conveyorBeltControl();
}

void controleEstacao(){
  
  Serial.println(sensorDeBarreira5.lightBlocked());
  
  if(sensorDeBarreira5.lightBlocked() or temPeca == 1){
   
     atuador1.goForward();
   
     temPeca = 1;

    if(ultra.getHeight() == 0 and pecaMedida == 0){
      Serial.println("Sem peca para medir");
      Serial.println(ultra.getHeight());
    }else{

     Serial.println(ultra.getHeight());
     
     if(pecaMedida == 0){
        if(ultra.isItShort()){
          highOrLow = 0;
        }else if(ultra.isItHigh()){
          highOrLow = 1;
        }
     }
      

      Serial.println("peca medida");
      pecaMedida = 1;

      //atuador1.goBackward();
    
      
      esteira.turnOn();

      if(sensorDeBarreira1.lightBlocked()){
          passouBarreira1 = 1;     
      }
      


      if(sensorDeBarreira4.lightBlocked()){
        if(lastExecuteTime == -1){
          lastExecuteTime = millis();
        } 
        passouBarreira4 = 1;

      }
      
      if(tempo(time1) == true and passouBarreira4 == 1){
         temPeca = 0;
         pecaMedida = 0;
         passouBarreira4 = 0;
         lastExecuteTime = -1;
         
         Serial.print("tamanho da peca: ");
         Serial.print(highOrLow);
         Serial.println(" ");
         
         esteira.turnOff();
         
      }   
      
      
    
    
   }
    
  }else{
    atuador1.goBackward();
  }
  
}


void setup() {
   Serial.begin(9600);
   
   atuador1.goBackward();
    
   sensorDeBarreira1.barrierSensorCalibrate();
   sensorDeBarreira2.barrierSensorCalibrate();
   sensorDeBarreira3.barrierSensorCalibrate();
   sensorDeBarreira4.barrierSensorCalibrate();
   sensorDeBarreira5.barrierSensorCalibrate();

   ultra.ultrasonicSensorCalibrate();

   esteira.setDirectionToRight();
   esteira.setSpeed(50);

   leituraDeSensores.setInterval(50);
   leituraDeSensores.onRun(monitoramento);

   controleDeAtuadores.setInterval(100);
   controleDeAtuadores.onRun(controle);

   controleDeEsteira.setInterval(0);
   controleDeEsteira.onRun(esteiraControle);

   controleDaEstacao.setInterval(100);
   controleDaEstacao.onRun(controleEstacao);

   cpu.add(&leituraDeSensores);
   cpu.add(&controleDeAtuadores);
   cpu.add(&controleDeEsteira);
   cpu.add(&controleDaEstacao);

}

void loop() {
  cpu.run();

}
