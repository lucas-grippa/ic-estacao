#include <Arduino_FreeRTOS.h>
#include <SwitchSensor.h>
#include <CircularActuatorFreeRTOS.h>

int goMesa = 3;

const int m1 = 6;
const int m2 = 7;
const int m3 = 8;
const int m4 = 9;
const int pos1=44;
const int pos2=47;
const int pos3=46;

CircularActuatorFreeRTOS mesa(m1, m2, m3, m4, pos1, pos2, pos3);

void TaskMesaCircular( void *pvParameters );
void TaskControleEstacao( void *pvParameters );

void setup() {
  Serial.begin(9600);
   mesa.setSpeed(30);

  xTaskCreate(

    TaskMesaCircular

    ,  (const portCHAR *)"MesaCircular"   // A name just for humans

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

void TaskMesaCircular(void *pvParameters)  // This is a task.
{

  (void) pvParameters;


  for (;;) // A Task shall never return or exit.

  {
    
    mesa.circularActuatorControl();
    
  }

}

void TaskControleEstacao(void *pvParameters)  // This is a task.
{

  (void) pvParameters;


  for (;;) // A Task shall never return or exit.

  {    
      if(goMesa != 0){
       if(goMesa == 1){
        mesa.goToPosition1();
        goMesa = 0;
       }
       if(goMesa == 2){
        mesa.goToPosition2();
        goMesa = 0;
       }
       if(goMesa == 3){
        mesa.goToPosition3();
        goMesa = 0;
       }
        
      }
      Serial.print("Pos 1: ");
      Serial.print(mesa.isItInPosition1());
      Serial.println(" ");

      Serial.print("Pos 2: ");
      Serial.print(mesa.isItInPosition2());
      Serial.println(" ");

      Serial.print("Pos 3: ");
      Serial.print(mesa.isItInPosition3());
      Serial.println(" ");


  
  }

}
