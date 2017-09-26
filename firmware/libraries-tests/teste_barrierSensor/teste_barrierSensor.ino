#include "Thread.h"
#include "ThreadController.h"
#include "BarrierSensor.h"

int ldrPin = 0;
int laserPin = 7;

int calibrate = 0;

ThreadController cpu;

Thread leituraDeSensores;

BarrierSensor barreira1(ldrPin, laserPin);

void leitura(){
  barreira1.readLdrValue();
}

void setup() {
  Serial.begin(9600);
  barreira1.barrierSensorCalibrate();

  calibrate = barreira1.getCalibratedValue();

  Serial.print("Calibrated value: ");
  Serial.print(calibrate);
  Serial.println(" ");
  
  leituraDeSensores.setInterval(50);
  leituraDeSensores.onRun(leitura);

  cpu.add(&leituraDeSensores);

 

}

void loop() {
  cpu.run();
  int ldrValue = barreira1.getLdrValue();
  bool light = barreira1.lightBlocked();

  Serial.print("LDR value: ");
  Serial.print(ldrValue);
  Serial.println(" ");

  Serial.print("Light blocked?: ");
  Serial.print(light);
  Serial.println(" ");
  

}
