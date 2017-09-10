#include <Arduino_FreeRTOS.h>
#include <ColorSensor.h>

const int s0=27;
const int s1=28;
const int s2=29;
const int s3=30;
const int out=31;

ColorSensor sensorDeCor(s0, s1, s2, s3, out);

void setup() {
  Serial.begin(9600);

  xTaskCreate(

    TaskMonitoramentoDeCor

    ,  (const portCHAR *)"MonitoramentoDeCor"   // A name just for humans

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

void TaskMonitoramentoDeCor(void *pvParameters)  // This is a task.
{

  (void) pvParameters;


  for (;;) // A Task shall never return or exit.

  {
    
    sensorDeCor.readColors();
    
  }

}

void TaskControleEstacao(void *pvParameters)  // This is a task.
{

  (void) pvParameters;


  for (;;) // A Task shall never return or exit.

  {
      Serial.print("é vermelho? ");
      Serial.print(sensorDeCor.getDataRed());
      Serial.println(" ");

      Serial.print("é verde? ");
      Serial.print(sensorDeCor.getDataGreen());
      Serial.println(" ");

      Serial.print("é azul? ");
      Serial.print(sensorDeCor.getDataBlue());
      Serial.println(" ");

      vTaskDelay( 2000 / portTICK_PERIOD_MS );
  
  
  }

}
