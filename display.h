//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "lineFollow.h"



#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif


#ifndef display_h
  #define display_h

  
LiquidCrystal_I2C lcd(0x27,16,2); 
// set the LCD address to 0x27 for a 16 chars and 2 line display
// display all keycodes

void displayKeyCodes(void) {
    lcd.clear();
    lcd.println("Codes 0x");
    lcd.println("-0x"); 
}

void lcdInit()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}

void doSomething(){
 
  
  lcd.print("Hello world...");
  lcd.setCursor(0, 1);
  lcd.print(" i ");
  lcd.printByte(3);
  lcd.print(" arduinos!");
  delay(5000);
  displayKeyCodes();
  
}

void displayTest(void){

        
        lcd.setCursor(0,1);

        for(int i=0;i<50;i++){

            lcd.print(i);
            delay(1000);
        }

        lcd.clear();
    }

void displayMainMenu(void){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("1.Line Follow");
        lcd.setCursor(0,1);
        lcd.print("2.wall Follow");
    delay(2000);
    lcd.clear();
      lcd.setCursor(0,0);
        lcd.print("3.Calibrate");
        lcd.setCursor(0,1);
        lcd.print("4.Change PID Values");
      delay(2000);
    }

void displayLIneFllow(){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("1.Line Fllow");
        lcd.setCursor(0,1);
        lcd.print("2.ChangPid");
        delay(200);
        //display.println("3.Calibrate");
    }
    void displayText(String text){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(text);
        delay(200);
        //display.println("3.Calibrate");
    }

 void printValues (double value) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(value,4);
        delay(400);
    }

 void displayKp (void){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Kp Value");
        lcd.setCursor(0,1);
        lcd.print("Base Val ");
        lcd.print(FULL_SPEED_Kp,4);
        delay(200);
    }

    void displayKd (void){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Kp Value");
        lcd.setCursor(0,1);
        lcd.print("Base Val ");
        lcd.print(FULL_SPEED_Kd,4);
        delay(200);
    }

    void displayChangePID(void){
         lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("1.Kp");
        lcd.setCursor(0,1);
        lcd.print("2.Kd");
        delay(200);
    }

#endif 
