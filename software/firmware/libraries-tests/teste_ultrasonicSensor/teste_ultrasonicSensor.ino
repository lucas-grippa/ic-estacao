#include "Thread.h"
#include "ThreadController.h"
#include "UltrasonicSensor.h"

const int trigPin = 20;
const int echoPin = 21;

ThreadController cpu;
Thread leituraDeSensores;

UltrasonicSensor ultra(trigPin, echoPin);

void leitura(){
  ultra.readDistance();
}

void setup() {
  Serial.begin(9600);

  ultra.ultrasonicSensorCalibrate();

  leituraDeSensores.setInterval(100);
  leituraDeSensores.onRun(leitura);

  cpu.add(&leituraDeSensores);
  
}

void loop() {
  cpu.run();
  
  float distance = ultra.getDistance();
  float height = ultra.getHeight();
  bool isShort = ultra.isItShort();
  bool isHigh = ultra.isItHigh();
  
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" ");

  Serial.print("Height: ");
  Serial.print(height);
  Serial.println(" ");

  Serial.print("Short: ");
  Serial.print(isShort);
  Serial.println(" ");

  Serial.print("High: ");
  Serial.print(isHigh);
  Serial.println(" ");
  
}
