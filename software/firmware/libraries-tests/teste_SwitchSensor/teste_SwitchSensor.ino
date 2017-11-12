#include "Thread.h"
#include "ThreadController.h"
#include "SwitchSensor.h"

const int swPin = 44;

ThreadController cpu;
Thread leituraDeSensores;

SwitchSensor sw(swPin);

void leitura(){
  sw.readSwitchState();
}

void setup() {
  Serial.begin(9600);

  leituraDeSensores.setInterval(50);
  leituraDeSensores.onRun(leitura);

  cpu.add(&leituraDeSensores);

}

void loop() {
  cpu.run();

  bool swState = sw.isItHigh();

  Serial.print("State: ");
  Serial.print(swState);
  Serial.println(" ");

}
