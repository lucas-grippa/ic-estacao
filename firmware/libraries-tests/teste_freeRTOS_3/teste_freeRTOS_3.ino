#include <Arduino_FreeRTOS.h>
#include <BarrierSensor.h>
#include <ColorSensor.h>
#include <SwitchSensor.h>
#include <LinearDCActuator.h>
#include <UltrasonicSensorFreeRTOS.h>
#include <ConveyorBeltFreeRTOS.h>
#include <Stepper.h>
#include <LinearStepActuator.h>
#include <CircularActuatorFreeRTOS.h>
#include <LiquidCrystal.h>
#include <DisplayInterface.h>

int highOrLow = -1;

String linha1 = "";
String linha2 = "";


//Flags
int temPeca = 0;
int pecaMedida = 0;
int cor = 0;
int mesaAcionada = 0;

//Sensor de cor
const int s0=27;
const int s1=28;
const int s2=29;
const int s3=30;
const int out=31;

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

//Atuador linear DC 2
const int at2_m1=10;
const int at2_m2=11;
const int swAv2=40;
const int swRec2=41;

//Atuador linear step 3
const int at3_m1=16;
const int at3_m2=17;
const int at3_m3=18;
const int at3_m4=19;
const int swAv3=42;
const int swRec3=43;

//Esteira
const int belt_m1=2;
const int belt_m2=3;
const int belt_m3=4;
const int belt_m4=5;

//Atuador circular
const int cl_m1 = 6;
const int cl_m2 = 7;
const int cl_m3 = 8;
const int cl_m4 = 9;
const int pos1=44;
const int pos2=47;
const int pos3=46;

//Display lcd
const int lcd1 = 37;
const int lcd2 = 36;
const int lcd3 = 35;
const int lcd4 = 34;
const int lcd5 = 33; 
const int lcd6 = 32;

BarrierSensor sensorDeBarreira1(ldr1Pin, laser1Pin);
BarrierSensor sensorDeBarreira2(ldr2Pin, laser2Pin);
BarrierSensor sensorDeBarreira3(ldr3Pin, laser3Pin);
BarrierSensor sensorDeBarreira4(ldr4Pin, laser4Pin);
BarrierSensor sensorDeBarreira5(ldr5Pin, laser5Pin);

LinearDCActuator atuador1(at1_m1, at1_m2, swAv1, swRec1);

LinearDCActuator atuador2(at2_m1, at2_m2, swAv2, swRec2);

LinearStepActuator atuador3(at3_m1, at3_m2, at3_m3, at3_m4, swAv3, swRec3);

CircularActuatorFreeRTOS mesa(cl_m1, cl_m2, cl_m3, cl_m4, pos1, pos2, pos3);

UltrasonicSensorFreeRTOS ultra(trigPin, echoPin);

ColorSensor sensorDeCor(s0, s1, s2, s3, out);

ConveyorBeltFreeRTOS esteira(belt_m1, belt_m2, belt_m3, belt_m4);

LiquidCrystal lcd(lcd1, lcd2, lcd3, lcd4, lcd5, lcd6);

DisplayInterface displayLcd;


void TaskSensorMonitoring( void *pvParameters );
void TaskUltrasonicSensorMonitoring( void *pvParameters );
void TaskActuatorControl( void *pvParameters );
void TaskConveyorBeltControl( void *pvParameters );
void TaskControleEstacao( void *pvParameters );
void TaskDisplayLCD( void *pvParameters );

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  atuador1.goBackward();
  atuador3.goBackward();

  sensorDeBarreira1.barrierSensorCalibrate();
  sensorDeBarreira2.barrierSensorCalibrate();
  sensorDeBarreira3.barrierSensorCalibrate();
  sensorDeBarreira4.barrierSensorCalibrate();
  sensorDeBarreira5.barrierSensorCalibrate();

  ultra.ultrasonicSensorCalibrate();

  mesa.setSpeed(10);

  esteira.setDirectionToRight();
  esteira.setSpeed(10);

    xTaskCreate(

    TaskSensorMonitoring

    ,  (const portCHAR *)"MonitoramentoDeSensores"   // A name just for humans

    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater

    ,  NULL

    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.

    ,  NULL );

    xTaskCreate(

    TaskUltrasonicSensorMonitoring

    ,  (const portCHAR *)"MonitoramentoDeUltra"   // A name just for humans

    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater

    ,  NULL

    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.

    ,  NULL );

    xTaskCreate(

    TaskActuatorControl

    ,  (const portCHAR *)"ControleAtuadores"   // A name just for humans

    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater

    ,  NULL

    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.

    ,  NULL );
    
    xTaskCreate(

    TaskConveyorBeltControl

    ,  (const portCHAR *)"ControleEsteira"   // A name just for humans

    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater

    ,  NULL

    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.

    ,  NULL );

    xTaskCreate(

    TaskDisplayLCD

    ,  (const portCHAR *)"DisplayLCD"   // A name just for humans

    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater

    ,  NULL

    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.

    ,  NULL );

    xTaskCreate(

    TaskStationControl

    ,  (const portCHAR *)"ControleEstacao"   // A name just for humans

    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater

    ,  NULL

    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.

    ,  NULL );

}

void loop() {
  // put your main code here, to run repeatedly:

}

void TaskSensorMonitoring(void *pvParameters)  // This is a task.
{

  (void) pvParameters;


  for (;;) // A Task shall never return or exit.

  {
    sensorDeBarreira1.readLdrValue();
    sensorDeBarreira2.readLdrValue();
    sensorDeBarreira3.readLdrValue();
    sensorDeBarreira4.readLdrValue();
    sensorDeBarreira5.readLdrValue();

    sensorDeCor.readColors();
  }

}

void TaskUltrasonicSensorMonitoring(void *pvParameters)  // This is a task.
{

  (void) pvParameters;


  for (;;) // A Task shall never return or exit.

  {
    
    ultra.readDistance();
    
  }

}

void TaskActuatorControl(void *pvParameters)  // This is a task.
{

  (void) pvParameters;


  for (;;) // A Task shall never return or exit.

  {
   atuador1.linearDCActuatorControl();
   atuador2.linearDCActuatorControl();
   atuador3.linearStepActuatorControl();
   mesa.circularActuatorControl();
  }

}

void TaskConveyorBeltControl(void *pvParameters)  // This is a task.
{

  (void) pvParameters;
  
  int xLastWakeTime;
  const int xFrequency = 10;

  // Initialise the xLastWakeTime variable with the current time.
  xLastWakeTime = xTaskGetTickCount ();


  for (;;) // A Task shall never return or exit.

  {
    // Wait for the next cycle.
    vTaskDelayUntil( &xLastWakeTime, xFrequency );
    esteira.conveyorBeltControl();
  }

}

void TaskDisplayLCD(void *pvParameters)  // This is a task.
{

  (void) pvParameters;

  int xLastWakeTime;
  const int xFrequency = 1;

  // Initialise the xLastWakeTime variable with the current time.
  xLastWakeTime = xTaskGetTickCount ();


  for (;;) // A Task shall never return or exit.

  {
    // Wait for the next cycle.
    vTaskDelayUntil( &xLastWakeTime, xFrequency );

    displayLcd.setLine1("Estação");
    displayLcd.setLine2("Automatizada");
    

    
    lcd.clear();
    //Posiciona o cursor na coluna 3, linha 0;
    lcd.setCursor(1, 0);
    //Envia o texto entre aspas para o LCD
    lcd.print(displayLcd.getLine1());
    lcd.setCursor(1, 1);
    lcd.print(displayLcd.getLine2());
  }

}

void TaskStationControl(void *pvParameters)  // This is a task.
{

  (void) pvParameters;


  for (;;) // A Task shall never return or exit.

  {
   Serial.println(sensorDeBarreira5.lightBlocked());
  
   if(sensorDeBarreira5.lightBlocked() or temPeca == 1){
   
     atuador1.goForward();
   
     temPeca = 1;

     if(ultra.getHeight() < 0.5 and pecaMedida == 0){
      Serial.println("Sem peca para medir");
      Serial.println(ultra.getHeight());
     }else{

      Serial.println(ultra.getHeight());
     
      if(pecaMedida == 0){
        vTaskDelay( 1000 / portTICK_PERIOD_MS );
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
         vTaskDelay( 5000 / portTICK_PERIOD_MS );
         esteira.turnOff();
         vTaskDelay( 500 / portTICK_PERIOD_MS );
         if(sensorDeCor.isItRed()){
          cor = 1;
         }
         if(sensorDeCor.isItGreen()){
          cor = 2;
         }
         if (sensorDeCor.isItBlue()){
          cor = 3;
         }
         vTaskDelay( 1000 / portTICK_PERIOD_MS );
         esteira.turnOn();   

         if(mesaAcionada == 0){
          if(cor == 1){
            mesa.goToPosition1();
            mesaAcionada = 1;
          }
   
          if(cor == 2){
            mesa.goToPosition2();
            mesaAcionada = 1;
          }

          if(cor == 3){
            mesa.goToPosition3();
            mesaAcionada = 1;
          } 
        }
      }

      
      

      if(sensorDeBarreira2.lightBlocked()){
        if(highOrLow == 0){
          vTaskDelay( 5000 / portTICK_PERIOD_MS );
          esteira.turnOff();
          vTaskDelay( 500 / portTICK_PERIOD_MS );
          atuador3.goForward();
          vTaskDelay( 3000 / portTICK_PERIOD_MS );
          esteira.turnOn();
          atuador3.goBackward();
        }
      }

      if(sensorDeBarreira3.lightBlocked()){
        if(highOrLow == 1){
          vTaskDelay( 6300 / portTICK_PERIOD_MS );
          esteira.turnOff();
          vTaskDelay( 500 / portTICK_PERIOD_MS );
          atuador2.goForward();
          while(atuador2.isItForward() == false){
            Serial.println("aguardando");
          }
          vTaskDelay( 1000 / portTICK_PERIOD_MS );
          atuador2.goBackward();
          temPeca = 0;
          pecaMedida = 0;
          mesaAcionada = 0;
       

         Serial.print("tamanho da peca: ");
         Serial.print(highOrLow);
         Serial.println(" ");

         Serial.print("cor da peca: ");
         Serial.print(cor);
         Serial.println(" ");
         
        }
      }
      


      
       if(sensorDeBarreira4.lightBlocked()){
         vTaskDelay( 5000 / portTICK_PERIOD_MS );
         temPeca = 0;
         pecaMedida = 0;
         mesaAcionada = 0;
         //cor = 0;
         
         Serial.print("tamanho da peca: ");
         Serial.print(highOrLow);
         Serial.println(" ");

         Serial.print("cor da peca: ");
         Serial.print(cor);
         Serial.println(" ");
         
         esteira.turnOff();
         
      }   
      
      
    
    
    }
    
    }else{
      atuador1.goBackward();
    }
  
  }

}
