#include <Arduino_FreeRTOS.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(37, 36, 35, 34, 33, 32);

void TaskLCD( void *pvParameters );

void setup() {
  lcd.begin(16, 2);

  xTaskCreate(

    TaskLCD

    ,  (const portCHAR *)"LCD"   // A name just for humans

    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater

    ,  NULL

    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.

    ,  NULL );

}

void loop() {}


void TaskLCD(void *pvParameters)  // This is a task.
{

  (void) pvParameters;


  for (;;) // A Task shall never return or exit.

  {
    
    lcd.clear();
    //Posiciona o cursor na coluna 3, linha 0;
    lcd.setCursor(2, 0);
    //Envia o texto entre aspas para o LCD
    lcd.print("mas q bosta");
    lcd.setCursor(1, 1);
    lcd.print("cu");
    
  }

}
