#ifndef indicators_h
  #define indicators_h
#define greenLedPin 28
#define redLedPin 22
#define blueLedPin 30
#define buzzer 45

void indicatorsInit(){
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void redLight(int time){
  digitalWrite(redLedPin, HIGH);
  delay(time);
  digitalWrite(redLedPin, LOW);
  delay(time);
}
void redOn(){
  digitalWrite(redLedPin, HIGH);
}
void redOff(){
  digitalWrite(redLedPin, LOW);
}
void greenLight(int time){
  digitalWrite(greenLedPin, HIGH);
  delay(time);
  digitalWrite(greenLedPin, LOW);
  delay(time);
}
void greenOn(){
  digitalWrite(greenLedPin, HIGH);
}
void greenOff(){
  digitalWrite(greenLedPin, LOW);
}
void blueLight(int time){
  digitalWrite(blueLedPin, HIGH);
  delay(time);
  digitalWrite(blueLedPin, LOW);
  delay(time);
}
void blueOn(){
  digitalWrite(blueLedPin, HIGH);
}
void blueOff(){
  digitalWrite(blueLedPin, LOW);
}
void buzzerBlink(int time){
  digitalWrite(buzzer, HIGH);
  delay(time);
  digitalWrite(buzzer, LOW);
  delay(time);
}
void buzzerOn(){
  digitalWrite(buzzer, HIGH);
}
void buzzerOff(){
  digitalWrite(buzzer, LOW);
}
#endif 
