#include <Arduino_FreeRTOS.h>
#include <ConveyorBeltFreeRTOS.h>

//Esteira
const int belt_m1=2;
const int belt_m2=3;
const int belt_m3=4;
const int belt_m4=5;

ConveyorBeltFreeRTOS esteira(belt_m1, belt_m2, belt_m3, belt_m4);

void TaskControleEsteira( void *pvParameters );
void TaskControleEstacao( void *pvParameters );

void setup() {
  Serial.begin(9600);

  esteira.setDirectionToRight();
  esteira.setSpeed(50);

  xTaskCreate(

    TaskControleEsteira

    ,  (const portCHAR *)"ControleEsteira"   // A name just for humans

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

void TaskControleEsteira(void *pvParameters)  // This is a task.
{

  (void) pvParameters;


  for (;;) // A Task shall never return or exit.

  {
   esteira.conveyorBeltFreeRTOSControl();
  }

}

void TaskControleEstacao(void *pvParameters)  // This is a task.
{

  (void) pvParameters;


  for (;;) // A Task shall never return or exit.

  {
    esteira.turnOn();
    Serial.println(esteira.getOnOffStatus());
  
  }

}
