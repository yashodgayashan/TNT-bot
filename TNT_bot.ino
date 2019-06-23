#include "irSensors.h"
#include "keypad.h"
#include "motor.h"
#include "colorsensor.h"
#include "display.h"
#include "QTRSensor.h"
#include "distanceSensor.h"
#include "menu.h"
#include "lineFollow.h"

void setup() {
  irSensorInit();
  indicatorsInit();
  keypadInit();
  motorInit ();
  colorInit();
  lcdInit();
  sensorInit();
  Serial.begin(9600);
  calibrateSensorArray();

}

void loop() {
  fullSpeedLineFollowBlackStrip();
}

void withMenu(void){
    char key = getKey();

 if(key != 'n'){

     if(key == 's' ){
         displayLIneFllow();
         LineFollowMenu();
         displayMainMenu();
        }

        if(key == 'b' ){
            displayText("Tuning");
            calibrateSensorArray();
            displayMainMenu();
        }

        if(key == 'u' ){
           displayText("solving hhhmaze");
            //solveMaze();
            displayMainMenu();
        }

        if(key == 'd' ){
            displayText("solving maze");
            //solveMaze();
            displayMainMenu();
        }
 }
}
