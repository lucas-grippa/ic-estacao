#include "Thread.h"
#include "ThreadController.h"
#include "ColorSensor.h"

const int s0=27;
const int s1=28;
const int s2=29;
const int s3=30;
const int out=31;

ThreadController cpu;
Thread leituraDeSensores;

ColorSensor sensorDeCor(s0, s1, s2, s3, out);

void leitura(){
  sensorDeCor.readColors();
}

void setup() {
  Serial.begin(9600);

  leituraDeSensores.setInterval(100);
  leituraDeSensores.onRun(leitura);

  cpu.add(&leituraDeSensores);

}

void loop() {
  cpu.run();
  
  int red = sensorDeCor.getDataRed();
  int green = sensorDeCor.getDataGreen();
  int blue = sensorDeCor.getDataBlue();

  Serial.print("é vermelho? ");
  Serial.print(red);
  Serial.println(" ");

  Serial.print("é verde? ");
  Serial.print(green);
  Serial.println(" ");

  Serial.print("é azul? ");
  Serial.print(blue);
  Serial.println(" ");

  delay(2000);

}
