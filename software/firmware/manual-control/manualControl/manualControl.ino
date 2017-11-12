#include "Thread.h"
#include "ThreadController.h"
#include "BarrierSensor.h"
#include <SwitchSensor.h>
#include <LinearDCActuator.h>
#include <ConveyorBelt.h>
#include <Stepper.h>
#include <LinearStepActuator.h>
#include <CircularActuatorV2.h>
#include <LiquidCrystal.h>
#include <DisplayInterface.h>

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

ThreadController cpu;
Thread SensorMonitoring;
Thread ConveyorBeltControl;
Thread CircularActuatorControl;
Thread ActuatorControl; 
Thread DisplayLCD;

BarrierSensor sensorDeBarreira1(ldr1Pin, laser1Pin);
BarrierSensor sensorDeBarreira2(ldr2Pin, laser2Pin);
BarrierSensor sensorDeBarreira3(ldr3Pin, laser3Pin);
BarrierSensor sensorDeBarreira4(ldr4Pin, laser4Pin);
BarrierSensor sensorDeBarreira5(ldr5Pin, laser5Pin);

LinearDCActuator atuador1(at1_m1, at1_m2, swAv1, swRec1);

LinearDCActuator atuador2(at2_m1, at2_m2, swAv2, swRec2);

LinearStepActuator atuador3(at3_m1, at3_m2, at3_m3, at3_m4, swAv3, swRec3);

CircularActuatorV2 mesa(cl_m1, cl_m2, cl_m3, cl_m4, pos1, pos2, pos3);

ConveyorBelt esteira(belt_m1, belt_m2, belt_m3, belt_m4);

LiquidCrystal lcd(lcd1, lcd2, lcd3, lcd4, lcd5, lcd6);

DisplayInterface displayLcd;



void sensorMonitoring(){
    sensorDeBarreira1.readLdrValue();
    sensorDeBarreira2.readLdrValue();
    sensorDeBarreira3.readLdrValue();
    sensorDeBarreira4.readLdrValue();
    sensorDeBarreira5.readLdrValue();
}

void conveyorBeltControl(){
    esteira.conveyorBeltControl();
}

void circularActuatorControl(){
    mesa.circularActuatorV2Control();
}

void actuatorControl(){
    atuador1.linearDCActuatorControl();
    atuador2.linearDCActuatorControl();
    atuador3.linearStepActuatorControl();
}

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.clear();
    //Posiciona o cursor na coluna 3, linha 0;
    lcd.setCursor(1, 0);
    //Envia o texto entre aspas para o LCD
    lcd.print(displayLcd.getLine1());
    lcd.setCursor(1, 1);
    lcd.print(displayLcd.getLine2());
    
    atuador1.goBackward();
    atuador2.goBackward();
    atuador3.goBackward();
  
    sensorDeBarreira1.barrierSensorCalibrate();
    sensorDeBarreira2.barrierSensorCalibrate();
    sensorDeBarreira3.barrierSensorCalibrate();
    sensorDeBarreira4.barrierSensorCalibrate();
    sensorDeBarreira5.barrierSensorCalibrate();
  
    SensorMonitoring.setInterval(1000);
    SensorMonitoring.onRun(sensorMonitoring);

    ConveyorBeltControl.setInterval(0);
    ConveyorBeltControl.onRun(conveyorBeltControl);

    CircularActuatorControl.setInterval(5);
    CircularActuatorControl.onRun(circularActuatorControl);

    ActuatorControl.setInterval(20);
    ActuatorControl.onRun(actuatorControl);

    cpu.add(&SensorMonitoring);
    cpu.add(&ConveyorBeltControl);
    cpu.add(&CircularActuatorControl);
    cpu.add(&ActuatorControl);

    mesa.setSpeed(30);

    displayLcd.setLine1("Estacao");
    displayLcd.setLine2("Automatizada");
    
    esteira.setDirectionToRight();
    esteira.setSpeed(35);
}

void loop() {
    cpu.run();
    
    if (Serial.available())
    {
      int device_action = Serial.parseInt();
  
        if(device_action == 11){
            esteira.turnOn();
        } 
        if(device_action == 12){
            esteira.turnOff();
        }
        
     
        
        if(device_action == 21){
            atuador1.goForward();
        }
        if(device_action == 22){
            atuador1.goBackward();
        }
      
      
        
        if(device_action == 31){
            atuador2.goForward();
        }
        if(device_action == 32){
            atuador2.goBackward();
        }
      
     
        
        if(device_action == 41){
            atuador3.goForward();
        }
        if(device_action == 42){
            atuador3.goBackward();
        }
      
     
        
        if(device_action == 51){
            mesa.goToPosition1();
        }
        if(device_action == 52){
            mesa.goToPosition2();
        }
        if(device_action == 53){
            mesa.goToPosition3();
        }
      
    
    }

}
