#ifndef motor_h
  #define motor_h 
  #define leftPin1  4 // arudino out put pin for motor driver 5-11 this pin will drive wheel motor
  #define leftPin2  6
  #define speedPinLeft 5
  #define rightPin1 7
  #define rightPin2 9
  #define speedPinRight 8 


  #define FULL_MOTOR_SPEED_LEFT   255
  #define FULL_MOTOR_SPEED_RIGHT  255
  #define FULL_BASE_SPEED_RIGHT   200
  #define FULL_BASE_SPEED_LEFT    200

  #define WALL_MOTOR_SPEED_LEFT   255
  #define WALL_MOTOR_SPEED_RIGHT  255
  #define WALL_BASE_SPEED_RIGHT   200
  #define WALL_BASE_SPEED_LEFT    200

  #define  halfMotorSpeed  180
  #define  halfBaseSpeed   120

  #define STOP_SPEED  80
  
  int    leftMotorSpeed  = 0;
  int    rightMotorSpeed = 0;

  void motorInit (){
      pinMode(leftPin1, OUTPUT);
      pinMode(leftPin2, OUTPUT);
      pinMode(rightPin1, OUTPUT);
      pinMode(rightPin2, OUTPUT);
      pinMode(speedPinLeft, OUTPUT);
      pinMode(speedPinRight, OUTPUT);
  }

    void speedControl (uint16_t lSpeed , uint16_t rSpeed){
    analogWrite(speedPinLeft, lSpeed);
    analogWrite(speedPinRight, rSpeed);
  }

   void normalSpeed(void){
    analogWrite (speedPinLeft, 255);
    analogWrite (speedPinRight, 255);
  }

  void forward(void){
    digitalWrite (leftPin1, HIGH);
    digitalWrite (leftPin2, LOW);
    digitalWrite (rightPin1, HIGH);
    digitalWrite (rightPin2, LOW);
  }

  void backward(void){
    digitalWrite (leftPin1, LOW);
    digitalWrite (leftPin2, HIGH);
    digitalWrite (rightPin1, LOW);
    digitalWrite (rightPin2, HIGH);
  }

  void turnRight(void){
    digitalWrite (leftPin1, LOW);
    digitalWrite (leftPin2, HIGH);
    digitalWrite (rightPin1, HIGH);
    digitalWrite (rightPin2, LOW);
  }

  void turnLeft(void){
    digitalWrite (leftPin1, HIGH);
    digitalWrite (leftPin2, LOW);
    digitalWrite (rightPin1, LOW);
    digitalWrite (rightPin2, HIGH);
  }

  void Stop (void){
    speedControl(STOP_SPEED,STOP_SPEED);
    digitalWrite (leftPin1, LOW);
    digitalWrite (leftPin2, LOW);
    digitalWrite (rightPin1, LOW);
    digitalWrite (rightPin2, LOW);
  }

  void freeforward (uint16_t time){
    normalSpeed();
    forward();
    delay(time);
    Stop();
  }

  void freeBackward (void){
    normalSpeed();
    backward();
  }

  void FreeRotateLeft(uint16_t time){
    normalSpeed();
    turnLeft();
    delay(time);
    Stop();
  }

  void FreeRotateRight(uint16_t time){
    normalSpeed();
    turnRight();
    delay(time);
    Stop();
  }

  void testMotors(){
      /*speedControl (255 ,100);
      forward();
      delay(1000);
      Stop();
      backward();
      delay(1000);
      Stop();*/

      forward();

      for(uint16_t i = 0; i < 256; i++)
      {
        speedControl (i ,0);
        delay(100);
      }

      for(uint16_t i = 0; i < 256; i++)
      {
        speedControl (0 ,i);
        delay(100);
      }
      
  }
#endif 
