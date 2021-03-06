#ifndef irSensor__h
    #define irSensor__h
    #define IR_LEFT     2
    #define IR_RIGHT    3

   volatile bool leftDetect = false;
   volatile bool rightDetect = false;

       void leftDetect_ISR(void){
        leftDetect = true;
    }

    void rightDetect_ISR(void){
        rightDetect = true;
    }

    void irSensorInit(void){
        attachInterrupt(IR_LEFT,leftDetect_ISR,FALLING);
        attachInterrupt(IR_RIGHT,rightDetect_ISR,FALLING);
    }

    void testIrSensor(void){
        if(leftDetect){
            Serial.println("left Detected");
            leftDetect =false;
        }
             if(rightDetect){
            Serial.println("Right Detected");
            rightDetect =false;
        }
    }

    void clear_ISR_Verialble(void){
        leftDetect = false;
        rightDetect = false;
    }
#endif
