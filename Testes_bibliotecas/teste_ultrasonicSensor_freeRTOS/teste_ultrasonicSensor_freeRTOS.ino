#include <Arduino_FreeRTOS.h>
#include <UltrasonicSensorFreeRTOS.h>

//Sensor ultrassoico
const int trigPin = 20;
const int echoPin = 21;

UltrasonicSensorFreeRTOS ultra(trigPin, echoPin);

void TaskMonitoramentoDeUltra( void *pvParameters );
void TaskControleEstacao( void *pvParameters );

void setup() {
  Serial.begin(9600);

  ultra.ultrasonicSensorCalibrate();

  xTaskCreate(

    TaskMonitoramentoDeUltra

    ,  (const portCHAR *)"MonitoramentoDeUltra"   // A name just for humans

    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater

    ,  NULL

    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.

    ,  NULL );

    xTaskCreate(

    TaskControleEstacao

    ,  (const portCHAR *)"ControleEstacao"   // A name just for humans

    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater

    ,  NULL

    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.

    ,  NULL );

}

void loop() {
  // put your main code here, to run repeatedly:

}

void TaskMonitoramentoDeUltra(void *pvParameters)  // This is a task.
{

  (void) pvParameters;


  for (;;) // A Task shall never return or exit.

  {
    
    ultra.readDistance();
    
  }

}

void TaskControleEstacao(void *pvParameters)  // This is a task.
{

  (void) pvParameters;


  for (;;) // A Task shall never return or exit.

  {
      Serial.print("tamanho da peca: ");
      Serial.print(ultra.getHeight());
      Serial.println(" ");

      Serial.print("Distancia: ");
      Serial.print(ultra.getDistance());
      Serial.println(" ");

      Serial.print("isItShort: ");
      Serial.print(ultra.isItShort());
      Serial.println(" ");

      Serial.print("isItHigh: ");
      Serial.print(ultra.isItHigh());
      Serial.println(" ");

      //vTaskDelay( 2000 / portTICK_PERIOD_MS );
  
  }

}
